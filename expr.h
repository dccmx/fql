#ifndef EXPR_H_
#define EXPR_H_

#include "variant.h"
#include "table.h"

class Expr {
 public:
  virtual Variant *Evaluate(Row *row) = 0;
  virtual void Print(int indent = 0) = 0;
};

class BinaryExpr : public Expr{
 public:
  BinaryExpr(int op = 0, Expr *left = NULL, Expr *right = NULL);
  ~BinaryExpr() { delete left_; delete right_;}

  Variant *Evaluate(Row *row);
  void Print(int indent = 0);

 private:
  int op_;
  Expr *left_;
  Expr *right_;
};

class UnaryExpr : public Expr {
 public:
  UnaryExpr(int op = 0, Expr *right = NULL)
      : op_(op), right_(right) {}

  ~UnaryExpr() { delete right_; }

  Variant *Evaluate(Row *row);

  void Print(int indent = 0) {
    for (int i = 0; i < indent; i++) printf(" ");
    printf("(%d,\n", op_);
    right_->Print(indent + 2);
  }

 private:
  int op_;
  Expr *right_;
};

class Value : public Expr {
 public:
  Value(Variant *value = NULL, int id = 0, bool is_attr = false)
      : value_(value), id_(id), is_attr_(is_attr) {}

  ~Value() { delete value_; }

  void set_is_attr(bool is_attr = true) { is_attr_ = is_attr; }
  int id() { return id_; }

  Variant *Evaluate(Row *row) {
    if (is_attr_) return row->get(value_->c_str());
    else return value_->Clone();
  }

  void Print(int indent = 0) {
    for (int i = 0; i < indent; i++) printf(" ");
    printf("%s[%s]", value_->c_str(), (is_attr_? "ATTR" : "VAL"));
  }

 private:
  Variant *value_;
  int id_;
  bool is_attr_;
};

#endif // EXPR_H_

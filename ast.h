#ifndef AST_H_
#define AST_H_

#include <stdlib.h>
#include <string>
#include <vector>

#include "table.h"

using std::vector;
using std::string;

class Statement;
class Select;
class Expr;
struct OrderList;
struct Limit;

struct Limit {
  Limit() : start(0), limit(-1) {}
  uint32_t start;
  int limit;
};

struct OrderList {
  vector<string> attrs;
  vector<int> dirs;
};

struct ParserContext {
  ParserContext() : stmt(NULL), error(false) {}
  Statement *stmt;
  bool error;
};

class Statement {
 public:
  virtual ~Statement() {}

 public:
  virtual Table *Execute() = 0;
};

class Select : public Statement {
 public:
  Select() : distinct_(false), attrs_(NULL), folders_(NULL), orders_(NULL) {}
  ~Select();

 public:
  Table *Execute();

 public:
  void set_attrs(vector<string> *attrs) { attrs_ = attrs; }
  void set_folders(vector<string> *folders) { folders_ = folders; }
  void set_distinct(bool distinct) { distinct_ = distinct; }
  void set_where(Expr *where) { where_ = where; }
  void set_orders(OrderList *orders) { orders_ = orders; }
  void set_limit(Limit *limit) { limit_ = limit; }

 private:
  Table *SelectDir(const string& dir);

 private:
  bool distinct_;
  vector<string> *attrs_;
  vector<string> *folders_;
  Expr *where_;
  OrderList *orders_;
  Limit *limit_;
};

class Expr {
 public:
  Expr(int op = 0, Expr *left = NULL, Expr *right = NULL, Variant *value = NULL, bool is_attr = false)
      : op_(op), left_(left), right_(right), value_(value), is_attr_(is_attr) {}
  ~Expr() { delete left_; delete right_; delete value_; }

  Variant *Evaluate(Row *row);
  void Print();
  void set_value(Variant *value) { value_ = value; }
  void set_is_attr(bool is_attr = true) { is_attr_ = is_attr; }

 private:
  int op_;
  Expr *left_;
  Expr *right_;
  Variant *value_;
  bool is_attr_;
};

#endif // AST_H_

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
  Expr() : op_(0), left_(NULL), right_(NULL), value_(NULL) {}
  ~Expr() { delete left_; delete right_; delete value_; }

  Variant *Evaluate();
  void set_value(Variant *value) { value_ = value; }

 private:
  int op_;
  Expr *left_;
  Expr *right_;
  Variant *value_;
};

#endif // AST_H_

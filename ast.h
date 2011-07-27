#ifndef AST_H_
#define AST_H_

#include <stdlib.h>
#include <string>
#include <vector>

#include "table.h"

using std::vector;
using std::string;

class Stmt;
class Select;

class Stmt {
 public:
  Table *Execute();
  void set_select(Select *select) { select_ = select; }

 private:
  Select *select_;
};

class Select {
 public:
  Select() : distinct_(false) {}

 public:
  Table *Execute();
  void set_attrs(vector<string> *attrs) { attrs_ = attrs; }
  void set_folders(vector<string> *folders) { folders_ = folders; }
  void set_distinct(bool distinct) { distinct_ = distinct; }

 private:
  bool distinct_;
  vector<string> *attrs_;
  vector<string> *folders_;
};

#endif // AST_H_

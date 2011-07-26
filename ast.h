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
 private:
  Select *select;
};

class Select {
 public:
  Table *Execute();

 private:
  vector<string> attrs;
  vector<string> folders;
};

#endif // AST_H_

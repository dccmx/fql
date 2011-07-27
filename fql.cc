#include <iostream>

#include "lexer.h"
#include "ast.h"
#include "sys.h"

int main(int argc, char **argv) {
  //Stmt *stmt = Parse((char *)"select time, \"name\" from `.`, folder2 where size > 100 and name=`dccmx\".pdf`");
  Stmt *stmt = Parse((char *)"select time, \"name\" from `.`, folder2 ");
  Table *res;
  if (stmt) {
    res = stmt->Execute();
    res->Print();
  }

  if (argc > 1 ) stmt = Parse(argv[1]);
  if (stmt) {
    res = stmt->Execute();
    res->Print();
  }
}

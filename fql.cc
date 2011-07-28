#include <iostream>

#include "lexer.h"
#include "ast.h"
#include "sys.h"

int main(int argc, char **argv) {
  //Stmt *stmt = Parse((char *)"select time, \"name\" from `.`, folder2 where size > 100 and name=`dccmx\".pdf`");
  Statement *stmt = Parse((char *)"select size, \"name\" from `.`, folder2 ");
  Table *res;
  if (stmt) {
    res = stmt->Execute();
    res->Print();
    delete res;
  }

  delete stmt;

  stmt = NULL;

  if (argc > 1 ) stmt = Parse(argv[1]);
  if (stmt) {
    res = stmt->Execute();
    res->Print();
  }
}

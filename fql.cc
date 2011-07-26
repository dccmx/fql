#include <iostream>

#include "lexer.h"
#include "ast.h"

int main(int argc, char **argv) {
  Stmt *stmt = Parse((char *)"select time,name from folder1, folder2 where size > 100 and name=`dccmx\".pdf`");
  Table *res = stmt->Execute();
  if (argc > 1 ) Parse(argv[1]);
}

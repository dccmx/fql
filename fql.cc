#include <iostream>

#include "lexer.h"
#include "ast.h"
#include "sys.h"

int main(int argc, char **argv) {
  if (argc > 1 ) {
    ParserContext parse = Parse(argv[1]);
    if (!parse.error) {
      Table *res = parse.stmt->Execute();
      res->Print();
      delete res;
      delete parse.stmt;
    }
  }
}

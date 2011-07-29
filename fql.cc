#include <iostream>

#include "lexer.h"
#include "ast.h"
#include "sys.h"
#include "variant.h"

void ExecuteSQL(char *sql) {
  ParserContext parse = Parse(sql);
  if (!parse.error) {
    Table *res = parse.stmt->Execute();
    res->Print();
    delete res;
    delete parse.stmt;
  }
}

int main(int argc, char **argv) {
  if (argc > 1 ) {
    ExecuteSQL(argv[1]);
  } else {
    char sql[1024];
    while (true) {
      printf("> ");
      fgets(sql, 1024, stdin);
      if (feof(stdin)) break;
      ExecuteSQL(sql);
    }
  }
}

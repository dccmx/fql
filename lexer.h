#ifndef LEXER_H_
#define LEXER_H_

#include "ast.h"

struct Token {
  Token(int tid, char *s, char *e)
      : id(tid), ps(s), pe(e) {}

  int id;
  char *ps, *pe;

  int value;
};

Stmt *Parse(char *str);

#endif // LEXER_H_

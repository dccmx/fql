#ifndef LEXER_H_
#define LEXER_H_

#include "ast.h"

struct Token {
  Token(int tid, char *s, char *e);

  int id;
  char str[1024];

  int value;
};

Statement *Parse(char *str);

#endif // LEXER_H_

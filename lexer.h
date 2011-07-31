#ifndef LEXER_H_
#define LEXER_H_

#include "ast.h"
#include "variant.h"

struct Token {
  Token(int tid, char *s, char *e);
  Variant *ToVariant();

  int id;
  char str[1024];

  int value;
  double fvalue;
};

ParserContext Parse(char *str);

#endif // LEXER_H_

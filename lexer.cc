#include <stdlib.h>
#include <string.h>

#include "lexer.h"
#include "parser.h"

#define INTEGER() { \
  tk = new Token(TK_INTEGER, ts, te); \
  Parse(parser, TK_INTEGER, tk, &context); \
}
#define FLOAT() {\
  tk = new Token(TK_FLOAT, ts, te); \
  Parse(parser, TK_FLOAT, tk, &context); \
}

#define KEYWORD(ID) { \
  tk = new Token(ID, ts, te); \
  Parse(parser, ID, tk, &context); \
}

#define SYMBOL(ID) { \
  tk = new Token(ID, ts, te); \
  Parse(parser, ID, tk, &context); \
}

#define STRING() { \
  tk = new Token(TK_STRING, ts + 1, te - 1); \
  Parse(parser, TK_STRING, tk, &context); \
}

#define ID() { \
  tk = new Token(TK_ID, ts, te); \
  Parse(parser, TK_ID, tk, &context); \
}

#include "parser.c"
#include "lexer.c"

Token::Token(int tid, char *s, char *e) {
  id = tid;
  strncpy(str, s, e - s);
  str[e - s] = '\0';
  switch (id) {
    case TK_INTEGER:
      value = atoi(str);
      break;
    case TK_FLOAT:
      fvalue = atof(str);
      break;
    case TK_ASC:
    case TK_DESC:
      value = id;
      break;
    default:
      break;
  }
}

Variant *Token::ToVariant() {
  Variant *ret = NULL;
  switch (id) {
    case TK_INTEGER:
      ret = new Int32(value);
      break;
    case TK_FLOAT:
      ret = new Float(fvalue);
      break;
    default:
      ret = new String(str);
      break;
  }
  return ret;
}

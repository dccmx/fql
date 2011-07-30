#include <string.h>

#include "lexer.h"
#include "parser.h"

Token::Token(int tid, char *s, char *e) {
  id = tid;
  strncpy(str, s, e - s);
  str[e - s] = '\0';
  switch (tid) {
    case TK_INTEGER:
      value = atoi(str);
      break;
    case TK_FLOAT:
      value = atoi(str);
      break;
    case TK_ASC:
    case TK_DESC:
      value = tid;
      break;
    default:
      break;
  }
}

Variant *Token::ToVariant() {
  return NULL;
}

#include <string.h>

#include "lexer.h"
#include "parser.h"

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

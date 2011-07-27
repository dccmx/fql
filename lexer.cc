#include <string.h>

#include "lexer.h"

Token::Token(int tid, char *s, char *e) {
  id = tid;
  strncpy(str, s, e - s);
  str[e - s] = '\0';
}

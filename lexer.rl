#include <string.h>
#include <stdlib.h>

#include "lexer.h"
#include "parser.h"
#include "parser.cc"

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

%%{
  machine lexer;

  main := |*
    ('-'|'+')? [1-9][0-9]* { INTEGER() };
    ('-'|'+')? [1-9][0-9]* '.' [0-9]+{ FLOAT() };

    /select/i { KEYWORD(TK_SELECT) };
    /quit/i { KEYWORD(TK_QUIT) };
    /where/i { KEYWORD(TK_WHERE) };
    /or/i { KEYWORD(TK_OR) };
    /and/i { KEYWORD(TK_AND) };
    /not/i { KEYWORD(TK_NOT) };
    /from/i { KEYWORD(TK_FROM) };
    /order/i { KEYWORD(TK_ORDER) };
    /by/i { KEYWORD(TK_BY) };
    /asc/i { KEYWORD(TK_ASC) };
    /desc/i { KEYWORD(TK_DESC) };
    /limit/i { KEYWORD(TK_LIMIT) };

    '+' { SYMBOL(TK_PLUS) };
    '-' { SYMBOL(TK_MINUS) };
    '/' { SYMBOL(TK_DIV) };
    '%' { SYMBOL(TK_MOD) };
    '(' { SYMBOL(TK_LP) };
    ')' { SYMBOL(TK_RP) };
    '>' { SYMBOL(TK_GT); };
    '<' { SYMBOL(TK_LT); };
    '=' { SYMBOL(TK_EQ); };
    '>=' { SYMBOL(TK_GE); };
    '<=' { SYMBOL(TK_LE); };
    '!=' { SYMBOL(TK_NE); };
    '*' { SYMBOL(TK_STAR) };
    ',' { SYMBOL(TK_COMMA) };

    dliteralChar = [^`"\\] | ( '\\' any );
    '"' (dliteralChar | '`')* '"' { STRING() };
    '`' (dliteralChar | '"')* '`' { STRING() };

    (print - space - [,>=*])+ { ID() };

    space;
  *|;
}%%

%% write data;

ParserContext Parse(char *str) {
  int cs, act;
  char *ts, *te;
  char *p = str;
  char *pe = p + strlen(p);
  char *eof = pe;

  Token *tk = NULL;

  ParserContext context;

  void *parser = ParseAlloc(malloc);

  %% write init;
  %% write exec;

  if (cs < %%{ write first_final; }%%) {
    printf("error: %s\n", p);
  }

  Parse(parser, 0, 0, &context);

  ParseFree(parser, free);

  return context;
}


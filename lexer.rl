#include <string.h>
#include <stdlib.h>

#include "lexer.h"
#include "parser.h"
#include "parser.c"

%%{
  machine lexer;
  main := |*
    [1-9][0-9]* {
      Parse(parser, TK_INTEGER, 0);
    };
    /select/i { 
      Parse(parser, TK_SELECT, NULL);
    };
    /from/i { 
      Parse(parser, TK_FROM, NULL);
    };
    /order/i { 
      Parse(parser, TK_ORDER, NULL);
    };
    /by/i { 
      Parse(parser, TK_BY, NULL);
    };
    /limit/i { 
      Parse(parser, TK_LIMIT, NULL);
    };
    /name/i { 
      Parse(parser, TK_LIMIT, NULL);
    };
    /time/i { 
      Parse(parser, TK_LIMIT, NULL);
    };
    ',' { 
      Parse(parser, TK_COMMA, NULL);
    };
    ' ';
  *|;
}%%

%% write data;

AST *Parse(char *str) {
  int cs, act;
  char *ts, *te;
  char *p = str;
  char *pe = p + strlen(p);
  char *eof = pe;

  void *parser = ParseAlloc(malloc);

  %% write init;
  %% write exec;

  Parse(parser, TK_INTEGER, NULL);
  Parse(parser, 0, 0);

  ParseFree(parser, free);

  return NULL;
}


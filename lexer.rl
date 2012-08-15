%%{
  machine lexer;

  main := |*
    ('-'|'+')? [1-9][0-9]* { INTEGER() };
    ('-'|'+')? [0-9]* '.' [0-9]+{ FLOAT() };

    /select/i { KEYWORD(TK_SELECT) };
    /quit/i { KEYWORD(TK_QUIT) };
    /where/i { KEYWORD(TK_WHERE) };
    /or/i { KEYWORD(TK_OR) };
    /and/i { KEYWORD(TK_AND) };
    /not/i { KEYWORD(TK_NOT) };
    /like/i { KEYWORD(TK_LIKE) };
    /from/i { KEYWORD(TK_FROM) };
    /-r/i { KEYWORD(TK_RECURSIVE) };
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
    "'" (dliteralChar | '"')* "'" { STRING() };

    (print - space - [,<>=\*])+ { ID() };

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
  context.stmt = NULL;

  void *parser = ParseAlloc(malloc);

  %% write init;
  %% write exec;

  if (cs < %%{ write first_final; }%%) {
    printf("unrecognized: %s\n", p);
    context.error = true;
  } else {
    Parse(parser, 0, 0, &context);
  }

  ParseFree(parser, free);

  return context;
}

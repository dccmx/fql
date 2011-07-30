/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#line 1 "parser.y"

#include <assert.h>
#line 11 "parser.c"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    ParseTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is ParseTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    ParseARG_SDECL     A static variable declaration for the %extra_argument
**    ParseARG_PDECL     A parameter declaration for the %extra_argument
**    ParseARG_STORE     Code to store %extra_argument into yypParser
**    ParseARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 45
#define YYACTIONTYPE unsigned char
#define ParseTOKENTYPE Token*
typedef union {
  int yyinit;
  ParseTOKENTYPE yy0;
  Select* yy3;
  vector<string>* yy15;
  OrderList* yy27;
  Limit* yy62;
  Expr* yy66;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseARG_SDECL ParserContext *ctx;
#define ParseARG_PDECL ,ParserContext *ctx
#define ParseARG_FETCH ParserContext *ctx = yypParser->ctx
#define ParseARG_STORE yypParser->ctx = ctx
#define YYNSTATE 49
#define YYNRULE 31
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* The yyzerominor constant is used to initialize instances of
** YYMINORTYPE objects to zero. */
static const YYMINORTYPE yyzerominor = { 0 };

/* Define the yytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define yytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the yytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef yytestcase
# define yytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
static const YYACTIONTYPE yy_action[] = {
 /*     0 */     5,    4,    6,    7,    7,    7,    7,    7,    7,   26,
 /*    10 */    15,   41,    5,    4,    6,    7,    7,    7,    7,    7,
 /*    20 */     7,   37,   37,    4,    6,    7,    7,    7,    7,    7,
 /*    30 */     7,    6,    7,    7,    7,    7,    7,    7,    7,    7,
 /*    40 */     7,    7,    7,    7,   35,   35,   35,   35,   35,   35,
 /*    50 */    45,   16,   32,   35,   35,   35,   25,   14,   40,   11,
 /*    60 */     3,   36,   47,   21,   20,   81,   23,   22,   24,   42,
 /*    70 */    39,   39,   31,   39,   39,   39,   39,   43,   13,   46,
 /*    80 */    48,   38,    1,    9,   17,    2,   44,   18,   19,   30,
 /*    90 */    33,   49,   27,   50,   28,   29,   34,    8,   10,   82,
 /*   100 */    12,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */    10,   11,   12,   13,   14,   15,   16,   17,   18,    1,
 /*    10 */     2,   21,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    20 */    18,   23,   24,   11,   12,   13,   14,   15,   16,   17,
 /*    30 */    18,   12,   13,   14,   15,   16,   17,   18,   13,   14,
 /*    40 */    15,   16,   17,   18,    4,    5,    6,    4,    5,    6,
 /*    50 */     7,   31,   32,    4,    5,    6,   30,   42,   42,   19,
 /*    60 */    20,   43,   42,   35,   35,   39,   35,   35,   35,   35,
 /*    70 */    42,   42,   36,   42,   42,   42,   42,   33,   42,   42,
 /*    80 */     3,   43,   40,    9,   34,   22,   42,   41,   37,   25,
 /*    90 */    38,    0,   27,    0,   28,    8,   28,   26,    8,   44,
 /*   100 */     8,
};
#define YY_SHIFT_USE_DFLT (-11)
#define YY_SHIFT_MAX 32
static const signed char yy_shift_ofst[] = {
 /*     0 */     8,   43,   40,   40,   40,   40,   40,   40,   49,   49,
 /*    10 */    49,   49,   49,   -2,   -2,   77,   74,   63,   64,   65,
 /*    20 */   -10,    2,   12,   19,   25,   91,   93,   66,   87,   68,
 /*    30 */    71,   90,   92,
};
#define YY_REDUCE_USE_DFLT (-1)
#define YY_REDUCE_MAX 19
static const signed char yy_reduce_ofst[] = {
 /*     0 */    26,   20,   28,   29,   31,   32,   33,   34,   36,   44,
 /*    10 */    15,   16,   37,   18,   38,   42,   50,   46,   51,   52,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */    80,   80,   80,   80,   80,   80,   80,   80,   80,   80,
 /*    10 */    80,   80,   80,   73,   73,   53,   59,   69,   75,   77,
 /*    20 */    80,   70,   66,   65,   67,   80,   80,   80,   78,   80,
 /*    30 */    80,   76,   56,   51,   79,   54,   71,   74,   72,   62,
 /*    40 */    63,   64,   68,   60,   61,   55,   58,   57,   52,
};
#define YY_SZ_ACTTAB (int)(sizeof(yy_action)/sizeof(yy_action[0]))

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  YYACTIONTYPE stateno;  /* The state-number */
  YYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  YYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
#ifdef YYTRACKMAXSTACKDEPTH
  int yyidxMax;                 /* Maximum value of yyidx */
#endif
  int yyerrcnt;                 /* Shifts left before out of the error */
  ParseARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry *yystack;        /* The parser's stack */
#else
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
#endif
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void ParseTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
  "$",             "QUIT",          "SELECT",        "DISTINCT",    
  "ID",            "STRING",        "FLOAT",         "STAR",        
  "COMMA",         "FROM",          "OR",            "AND",         
  "LIKE",          "GT",            "LT",            "EQ",          
  "GE",            "LE",            "NE",            "NOT",         
  "LP",            "RP",            "WHERE",         "ASC",         
  "DESC",          "ORDER",         "BY",            "LIMIT",       
  "INTEGER",       "error",         "select",        "cols",        
  "attrlist",      "folderlist",    "from",          "expr",        
  "orderlist",     "orderby",       "limit",         "stmt",        
  "distinct",      "where",         "name",          "order",       
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "stmt ::= select",
 /*   1 */ "stmt ::= QUIT",
 /*   2 */ "select ::= SELECT distinct cols from where orderby limit",
 /*   3 */ "distinct ::= DISTINCT",
 /*   4 */ "distinct ::=",
 /*   5 */ "name ::= ID|STRING|FLOAT",
 /*   6 */ "cols ::= STAR",
 /*   7 */ "cols ::= attrlist",
 /*   8 */ "attrlist ::= name",
 /*   9 */ "attrlist ::= attrlist COMMA name",
 /*  10 */ "from ::=",
 /*  11 */ "from ::= FROM folderlist",
 /*  12 */ "folderlist ::= name",
 /*  13 */ "expr ::= name",
 /*  14 */ "expr ::= NOT name",
 /*  15 */ "expr ::= LP expr RP",
 /*  16 */ "expr ::= expr AND expr",
 /*  17 */ "expr ::= expr OR expr",
 /*  18 */ "expr ::= expr LIKE expr",
 /*  19 */ "expr ::= expr GT|LT|EQ|GE|LE|NE expr",
 /*  20 */ "where ::=",
 /*  21 */ "where ::= WHERE expr",
 /*  22 */ "orderlist ::= name order",
 /*  23 */ "orderlist ::= orderlist COMMA name order",
 /*  24 */ "order ::=",
 /*  25 */ "order ::= ASC|DESC",
 /*  26 */ "orderby ::=",
 /*  27 */ "orderby ::= ORDER BY orderlist",
 /*  28 */ "limit ::=",
 /*  29 */ "limit ::= LIMIT INTEGER",
 /*  30 */ "limit ::= LIMIT INTEGER COMMA INTEGER",
};
#endif /* NDEBUG */


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.
*/
static void yyGrowStack(yyParser *p){
  int newSize;
  yyStackEntry *pNew;

  newSize = p->yystksz*2 + 100;
  pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
  if( pNew ){
    p->yystack = pNew;
    p->yystksz = newSize;
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
              yyTracePrompt, p->yystksz);
    }
#endif
  }
}
#endif

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to Parse and ParseFree.
*/
void *ParseAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
#ifdef YYTRACKMAXSTACKDEPTH
    pParser->yyidxMax = 0;
#endif
#if YYSTACKDEPTH<=0
    pParser->yystack = NULL;
    pParser->yystksz = 0;
    yyGrowStack(pParser);
#endif
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(
  yyParser *yypParser,    /* The parser */
  YYCODETYPE yymajor,     /* Type code for object to destroy */
  YYMINORTYPE *yypminor   /* The object to be destroyed */
){
  ParseARG_FETCH;
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
      /* TERMINAL Destructor */
    case 1: /* QUIT */
    case 2: /* SELECT */
    case 3: /* DISTINCT */
    case 4: /* ID */
    case 5: /* STRING */
    case 6: /* FLOAT */
    case 7: /* STAR */
    case 8: /* COMMA */
    case 9: /* FROM */
    case 10: /* OR */
    case 11: /* AND */
    case 12: /* LIKE */
    case 13: /* GT */
    case 14: /* LT */
    case 15: /* EQ */
    case 16: /* GE */
    case 17: /* LE */
    case 18: /* NE */
    case 19: /* NOT */
    case 20: /* LP */
    case 21: /* RP */
    case 22: /* WHERE */
    case 23: /* ASC */
    case 24: /* DESC */
    case 25: /* ORDER */
    case 26: /* BY */
    case 27: /* LIMIT */
    case 28: /* INTEGER */
{
#line 4 "parser.y"
 delete (yypminor->yy0); 
#line 449 "parser.c"
}
      break;
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor(pParser, yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from ParseAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void ParseFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
  free(pParser->yystack);
#endif
  (*freeProc)((void*)pParser);
}

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef YYTRACKMAXSTACKDEPTH
int ParseStackPeak(void *p){
  yyParser *pParser = (yyParser*)p;
  return pParser->yyidxMax;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  if( stateno>YY_SHIFT_MAX || (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
    if( iLookAhead>0 ){
#ifdef YYFALLBACK
      YYCODETYPE iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        return yy_find_shift_action(pParser, iFallback);
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if( j>=0 && j<YY_SZ_ACTTAB && yy_lookahead[j]==YYWILDCARD ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
    }
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_MAX ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_MAX );
#endif
  i = yy_reduce_ofst[stateno];
  assert( i!=YY_REDUCE_USE_DFLT );
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_SZ_ACTTAB );
  assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void yyStackOverflow(yyParser *yypParser, YYMINORTYPE *yypMinor){
   ParseARG_FETCH;
   yypParser->yyidx--;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
#line 13 "parser.y"

  printf("Stack overflowed\n");
#line 625 "parser.c"
   ParseARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer to the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
#ifdef YYTRACKMAXSTACKDEPTH
  if( yypParser->yyidx>yypParser->yyidxMax ){
    yypParser->yyidxMax = yypParser->yyidx;
  }
#endif
#if YYSTACKDEPTH>0 
  if( yypParser->yyidx>=YYSTACKDEPTH ){
    yyStackOverflow(yypParser, yypMinor);
    return;
  }
#else
  if( yypParser->yyidx>=yypParser->yystksz ){
    yyGrowStack(yypParser);
    if( yypParser->yyidx>=yypParser->yystksz ){
      yyStackOverflow(yypParser, yypMinor);
      return;
    }
  }
#endif
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = (YYACTIONTYPE)yyNewState;
  yytos->major = (YYCODETYPE)yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 39, 1 },
  { 39, 1 },
  { 30, 7 },
  { 40, 1 },
  { 40, 0 },
  { 42, 1 },
  { 31, 1 },
  { 31, 1 },
  { 32, 1 },
  { 32, 3 },
  { 34, 0 },
  { 34, 2 },
  { 33, 1 },
  { 35, 1 },
  { 35, 2 },
  { 35, 3 },
  { 35, 3 },
  { 35, 3 },
  { 35, 3 },
  { 35, 3 },
  { 41, 0 },
  { 41, 2 },
  { 36, 2 },
  { 36, 4 },
  { 43, 0 },
  { 43, 1 },
  { 37, 0 },
  { 37, 3 },
  { 38, 0 },
  { 38, 2 },
  { 38, 4 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  ParseARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.  
  **
  ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
  ** without this code, their parser segfaults.  I'm not sure what there
  ** parser is doing to make this happen.  This is the second bug report
  ** from wireshark this week.  Clearly they are stressing Lemon in ways
  ** that it has not been previously stressed...  (SQLite ticket #2172)
  */
  /*memset(&yygotominor, 0, sizeof(yygotominor));*/
  yygotominor = yyzerominor;


  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0: /* stmt ::= select */
#line 32 "parser.y"
{
  ctx->stmt = yymsp[0].minor.yy3;
}
#line 772 "parser.c"
        break;
      case 1: /* stmt ::= QUIT */
#line 36 "parser.y"
{
  exit(0);
  yy_destructor(yypParser,1,&yymsp[0].minor);
}
#line 780 "parser.c"
        break;
      case 2: /* select ::= SELECT distinct cols from where orderby limit */
#line 40 "parser.y"
{
  yygotominor.yy3 = new Select();
  if (yymsp[-5].minor.yy0 != NULL) {
    yygotominor.yy3->set_distinct(true);
    delete yymsp[-5].minor.yy0;
  }
  yygotominor.yy3->set_attrs(yymsp[-4].minor.yy15);
  yygotominor.yy3->set_folders(yymsp[-3].minor.yy15);
  yygotominor.yy3->set_orders(yymsp[-1].minor.yy27);
  yygotominor.yy3->set_limit(yymsp[0].minor.yy62);
  yy_destructor(yypParser,2,&yymsp[-6].minor);
}
#line 796 "parser.c"
        break;
      case 3: /* distinct ::= DISTINCT */
#line 52 "parser.y"
{
  yy_destructor(yypParser,3,&yymsp[0].minor);
}
#line 803 "parser.c"
        break;
      case 5: /* name ::= ID|STRING|FLOAT */
      case 25: /* order ::= ASC|DESC */ yytestcase(yyruleno==25);
#line 55 "parser.y"
{
  yygotominor.yy0 = yymsp[0].minor.yy0;
}
#line 811 "parser.c"
        break;
      case 6: /* cols ::= STAR */
#line 59 "parser.y"
{
  yygotominor.yy15 = new vector<string>();
  yygotominor.yy15->push_back(string("perms"));
  yygotominor.yy15->push_back(string("uname"));
  yygotominor.yy15->push_back(string("gname"));
  yygotominor.yy15->push_back(string("size"));
  yygotominor.yy15->push_back(string("time"));
  yygotominor.yy15->push_back(string("name"));
  delete yymsp[0].minor.yy0;
}
#line 825 "parser.c"
        break;
      case 7: /* cols ::= attrlist */
#line 70 "parser.y"
{
  yygotominor.yy15 = yymsp[0].minor.yy15;
}
#line 832 "parser.c"
        break;
      case 8: /* attrlist ::= name */
      case 12: /* folderlist ::= name */ yytestcase(yyruleno==12);
#line 74 "parser.y"
{
  yygotominor.yy15 = new vector<string>();
  yygotominor.yy15->push_back(string(yymsp[0].minor.yy0->str));
  delete yymsp[0].minor.yy0;
}
#line 842 "parser.c"
        break;
      case 9: /* attrlist ::= attrlist COMMA name */
#line 80 "parser.y"
{
  yymsp[-2].minor.yy15->push_back(string(yymsp[0].minor.yy0->str));
  delete yymsp[0].minor.yy0;
  yygotominor.yy15 = yymsp[-2].minor.yy15;
  yy_destructor(yypParser,8,&yymsp[-1].minor);
}
#line 852 "parser.c"
        break;
      case 11: /* from ::= FROM folderlist */
#line 87 "parser.y"
{
  yygotominor.yy15 = yymsp[0].minor.yy15;
  yy_destructor(yypParser,9,&yymsp[-1].minor);
}
#line 860 "parser.c"
        break;
      case 13: /* expr ::= name */
#line 109 "parser.y"
{
  yygotominor.yy66 = new Expr();
  yygotominor.yy66->set_value(yymsp[0].minor.yy0->ToVariant());
}
#line 868 "parser.c"
        break;
      case 14: /* expr ::= NOT name */
#line 113 "parser.y"
{
  yy_destructor(yypParser,19,&yymsp[-1].minor);
}
#line 875 "parser.c"
        break;
      case 15: /* expr ::= LP expr RP */
#line 114 "parser.y"
{
  yy_destructor(yypParser,20,&yymsp[-2].minor);
  yy_destructor(yypParser,21,&yymsp[0].minor);
}
#line 883 "parser.c"
        break;
      case 16: /* expr ::= expr AND expr */
#line 115 "parser.y"
{
  yy_destructor(yypParser,11,&yymsp[-1].minor);
}
#line 890 "parser.c"
        break;
      case 17: /* expr ::= expr OR expr */
#line 116 "parser.y"
{
  yy_destructor(yypParser,10,&yymsp[-1].minor);
}
#line 897 "parser.c"
        break;
      case 18: /* expr ::= expr LIKE expr */
#line 117 "parser.y"
{
  yy_destructor(yypParser,12,&yymsp[-1].minor);
}
#line 904 "parser.c"
        break;
      case 21: /* where ::= WHERE expr */
#line 121 "parser.y"
{
  yy_destructor(yypParser,22,&yymsp[-1].minor);
}
#line 911 "parser.c"
        break;
      case 22: /* orderlist ::= name order */
#line 123 "parser.y"
{
  yygotominor.yy27 = new OrderList();
  yygotominor.yy27->attrs.push_back(string(yymsp[-1].minor.yy0->str));
  if (yymsp[0].minor.yy0) yygotominor.yy27->dirs.push_back(yymsp[0].minor.yy0->value);
  else yygotominor.yy27->dirs.push_back(TK_ASC);
}
#line 921 "parser.c"
        break;
      case 23: /* orderlist ::= orderlist COMMA name order */
#line 129 "parser.y"
{
  yymsp[-3].minor.yy27->attrs.push_back(string(yymsp[-1].minor.yy0->str));
  if (yymsp[0].minor.yy0) yymsp[-3].minor.yy27->dirs.push_back(yymsp[0].minor.yy0->value);
  else yymsp[-3].minor.yy27->dirs.push_back(TK_ASC);
  yygotominor.yy27 = yymsp[-3].minor.yy27;
  yy_destructor(yypParser,8,&yymsp[-2].minor);
}
#line 932 "parser.c"
        break;
      case 27: /* orderby ::= ORDER BY orderlist */
#line 142 "parser.y"
{
  yygotominor.yy27 = yymsp[0].minor.yy27;
  yy_destructor(yypParser,25,&yymsp[-2].minor);
  yy_destructor(yypParser,26,&yymsp[-1].minor);
}
#line 941 "parser.c"
        break;
      case 28: /* limit ::= */
#line 146 "parser.y"
{
  yygotominor.yy62 = new Limit();
}
#line 948 "parser.c"
        break;
      case 29: /* limit ::= LIMIT INTEGER */
#line 149 "parser.y"
{
  yygotominor.yy62 = new Limit();
  yygotominor.yy62->limit = yymsp[0].minor.yy0->value;
  delete yymsp[0].minor.yy0;
  yy_destructor(yypParser,27,&yymsp[-1].minor);
}
#line 958 "parser.c"
        break;
      case 30: /* limit ::= LIMIT INTEGER COMMA INTEGER */
#line 154 "parser.y"
{
  yygotominor.yy62 = new Limit();
  yygotominor.yy62->start = yymsp[-2].minor.yy0->value;
  yygotominor.yy62->limit = yymsp[0].minor.yy0->value;
  delete yymsp[-2].minor.yy0;
  delete yymsp[0].minor.yy0;
  yy_destructor(yypParser,27,&yymsp[-3].minor);
  yy_destructor(yypParser,8,&yymsp[-1].minor);
}
#line 971 "parser.c"
        break;
      default:
      /* (4) distinct ::= */ yytestcase(yyruleno==4);
      /* (10) from ::= */ yytestcase(yyruleno==10);
      /* (19) expr ::= expr GT|LT|EQ|GE|LE|NE expr */ yytestcase(yyruleno==19);
      /* (20) where ::= */ yytestcase(yyruleno==20);
      /* (24) order ::= */ yytestcase(yyruleno==24);
      /* (26) orderby ::= */ yytestcase(yyruleno==26);
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
  if( yyact < YYNSTATE ){
#ifdef NDEBUG
    /* If we are not debugging and the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = (YYACTIONTYPE)yyact;
      yymsp->major = (YYCODETYPE)yygoto;
      yymsp->minor = yygotominor;
    }else
#endif
    {
      yy_shift(yypParser,yyact,yygoto,&yygotominor);
    }
  }else{
    assert( yyact == YYNSTATE + YYNRULE + 1 );
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
#ifndef YYNOERRORRECOVERY
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}
#endif /* YYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  ParseARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 7 "parser.y"

  if (TOKEN) printf("syntax error near: %s\n", TOKEN->str);
  else printf("syntax error\n");
  ctx->error = true;
#line 1044 "parser.c"
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
#line 6 "parser.y"
#line 1064 "parser.c"
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "ParseAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void Parse(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  ParseTOKENTYPE yyminor       /* The value for the token */
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
    if( yypParser->yystksz <=0 ){
      /*memset(&yyminorunion, 0, sizeof(yyminorunion));*/
      yyminorunion = yyzerominor;
      yyStackOverflow(yypParser, &yyminorunion);
      return;
    }
#endif
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  ParseARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
    if( yyact<YYNSTATE ){
      assert( !yyendofinput );  /* Impossible to shift the $ token */
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      yymajor = YYNOCODE;
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else{
      assert( yyact == YY_ERROR_ACTION );
#ifdef YYERRORSYMBOL
      int yymx;
#endif
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_reduce_action(
                        yypParser->yystack[yypParser->yyidx].stateno,
                        YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
      /* If the YYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      yy_syntax_error(yypParser,yymajor,yyminorunion);
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      yymajor = YYNOCODE;
      
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}

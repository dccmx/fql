
#line 1 "lexer.rl"
#include <string.h>
#include <stdlib.h>

#include "lexer.h"
#include "parser.h"
#include "parser.c"

#define INTEGER() { tk = new Token(TK_INTEGER, ts, te); \
  tk->value = atoi(tk->ps); \
  Parse(parser, TK_INTEGER, tk); \
  printf("int: %d\n", tk->value); \
}

#define KEYWORD(ID) { Parse(parser, ID, NULL); \
  printf("keyword: ");\
  for (char *p = ts; p < te; p++) printf("%c", *p);\
  printf("\n");\
}

#define SYMBOL(ID) { Parse(parser, ID, NULL); \
  printf("symbol: ");\
  for (char *p = ts; p < te; p++) printf("%c", *p);\
  printf("\n");\
}

#define STRING() { \
  printf("string: ");\
  for (char *p = ts + 1; p < te - 1; p++) printf("%c", *p);\
  printf("\n");\
}

#define ID() { \
  printf("id: ");\
  for (char *p = ts; p < te; p++) printf("%c", *p);\
  printf("\n");\
}

#line 68 "lexer.rl"



#line 45 "lexer.cc"
static const char _lexer_actions[] = {
	0, 1, 0, 1, 1, 1, 14, 1, 
	15, 1, 16, 1, 17, 1, 18, 1, 
	19, 1, 20, 1, 21, 1, 22, 1, 
	23, 1, 24, 2, 2, 3, 2, 2, 
	4, 2, 2, 5, 2, 2, 6, 2, 
	2, 7, 2, 2, 8, 2, 2, 9, 
	2, 2, 10, 2, 2, 11, 2, 2, 
	12, 2, 2, 13
};

static const short _lexer_key_offsets[] = {
	0, 0, 2, 2, 4, 4, 36, 42, 
	48, 58, 66, 74, 82, 90, 98, 106, 
	114, 122, 130, 138, 146, 154, 162, 170, 
	178, 186, 194, 202, 210, 218, 226, 234, 
	242, 250, 258, 266, 274
};

static const char _lexer_trans_keys[] = {
	34, 92, 92, 96, 32, 34, 42, 44, 
	48, 61, 62, 65, 66, 68, 70, 76, 
	78, 79, 83, 87, 96, 97, 98, 100, 
	102, 108, 110, 111, 115, 119, 49, 57, 
	67, 90, 99, 122, 48, 57, 65, 90, 
	97, 122, 48, 57, 65, 90, 97, 122, 
	78, 83, 110, 115, 48, 57, 65, 90, 
	97, 122, 68, 100, 48, 57, 65, 90, 
	97, 122, 67, 99, 48, 57, 65, 90, 
	97, 122, 89, 121, 48, 57, 65, 90, 
	97, 122, 69, 101, 48, 57, 65, 90, 
	97, 122, 83, 115, 48, 57, 65, 90, 
	97, 122, 67, 99, 48, 57, 65, 90, 
	97, 122, 82, 114, 48, 57, 65, 90, 
	97, 122, 79, 111, 48, 57, 65, 90, 
	97, 122, 77, 109, 48, 57, 65, 90, 
	97, 122, 73, 105, 48, 57, 65, 90, 
	97, 122, 77, 109, 48, 57, 65, 90, 
	97, 122, 73, 105, 48, 57, 65, 90, 
	97, 122, 84, 116, 48, 57, 65, 90, 
	97, 122, 79, 111, 48, 57, 65, 90, 
	97, 122, 84, 116, 48, 57, 65, 90, 
	97, 122, 82, 114, 48, 57, 65, 90, 
	97, 122, 68, 100, 48, 57, 65, 90, 
	97, 122, 69, 101, 48, 57, 65, 90, 
	97, 122, 82, 114, 48, 57, 65, 90, 
	97, 122, 69, 101, 48, 57, 65, 90, 
	97, 122, 76, 108, 48, 57, 65, 90, 
	97, 122, 69, 101, 48, 57, 65, 90, 
	97, 122, 67, 99, 48, 57, 65, 90, 
	97, 122, 84, 116, 48, 57, 65, 90, 
	97, 122, 72, 104, 48, 57, 65, 90, 
	97, 122, 69, 101, 48, 57, 65, 90, 
	97, 122, 82, 114, 48, 57, 65, 90, 
	97, 122, 69, 101, 48, 57, 65, 90, 
	97, 122, 0
};

static const char _lexer_single_lengths[] = {
	0, 2, 0, 2, 0, 26, 0, 0, 
	4, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2
};

static const char _lexer_range_lengths[] = {
	0, 0, 0, 0, 0, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3
};

static const unsigned char _lexer_index_offsets[] = {
	0, 0, 3, 4, 7, 8, 38, 42, 
	46, 54, 60, 66, 72, 78, 84, 90, 
	96, 102, 108, 114, 120, 126, 132, 138, 
	144, 150, 156, 162, 168, 174, 180, 186, 
	192, 198, 204, 210, 216
};

static const char _lexer_indicies[] = {
	1, 2, 0, 0, 4, 5, 3, 3, 
	6, 0, 8, 9, 10, 12, 13, 14, 
	15, 16, 17, 18, 19, 20, 21, 22, 
	3, 14, 15, 16, 17, 18, 19, 20, 
	21, 22, 11, 10, 10, 7, 10, 10, 
	10, 23, 11, 10, 10, 24, 26, 27, 
	26, 27, 10, 10, 10, 25, 28, 28, 
	10, 10, 10, 25, 29, 29, 10, 10, 
	10, 25, 30, 30, 10, 10, 10, 25, 
	31, 31, 10, 10, 10, 25, 32, 32, 
	10, 10, 10, 25, 33, 33, 10, 10, 
	10, 25, 34, 34, 10, 10, 10, 25, 
	35, 35, 10, 10, 10, 25, 36, 36, 
	10, 10, 10, 25, 37, 37, 10, 10, 
	10, 25, 38, 38, 10, 10, 10, 25, 
	39, 39, 10, 10, 10, 25, 40, 40, 
	10, 10, 10, 25, 41, 41, 10, 10, 
	10, 25, 42, 42, 10, 10, 10, 25, 
	43, 43, 10, 10, 10, 25, 45, 45, 
	10, 10, 10, 44, 46, 46, 10, 10, 
	10, 25, 47, 47, 10, 10, 10, 25, 
	48, 48, 10, 10, 10, 25, 49, 49, 
	10, 10, 10, 25, 50, 50, 10, 10, 
	10, 25, 51, 51, 10, 10, 10, 25, 
	52, 52, 10, 10, 10, 25, 53, 53, 
	10, 10, 10, 25, 54, 54, 10, 10, 
	10, 25, 55, 55, 10, 10, 10, 25, 
	56, 56, 10, 10, 10, 25, 0
};

static const char _lexer_trans_targs[] = {
	1, 5, 2, 3, 4, 5, 5, 0, 
	5, 5, 6, 7, 5, 5, 8, 11, 
	12, 15, 18, 22, 24, 28, 33, 5, 
	5, 5, 9, 10, 6, 6, 6, 13, 
	14, 6, 16, 17, 6, 19, 20, 21, 
	6, 23, 6, 25, 5, 26, 27, 6, 
	29, 30, 31, 32, 6, 34, 35, 36, 
	6
};

static const char _lexer_trans_actions[] = {
	0, 13, 0, 0, 0, 15, 17, 0, 
	11, 5, 57, 0, 9, 7, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 25, 
	19, 23, 0, 0, 33, 48, 45, 0, 
	0, 51, 0, 0, 39, 0, 0, 0, 
	54, 0, 36, 0, 21, 0, 0, 42, 
	0, 0, 0, 0, 27, 0, 0, 0, 
	30
};

static const char _lexer_to_state_actions[] = {
	0, 0, 0, 0, 0, 1, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0
};

static const char _lexer_from_state_actions[] = {
	0, 0, 0, 0, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0
};

static const unsigned char _lexer_eof_trans[] = {
	0, 0, 0, 0, 0, 0, 24, 25, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 45, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26
};

static const int lexer_start = 5;
static const int lexer_first_final = 5;
static const int lexer_error = 0;

static const int lexer_en_main = 5;


#line 71 "lexer.rl"

Stmt *Parse(char *str) {
  int cs, act;
  char *ts, *te;
  char *p = str;
  char *pe = p + strlen(p);
  char *eof = pe;

  Token *tk = NULL;

  void *parser = ParseAlloc(malloc);

  
#line 226 "lexer.cc"
	{
	cs = lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 84 "lexer.rl"
  
#line 236 "lexer.cc"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_acts = _lexer_actions + _lexer_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 1:
#line 1 "NONE"
	{ts = p;}
	break;
#line 257 "lexer.cc"
		}
	}

	_keys = _lexer_trans_keys + _lexer_key_offsets[cs];
	_trans = _lexer_index_offsets[cs];

	_klen = _lexer_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _lexer_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _lexer_indicies[_trans];
_eof_trans:
	cs = _lexer_trans_targs[_trans];

	if ( _lexer_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _lexer_actions + _lexer_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 2:
#line 1 "NONE"
	{te = p+1;}
	break;
	case 3:
#line 43 "lexer.rl"
	{act = 2;}
	break;
	case 4:
#line 44 "lexer.rl"
	{act = 3;}
	break;
	case 5:
#line 46 "lexer.rl"
	{act = 5;}
	break;
	case 6:
#line 47 "lexer.rl"
	{act = 6;}
	break;
	case 7:
#line 48 "lexer.rl"
	{act = 7;}
	break;
	case 8:
#line 49 "lexer.rl"
	{act = 8;}
	break;
	case 9:
#line 50 "lexer.rl"
	{act = 9;}
	break;
	case 10:
#line 51 "lexer.rl"
	{act = 10;}
	break;
	case 11:
#line 52 "lexer.rl"
	{act = 11;}
	break;
	case 12:
#line 53 "lexer.rl"
	{act = 12;}
	break;
	case 13:
#line 64 "lexer.rl"
	{act = 19;}
	break;
	case 14:
#line 55 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_COMMA) }}
	break;
	case 15:
#line 56 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_GT); }}
	break;
	case 16:
#line 57 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_EQ); }}
	break;
	case 17:
#line 58 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_STAR) }}
	break;
	case 18:
#line 61 "lexer.rl"
	{te = p+1;{ STRING() }}
	break;
	case 19:
#line 62 "lexer.rl"
	{te = p+1;{ STRING() }}
	break;
	case 20:
#line 66 "lexer.rl"
	{te = p+1;}
	break;
	case 21:
#line 41 "lexer.rl"
	{te = p;p--;{ INTEGER() }}
	break;
	case 22:
#line 45 "lexer.rl"
	{te = p;p--;{ KEYWORD(TK_OR) }}
	break;
	case 23:
#line 64 "lexer.rl"
	{te = p;p--;{ ID() }}
	break;
	case 24:
#line 1 "NONE"
	{	switch( act ) {
	case 2:
	{{p = ((te))-1;} KEYWORD(TK_SELECT) }
	break;
	case 3:
	{{p = ((te))-1;} KEYWORD(TK_WHERE) }
	break;
	case 5:
	{{p = ((te))-1;} KEYWORD(TK_AND) }
	break;
	case 6:
	{{p = ((te))-1;} KEYWORD(TK_NOT) }
	break;
	case 7:
	{{p = ((te))-1;} KEYWORD(TK_FROM) }
	break;
	case 8:
	{{p = ((te))-1;} KEYWORD(TK_ORDER) }
	break;
	case 9:
	{{p = ((te))-1;} KEYWORD(TK_BY) }
	break;
	case 10:
	{{p = ((te))-1;} KEYWORD(TK_ASC) }
	break;
	case 11:
	{{p = ((te))-1;} KEYWORD(TK_DESC) }
	break;
	case 12:
	{{p = ((te))-1;} KEYWORD(TK_LIMIT) }
	break;
	case 19:
	{{p = ((te))-1;} ID() }
	break;
	}
	}
	break;
#line 450 "lexer.cc"
		}
	}

_again:
	_acts = _lexer_actions + _lexer_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 0:
#line 1 "NONE"
	{ts = 0;}
	break;
#line 463 "lexer.cc"
		}
	}

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _lexer_eof_trans[cs] > 0 ) {
		_trans = _lexer_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	_out: {}
	}

#line 85 "lexer.rl"

  if (cs < 
#line 486 "lexer.cc"
5
#line 86 "lexer.rl"
) {
    printf("error: %s\n", p);
  }

  Parse(parser, TK_INTEGER, NULL);
  Parse(parser, 0, 0);

  ParseFree(parser, free);

  return NULL;
}


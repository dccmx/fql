
#line 1 "lexer.rl"
#include <string.h>
#include <stdlib.h>

#include "lexer.h"
#include "parser.h"
#include "parser.c"

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


#line 70 "lexer.rl"



#line 45 "lexer-rl.cc"
static const char _lexer_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	18, 1, 19, 1, 20, 1, 21, 1, 
	22, 1, 23, 1, 24, 1, 25, 1, 
	26, 1, 27, 1, 28, 1, 29, 2, 
	2, 3, 2, 2, 4, 2, 2, 5, 
	2, 2, 6, 2, 2, 7, 2, 2, 
	8, 2, 2, 9, 2, 2, 10, 2, 
	2, 11, 2, 2, 12, 2, 2, 13, 
	2, 2, 14, 2, 2, 15, 2, 2, 
	16, 2, 2, 17
};

static const short _lexer_key_offsets[] = {
	0, 0, 2, 2, 4, 4, 41, 48, 
	57, 64, 75, 87, 98, 109, 118, 127, 
	136, 145, 154, 163, 172, 181, 190, 199, 
	208, 217, 226, 235, 244, 253, 262, 271, 
	280, 289, 298, 307, 316, 325, 334, 343, 
	352, 361, 370, 379, 388, 397
};

static const char _lexer_trans_keys[] = {
	34, 92, 92, 96, 32, 34, 42, 43, 
	44, 45, 61, 62, 65, 66, 68, 70, 
	76, 78, 79, 81, 83, 87, 96, 97, 
	98, 100, 102, 108, 110, 111, 113, 115, 
	119, 9, 13, 33, 48, 49, 57, 58, 
	126, 43, 33, 41, 45, 60, 63, 126, 
	34, 43, 92, 33, 41, 45, 60, 63, 
	126, 43, 33, 41, 45, 60, 63, 126, 
	43, 33, 41, 45, 48, 49, 57, 58, 
	60, 63, 126, 43, 46, 33, 41, 45, 
	47, 48, 57, 58, 60, 63, 126, 43, 
	33, 41, 45, 47, 48, 57, 58, 60, 
	63, 126, 43, 78, 83, 110, 115, 33, 
	41, 45, 60, 63, 126, 43, 68, 100, 
	33, 41, 45, 60, 63, 126, 43, 67, 
	99, 33, 41, 45, 60, 63, 126, 43, 
	89, 121, 33, 41, 45, 60, 63, 126, 
	43, 69, 101, 33, 41, 45, 60, 63, 
	126, 43, 83, 115, 33, 41, 45, 60, 
	63, 126, 43, 67, 99, 33, 41, 45, 
	60, 63, 126, 43, 82, 114, 33, 41, 
	45, 60, 63, 126, 43, 79, 111, 33, 
	41, 45, 60, 63, 126, 43, 77, 109, 
	33, 41, 45, 60, 63, 126, 43, 73, 
	105, 33, 41, 45, 60, 63, 126, 43, 
	77, 109, 33, 41, 45, 60, 63, 126, 
	43, 73, 105, 33, 41, 45, 60, 63, 
	126, 43, 84, 116, 33, 41, 45, 60, 
	63, 126, 43, 79, 111, 33, 41, 45, 
	60, 63, 126, 43, 84, 116, 33, 41, 
	45, 60, 63, 126, 43, 82, 114, 33, 
	41, 45, 60, 63, 126, 43, 68, 100, 
	33, 41, 45, 60, 63, 126, 43, 69, 
	101, 33, 41, 45, 60, 63, 126, 43, 
	82, 114, 33, 41, 45, 60, 63, 126, 
	43, 85, 117, 33, 41, 45, 60, 63, 
	126, 43, 73, 105, 33, 41, 45, 60, 
	63, 126, 43, 84, 116, 33, 41, 45, 
	60, 63, 126, 43, 69, 101, 33, 41, 
	45, 60, 63, 126, 43, 76, 108, 33, 
	41, 45, 60, 63, 126, 43, 69, 101, 
	33, 41, 45, 60, 63, 126, 43, 67, 
	99, 33, 41, 45, 60, 63, 126, 43, 
	84, 116, 33, 41, 45, 60, 63, 126, 
	43, 72, 104, 33, 41, 45, 60, 63, 
	126, 43, 69, 101, 33, 41, 45, 60, 
	63, 126, 43, 82, 114, 33, 41, 45, 
	60, 63, 126, 43, 69, 101, 33, 41, 
	45, 60, 63, 126, 43, 92, 96, 33, 
	41, 45, 60, 63, 126, 43, 33, 41, 
	45, 60, 63, 126, 0
};

static const char _lexer_single_lengths[] = {
	0, 2, 0, 2, 0, 29, 1, 3, 
	1, 1, 2, 1, 5, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 1
};

static const char _lexer_range_lengths[] = {
	0, 0, 0, 0, 0, 4, 3, 3, 
	3, 5, 5, 5, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3
};

static const short _lexer_index_offsets[] = {
	0, 0, 3, 4, 7, 8, 42, 47, 
	54, 59, 66, 74, 81, 90, 97, 104, 
	111, 118, 125, 132, 139, 146, 153, 160, 
	167, 174, 181, 188, 195, 202, 209, 216, 
	223, 230, 237, 244, 251, 258, 265, 272, 
	279, 286, 293, 300, 307, 314
};

static const char _lexer_indicies[] = {
	2, 3, 1, 1, 5, 6, 4, 4, 
	7, 10, 11, 12, 13, 12, 15, 16, 
	17, 18, 19, 20, 21, 22, 23, 24, 
	25, 26, 27, 17, 18, 19, 20, 21, 
	22, 23, 24, 25, 26, 7, 9, 14, 
	9, 8, 9, 9, 9, 9, 28, 30, 
	10, 31, 10, 10, 10, 1, 10, 10, 
	10, 10, 1, 9, 9, 9, 14, 9, 
	9, 29, 9, 33, 9, 9, 14, 9, 
	9, 32, 9, 9, 9, 34, 9, 9, 
	28, 9, 35, 36, 35, 36, 9, 9, 
	9, 29, 9, 37, 37, 9, 9, 9, 
	29, 9, 38, 38, 9, 9, 9, 29, 
	9, 39, 39, 9, 9, 9, 29, 9, 
	40, 40, 9, 9, 9, 29, 9, 41, 
	41, 9, 9, 9, 29, 9, 42, 42, 
	9, 9, 9, 29, 9, 43, 43, 9, 
	9, 9, 29, 9, 44, 44, 9, 9, 
	9, 29, 9, 45, 45, 9, 9, 9, 
	29, 9, 46, 46, 9, 9, 9, 29, 
	9, 47, 47, 9, 9, 9, 29, 9, 
	48, 48, 9, 9, 9, 29, 9, 49, 
	49, 9, 9, 9, 29, 9, 50, 50, 
	9, 9, 9, 29, 9, 51, 51, 9, 
	9, 9, 29, 9, 52, 52, 9, 9, 
	9, 29, 9, 54, 54, 9, 9, 9, 
	53, 9, 55, 55, 9, 9, 9, 29, 
	9, 56, 56, 9, 9, 9, 29, 9, 
	57, 57, 9, 9, 9, 29, 9, 58, 
	58, 9, 9, 9, 29, 9, 59, 59, 
	9, 9, 9, 29, 9, 60, 60, 9, 
	9, 9, 29, 9, 61, 61, 9, 9, 
	9, 29, 9, 62, 62, 9, 9, 9, 
	29, 9, 63, 63, 9, 9, 9, 29, 
	9, 64, 64, 9, 9, 9, 29, 9, 
	65, 65, 9, 9, 9, 29, 9, 66, 
	66, 9, 9, 9, 29, 9, 67, 67, 
	9, 9, 9, 29, 9, 68, 68, 9, 
	9, 9, 29, 27, 69, 70, 27, 27, 
	27, 4, 27, 27, 27, 27, 4, 0
};

static const char _lexer_trans_targs[] = {
	5, 1, 5, 2, 3, 4, 5, 5, 
	0, 6, 7, 5, 9, 5, 10, 5, 
	5, 12, 15, 16, 19, 22, 26, 28, 
	32, 35, 40, 44, 5, 5, 6, 8, 
	5, 11, 11, 13, 14, 6, 6, 6, 
	17, 18, 6, 20, 21, 6, 23, 24, 
	25, 6, 27, 6, 29, 5, 30, 31, 
	6, 33, 34, 6, 36, 37, 38, 39, 
	6, 41, 42, 43, 6, 45, 6
};

static const char _lexer_trans_actions[] = {
	27, 0, 15, 0, 0, 0, 17, 19, 
	0, 73, 5, 13, 0, 7, 0, 11, 
	9, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 5, 29, 25, 67, 5, 
	21, 73, 31, 0, 0, 43, 58, 55, 
	0, 0, 61, 0, 0, 49, 0, 0, 
	0, 64, 0, 46, 0, 23, 0, 0, 
	52, 0, 0, 37, 0, 0, 0, 0, 
	34, 0, 0, 0, 40, 5, 70
};

static const char _lexer_to_state_actions[] = {
	0, 0, 0, 0, 0, 1, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0
};

static const char _lexer_from_state_actions[] = {
	0, 0, 0, 0, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0
};

static const short _lexer_eof_trans[] = {
	0, 1, 1, 1, 1, 0, 29, 30, 
	30, 30, 33, 29, 30, 30, 30, 30, 
	30, 30, 30, 30, 30, 30, 30, 30, 
	30, 30, 30, 30, 30, 54, 30, 30, 
	30, 30, 30, 30, 30, 30, 30, 30, 
	30, 30, 30, 30, 30, 30
};

static const int lexer_start = 5;
static const int lexer_first_final = 5;
static const int lexer_error = 0;

static const int lexer_en_main = 5;


#line 73 "lexer.rl"

ParserContext Parse(char *str) {
  int cs, act;
  char *ts, *te;
  char *p = str;
  char *pe = p + strlen(p);
  char *eof = pe;

  Token *tk = NULL;

  ParserContext context;

  void *parser = ParseAlloc(malloc);

  
#line 266 "lexer-rl.cc"
	{
	cs = lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 88 "lexer.rl"
  
#line 276 "lexer-rl.cc"
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
#line 297 "lexer-rl.cc"
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
#line 42 "lexer.rl"
	{act = 2;}
	break;
	case 4:
#line 44 "lexer.rl"
	{act = 3;}
	break;
	case 5:
#line 45 "lexer.rl"
	{act = 4;}
	break;
	case 6:
#line 46 "lexer.rl"
	{act = 5;}
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
#line 54 "lexer.rl"
	{act = 13;}
	break;
	case 14:
#line 55 "lexer.rl"
	{act = 14;}
	break;
	case 15:
#line 63 "lexer.rl"
	{act = 19;}
	break;
	case 16:
#line 64 "lexer.rl"
	{act = 20;}
	break;
	case 17:
#line 66 "lexer.rl"
	{act = 21;}
	break;
	case 18:
#line 57 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_COMMA) }}
	break;
	case 19:
#line 58 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_GT); }}
	break;
	case 20:
#line 59 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_EQ); }}
	break;
	case 21:
#line 60 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_STAR) }}
	break;
	case 22:
#line 63 "lexer.rl"
	{te = p+1;{ STRING() }}
	break;
	case 23:
#line 64 "lexer.rl"
	{te = p+1;{ STRING() }}
	break;
	case 24:
#line 68 "lexer.rl"
	{te = p+1;}
	break;
	case 25:
#line 41 "lexer.rl"
	{te = p;p--;{ INTEGER() }}
	break;
	case 26:
#line 47 "lexer.rl"
	{te = p;p--;{ KEYWORD(TK_OR) }}
	break;
	case 27:
#line 66 "lexer.rl"
	{te = p;p--;{ ID() }}
	break;
	case 28:
#line 66 "lexer.rl"
	{{p = ((te))-1;}{ ID() }}
	break;
	case 29:
#line 1 "NONE"
	{	switch( act ) {
	case 2:
	{{p = ((te))-1;} FLOAT() }
	break;
	case 3:
	{{p = ((te))-1;} KEYWORD(TK_SELECT) }
	break;
	case 4:
	{{p = ((te))-1;} KEYWORD(TK_QUIT) }
	break;
	case 5:
	{{p = ((te))-1;} KEYWORD(TK_WHERE) }
	break;
	case 7:
	{{p = ((te))-1;} KEYWORD(TK_AND) }
	break;
	case 8:
	{{p = ((te))-1;} KEYWORD(TK_NOT) }
	break;
	case 9:
	{{p = ((te))-1;} KEYWORD(TK_FROM) }
	break;
	case 10:
	{{p = ((te))-1;} KEYWORD(TK_ORDER) }
	break;
	case 11:
	{{p = ((te))-1;} KEYWORD(TK_BY) }
	break;
	case 12:
	{{p = ((te))-1;} KEYWORD(TK_ASC) }
	break;
	case 13:
	{{p = ((te))-1;} KEYWORD(TK_DESC) }
	break;
	case 14:
	{{p = ((te))-1;} KEYWORD(TK_LIMIT) }
	break;
	case 19:
	{{p = ((te))-1;} STRING() }
	break;
	case 20:
	{{p = ((te))-1;} STRING() }
	break;
	case 21:
	{{p = ((te))-1;} ID() }
	break;
	}
	}
	break;
#line 522 "lexer-rl.cc"
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
#line 535 "lexer-rl.cc"
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

#line 89 "lexer.rl"

  if (cs < 
#line 558 "lexer-rl.cc"
5
#line 90 "lexer.rl"
) {
    printf("error: %s\n", p);
  }

  Parse(parser, 0, 0, &context);

  ParseFree(parser, free);

  return context;
}



#line 1 "lexer.rl"
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


#line 80 "lexer.rl"



#line 45 "lexer-rl.cc"
static const char _lexer_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	24, 1, 25, 1, 26, 1, 27, 1, 
	28, 1, 29, 1, 30, 1, 31, 1, 
	32, 1, 33, 1, 34, 1, 35, 1, 
	36, 1, 37, 1, 38, 1, 39, 2, 
	2, 3, 2, 2, 4, 2, 2, 5, 
	2, 2, 6, 2, 2, 7, 2, 2, 
	8, 2, 2, 9, 2, 2, 10, 2, 
	2, 11, 2, 2, 12, 2, 2, 13, 
	2, 2, 14, 2, 2, 15, 2, 2, 
	16, 2, 2, 17, 2, 2, 18, 2, 
	2, 19, 2, 2, 20, 2, 2, 21, 
	2, 2, 22, 2, 2, 23
};

static const short _lexer_key_offsets[] = {
	0, 0, 2, 2, 4, 4, 47, 55, 
	62, 71, 78, 89, 101, 112, 120, 121, 
	132, 141, 150, 159, 168, 177, 186, 195, 
	204, 213, 222, 231, 240, 249, 258, 267, 
	276, 285, 294, 303, 312, 321, 330, 339, 
	348, 357, 366, 375, 384, 393, 402, 411, 
	420
};

static const char _lexer_trans_keys[] = {
	34, 92, 92, 96, 32, 33, 34, 37, 
	40, 41, 42, 43, 44, 45, 47, 60, 
	61, 62, 65, 66, 68, 70, 76, 78, 
	79, 81, 83, 87, 96, 97, 98, 100, 
	102, 108, 110, 111, 113, 115, 119, 9, 
	13, 35, 48, 49, 57, 58, 126, 43, 
	61, 33, 41, 45, 60, 63, 126, 43, 
	33, 41, 45, 60, 63, 126, 34, 43, 
	92, 33, 41, 45, 60, 63, 126, 43, 
	33, 41, 45, 60, 63, 126, 43, 33, 
	41, 45, 48, 49, 57, 58, 60, 63, 
	126, 43, 46, 33, 41, 45, 47, 48, 
	57, 58, 60, 63, 126, 43, 33, 41, 
	45, 47, 48, 57, 58, 60, 63, 126, 
	43, 61, 33, 41, 45, 60, 63, 126, 
	61, 43, 78, 83, 110, 115, 33, 41, 
	45, 60, 63, 126, 43, 68, 100, 33, 
	41, 45, 60, 63, 126, 43, 67, 99, 
	33, 41, 45, 60, 63, 126, 43, 89, 
	121, 33, 41, 45, 60, 63, 126, 43, 
	69, 101, 33, 41, 45, 60, 63, 126, 
	43, 83, 115, 33, 41, 45, 60, 63, 
	126, 43, 67, 99, 33, 41, 45, 60, 
	63, 126, 43, 82, 114, 33, 41, 45, 
	60, 63, 126, 43, 79, 111, 33, 41, 
	45, 60, 63, 126, 43, 77, 109, 33, 
	41, 45, 60, 63, 126, 43, 73, 105, 
	33, 41, 45, 60, 63, 126, 43, 77, 
	109, 33, 41, 45, 60, 63, 126, 43, 
	73, 105, 33, 41, 45, 60, 63, 126, 
	43, 84, 116, 33, 41, 45, 60, 63, 
	126, 43, 79, 111, 33, 41, 45, 60, 
	63, 126, 43, 84, 116, 33, 41, 45, 
	60, 63, 126, 43, 82, 114, 33, 41, 
	45, 60, 63, 126, 43, 68, 100, 33, 
	41, 45, 60, 63, 126, 43, 69, 101, 
	33, 41, 45, 60, 63, 126, 43, 82, 
	114, 33, 41, 45, 60, 63, 126, 43, 
	85, 117, 33, 41, 45, 60, 63, 126, 
	43, 73, 105, 33, 41, 45, 60, 63, 
	126, 43, 84, 116, 33, 41, 45, 60, 
	63, 126, 43, 69, 101, 33, 41, 45, 
	60, 63, 126, 43, 76, 108, 33, 41, 
	45, 60, 63, 126, 43, 69, 101, 33, 
	41, 45, 60, 63, 126, 43, 67, 99, 
	33, 41, 45, 60, 63, 126, 43, 84, 
	116, 33, 41, 45, 60, 63, 126, 43, 
	72, 104, 33, 41, 45, 60, 63, 126, 
	43, 69, 101, 33, 41, 45, 60, 63, 
	126, 43, 82, 114, 33, 41, 45, 60, 
	63, 126, 43, 69, 101, 33, 41, 45, 
	60, 63, 126, 43, 92, 96, 33, 41, 
	45, 60, 63, 126, 43, 33, 41, 45, 
	60, 63, 126, 0
};

static const char _lexer_single_lengths[] = {
	0, 2, 0, 2, 0, 35, 2, 1, 
	3, 1, 1, 2, 1, 2, 1, 5, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	1
};

static const char _lexer_range_lengths[] = {
	0, 0, 0, 0, 0, 4, 3, 3, 
	3, 3, 5, 5, 5, 3, 0, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3
};

static const short _lexer_index_offsets[] = {
	0, 0, 3, 4, 7, 8, 48, 54, 
	59, 66, 71, 78, 86, 93, 99, 101, 
	110, 117, 124, 131, 138, 145, 152, 159, 
	166, 173, 180, 187, 194, 201, 208, 215, 
	222, 229, 236, 243, 250, 257, 264, 271, 
	278, 285, 292, 299, 306, 313, 320, 327, 
	334
};

static const char _lexer_indicies[] = {
	2, 3, 1, 1, 5, 6, 4, 4, 
	7, 9, 10, 12, 13, 14, 15, 16, 
	17, 18, 19, 21, 22, 23, 24, 25, 
	26, 27, 28, 29, 30, 31, 32, 33, 
	34, 24, 25, 26, 27, 28, 29, 30, 
	31, 32, 33, 7, 11, 20, 11, 8, 
	11, 36, 11, 11, 11, 35, 11, 11, 
	11, 11, 37, 38, 10, 39, 10, 10, 
	10, 1, 10, 10, 10, 10, 1, 11, 
	11, 11, 20, 11, 11, 37, 11, 41, 
	11, 11, 20, 11, 11, 40, 11, 11, 
	11, 42, 11, 11, 37, 11, 44, 11, 
	11, 11, 43, 46, 45, 11, 47, 48, 
	47, 48, 11, 11, 11, 35, 11, 49, 
	49, 11, 11, 11, 35, 11, 50, 50, 
	11, 11, 11, 35, 11, 51, 51, 11, 
	11, 11, 35, 11, 52, 52, 11, 11, 
	11, 35, 11, 53, 53, 11, 11, 11, 
	35, 11, 54, 54, 11, 11, 11, 35, 
	11, 55, 55, 11, 11, 11, 35, 11, 
	56, 56, 11, 11, 11, 35, 11, 57, 
	57, 11, 11, 11, 35, 11, 58, 58, 
	11, 11, 11, 35, 11, 59, 59, 11, 
	11, 11, 35, 11, 60, 60, 11, 11, 
	11, 35, 11, 61, 61, 11, 11, 11, 
	35, 11, 62, 62, 11, 11, 11, 35, 
	11, 63, 63, 11, 11, 11, 35, 11, 
	64, 64, 11, 11, 11, 35, 11, 66, 
	66, 11, 11, 11, 65, 11, 67, 67, 
	11, 11, 11, 35, 11, 68, 68, 11, 
	11, 11, 35, 11, 69, 69, 11, 11, 
	11, 35, 11, 70, 70, 11, 11, 11, 
	35, 11, 71, 71, 11, 11, 11, 35, 
	11, 72, 72, 11, 11, 11, 35, 11, 
	73, 73, 11, 11, 11, 35, 11, 74, 
	74, 11, 11, 11, 35, 11, 75, 75, 
	11, 11, 11, 35, 11, 76, 76, 11, 
	11, 11, 35, 11, 77, 77, 11, 11, 
	11, 35, 11, 78, 78, 11, 11, 11, 
	35, 11, 79, 79, 11, 11, 11, 35, 
	11, 80, 80, 11, 11, 11, 35, 34, 
	81, 82, 34, 34, 34, 4, 34, 34, 
	34, 34, 4, 0
};

static const char _lexer_trans_targs[] = {
	5, 1, 5, 2, 3, 4, 5, 5, 
	0, 6, 8, 7, 7, 7, 7, 5, 
	10, 5, 10, 7, 11, 13, 5, 14, 
	15, 18, 19, 22, 25, 29, 31, 35, 
	38, 43, 47, 5, 5, 5, 7, 9, 
	5, 12, 12, 5, 5, 5, 5, 16, 
	17, 7, 7, 7, 20, 21, 7, 23, 
	24, 7, 26, 27, 28, 7, 30, 7, 
	32, 5, 33, 34, 7, 36, 37, 7, 
	39, 40, 41, 42, 7, 44, 45, 46, 
	7, 48, 7
};

static const char _lexer_trans_actions[] = {
	35, 0, 19, 0, 0, 0, 21, 23, 
	0, 0, 5, 99, 84, 87, 90, 15, 
	75, 17, 78, 81, 0, 0, 7, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 5, 33, 13, 37, 93, 5, 
	25, 99, 39, 31, 11, 29, 9, 0, 
	0, 51, 66, 63, 0, 0, 69, 0, 
	0, 57, 0, 0, 0, 72, 0, 54, 
	0, 27, 0, 0, 60, 0, 0, 45, 
	0, 0, 0, 0, 42, 0, 0, 0, 
	48, 5, 96
};

static const char _lexer_to_state_actions[] = {
	0, 0, 0, 0, 0, 1, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0
};

static const char _lexer_from_state_actions[] = {
	0, 0, 0, 0, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0
};

static const short _lexer_eof_trans[] = {
	0, 1, 1, 1, 1, 0, 36, 38, 
	36, 36, 38, 41, 38, 44, 46, 36, 
	36, 36, 36, 36, 36, 36, 36, 36, 
	36, 36, 36, 36, 36, 36, 36, 36, 
	66, 36, 36, 36, 36, 36, 36, 36, 
	36, 36, 36, 36, 36, 36, 36, 36, 
	36
};

static const int lexer_start = 5;
static const int lexer_first_final = 5;
static const int lexer_error = 0;

static const int lexer_en_main = 5;


#line 83 "lexer.rl"

ParserContext Parse(char *str) {
  int cs, act;
  char *ts, *te;
  char *p = str;
  char *pe = p + strlen(p);
  char *eof = pe;

  Token *tk = NULL;

  ParserContext context;

  void *parser = ParseAlloc(malloc);

  
#line 286 "lexer-rl.cc"
	{
	cs = lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 98 "lexer.rl"
  
#line 296 "lexer-rl.cc"
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
#line 317 "lexer-rl.cc"
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
#line 57 "lexer.rl"
	{act = 15;}
	break;
	case 16:
#line 58 "lexer.rl"
	{act = 16;}
	break;
	case 17:
#line 59 "lexer.rl"
	{act = 17;}
	break;
	case 18:
#line 60 "lexer.rl"
	{act = 18;}
	break;
	case 19:
#line 61 "lexer.rl"
	{act = 19;}
	break;
	case 20:
#line 62 "lexer.rl"
	{act = 20;}
	break;
	case 21:
#line 73 "lexer.rl"
	{act = 29;}
	break;
	case 22:
#line 74 "lexer.rl"
	{act = 30;}
	break;
	case 23:
#line 76 "lexer.rl"
	{act = 31;}
	break;
	case 24:
#line 65 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_EQ); }}
	break;
	case 25:
#line 66 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_GE); }}
	break;
	case 26:
#line 67 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_LE); }}
	break;
	case 27:
#line 68 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_NE); }}
	break;
	case 28:
#line 69 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_STAR) }}
	break;
	case 29:
#line 70 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_COMMA) }}
	break;
	case 30:
#line 73 "lexer.rl"
	{te = p+1;{ STRING() }}
	break;
	case 31:
#line 74 "lexer.rl"
	{te = p+1;{ STRING() }}
	break;
	case 32:
#line 78 "lexer.rl"
	{te = p+1;}
	break;
	case 33:
#line 41 "lexer.rl"
	{te = p;p--;{ INTEGER() }}
	break;
	case 34:
#line 47 "lexer.rl"
	{te = p;p--;{ KEYWORD(TK_OR) }}
	break;
	case 35:
#line 63 "lexer.rl"
	{te = p;p--;{ SYMBOL(TK_GT); }}
	break;
	case 36:
#line 64 "lexer.rl"
	{te = p;p--;{ SYMBOL(TK_LT); }}
	break;
	case 37:
#line 76 "lexer.rl"
	{te = p;p--;{ ID() }}
	break;
	case 38:
#line 76 "lexer.rl"
	{{p = ((te))-1;}{ ID() }}
	break;
	case 39:
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
	case 15:
	{{p = ((te))-1;} SYMBOL(TK_PLUS) }
	break;
	case 16:
	{{p = ((te))-1;} SYMBOL(TK_MINUS) }
	break;
	case 17:
	{{p = ((te))-1;} SYMBOL(TK_DIV) }
	break;
	case 18:
	{{p = ((te))-1;} SYMBOL(TK_MOD) }
	break;
	case 19:
	{{p = ((te))-1;} SYMBOL(TK_LP) }
	break;
	case 20:
	{{p = ((te))-1;} SYMBOL(TK_RP) }
	break;
	case 29:
	{{p = ((te))-1;} STRING() }
	break;
	case 30:
	{{p = ((te))-1;} STRING() }
	break;
	case 31:
	{{p = ((te))-1;} ID() }
	break;
	}
	}
	break;
#line 600 "lexer-rl.cc"
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
#line 613 "lexer-rl.cc"
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

#line 99 "lexer.rl"

  if (cs < 
#line 636 "lexer-rl.cc"
5
#line 100 "lexer.rl"
) {
    printf("error: %s\n", p);
  }

  Parse(parser, 0, 0, &context);

  ParseFree(parser, free);

  return context;
}


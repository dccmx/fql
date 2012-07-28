
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


#line 82 "lexer.rl"



#line 45 "lexer-rl.cc"
static const char _lexer_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	26, 1, 27, 1, 28, 1, 29, 1, 
	30, 1, 31, 1, 32, 1, 33, 1, 
	34, 1, 35, 1, 36, 1, 37, 1, 
	38, 1, 39, 1, 40, 1, 41, 1, 
	42, 2, 2, 3, 2, 2, 4, 2, 
	2, 5, 2, 2, 6, 2, 2, 7, 
	2, 2, 8, 2, 2, 9, 2, 2, 
	10, 2, 2, 11, 2, 2, 12, 2, 
	2, 13, 2, 2, 14, 2, 2, 15, 
	2, 2, 16, 2, 2, 17, 2, 2, 
	18, 2, 2, 19, 2, 2, 20, 2, 
	2, 21, 2, 2, 22, 2, 2, 23, 
	2, 2, 24, 2, 2, 25
};

static const short _lexer_key_offsets[] = {
	0, 0, 2, 2, 5, 5, 7, 7, 
	53, 61, 68, 77, 84, 94, 97, 104, 
	117, 128, 140, 152, 153, 154, 165, 174, 
	183, 192, 201, 210, 219, 228, 237, 246, 
	255, 266, 275, 284, 293, 302, 311, 320, 
	329, 338, 347, 356, 365, 374, 383, 392, 
	401, 410, 419, 428, 437, 446, 455, 464
};

static const char _lexer_trans_keys[] = {
	34, 92, 39, 92, 96, 92, 96, 32, 
	33, 34, 37, 39, 40, 41, 42, 43, 
	44, 45, 46, 47, 48, 60, 61, 62, 
	65, 66, 68, 70, 76, 78, 79, 81, 
	83, 87, 96, 97, 98, 100, 102, 108, 
	110, 111, 113, 115, 119, 9, 13, 35, 
	38, 49, 57, 58, 126, 43, 61, 33, 
	41, 45, 59, 63, 126, 43, 33, 41, 
	45, 59, 63, 126, 34, 43, 92, 33, 
	41, 45, 59, 63, 126, 43, 33, 41, 
	45, 59, 63, 126, 39, 43, 92, 96, 
	33, 41, 45, 59, 63, 126, 39, 92, 
	96, 43, 33, 41, 45, 59, 63, 126, 
	43, 46, 48, 33, 41, 45, 47, 49, 
	57, 58, 59, 63, 126, 43, 33, 41, 
	45, 47, 48, 57, 58, 59, 63, 126, 
	43, 46, 33, 41, 45, 47, 48, 57, 
	58, 59, 63, 126, 43, 46, 33, 41, 
	45, 47, 48, 57, 58, 59, 63, 126, 
	61, 61, 43, 78, 83, 110, 115, 33, 
	41, 45, 59, 63, 126, 43, 68, 100, 
	33, 41, 45, 59, 63, 126, 43, 67, 
	99, 33, 41, 45, 59, 63, 126, 43, 
	89, 121, 33, 41, 45, 59, 63, 126, 
	43, 69, 101, 33, 41, 45, 59, 63, 
	126, 43, 83, 115, 33, 41, 45, 59, 
	63, 126, 43, 67, 99, 33, 41, 45, 
	59, 63, 126, 43, 82, 114, 33, 41, 
	45, 59, 63, 126, 43, 79, 111, 33, 
	41, 45, 59, 63, 126, 43, 77, 109, 
	33, 41, 45, 59, 63, 126, 43, 73, 
	105, 33, 41, 45, 59, 63, 126, 43, 
	75, 77, 107, 109, 33, 41, 45, 59, 
	63, 126, 43, 69, 101, 33, 41, 45, 
	59, 63, 126, 43, 73, 105, 33, 41, 
	45, 59, 63, 126, 43, 84, 116, 33, 
	41, 45, 59, 63, 126, 43, 79, 111, 
	33, 41, 45, 59, 63, 126, 43, 84, 
	116, 33, 41, 45, 59, 63, 126, 43, 
	82, 114, 33, 41, 45, 59, 63, 126, 
	43, 68, 100, 33, 41, 45, 59, 63, 
	126, 43, 69, 101, 33, 41, 45, 59, 
	63, 126, 43, 82, 114, 33, 41, 45, 
	59, 63, 126, 43, 85, 117, 33, 41, 
	45, 59, 63, 126, 43, 73, 105, 33, 
	41, 45, 59, 63, 126, 43, 84, 116, 
	33, 41, 45, 59, 63, 126, 43, 69, 
	101, 33, 41, 45, 59, 63, 126, 43, 
	76, 108, 33, 41, 45, 59, 63, 126, 
	43, 69, 101, 33, 41, 45, 59, 63, 
	126, 43, 67, 99, 33, 41, 45, 59, 
	63, 126, 43, 84, 116, 33, 41, 45, 
	59, 63, 126, 43, 72, 104, 33, 41, 
	45, 59, 63, 126, 43, 69, 101, 33, 
	41, 45, 59, 63, 126, 43, 82, 114, 
	33, 41, 45, 59, 63, 126, 43, 69, 
	101, 33, 41, 45, 59, 63, 126, 43, 
	92, 96, 33, 41, 45, 59, 63, 126, 
	43, 33, 41, 45, 59, 63, 126, 0
};

static const char _lexer_single_lengths[] = {
	0, 2, 0, 3, 0, 2, 0, 38, 
	2, 1, 3, 1, 4, 3, 1, 3, 
	1, 2, 2, 1, 1, 5, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	5, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 1
};

static const char _lexer_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 4, 
	3, 3, 3, 3, 3, 0, 3, 5, 
	5, 5, 5, 0, 0, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3
};

static const short _lexer_index_offsets[] = {
	0, 0, 3, 4, 8, 9, 12, 13, 
	56, 62, 67, 74, 79, 87, 91, 96, 
	105, 112, 120, 128, 130, 132, 141, 148, 
	155, 162, 169, 176, 183, 190, 197, 204, 
	211, 220, 227, 234, 241, 248, 255, 262, 
	269, 276, 283, 290, 297, 304, 311, 318, 
	325, 332, 339, 346, 353, 360, 367, 374
};

static const char _lexer_indicies[] = {
	2, 3, 1, 1, 6, 7, 4, 5, 
	5, 9, 10, 8, 8, 11, 13, 14, 
	16, 17, 18, 19, 20, 21, 22, 23, 
	24, 25, 26, 28, 29, 30, 31, 32, 
	33, 34, 35, 36, 37, 38, 39, 40, 
	41, 31, 32, 33, 34, 35, 36, 37, 
	38, 39, 40, 11, 15, 27, 15, 12, 
	15, 43, 15, 15, 15, 42, 15, 15, 
	15, 15, 4, 44, 14, 45, 14, 14, 
	14, 1, 14, 14, 14, 14, 1, 46, 
	17, 47, 15, 17, 17, 17, 5, 6, 
	7, 48, 5, 17, 17, 17, 17, 5, 
	15, 24, 26, 15, 15, 27, 15, 15, 
	4, 15, 15, 15, 49, 15, 15, 4, 
	15, 24, 15, 15, 26, 15, 15, 42, 
	15, 24, 15, 15, 27, 15, 15, 50, 
	52, 51, 54, 53, 15, 55, 56, 55, 
	56, 15, 15, 15, 42, 15, 57, 57, 
	15, 15, 15, 42, 15, 58, 58, 15, 
	15, 15, 42, 15, 59, 59, 15, 15, 
	15, 42, 15, 60, 60, 15, 15, 15, 
	42, 15, 61, 61, 15, 15, 15, 42, 
	15, 62, 62, 15, 15, 15, 42, 15, 
	63, 63, 15, 15, 15, 42, 15, 64, 
	64, 15, 15, 15, 42, 15, 65, 65, 
	15, 15, 15, 42, 15, 66, 66, 15, 
	15, 15, 42, 15, 67, 68, 67, 68, 
	15, 15, 15, 42, 15, 69, 69, 15, 
	15, 15, 42, 15, 70, 70, 15, 15, 
	15, 42, 15, 71, 71, 15, 15, 15, 
	42, 15, 72, 72, 15, 15, 15, 42, 
	15, 73, 73, 15, 15, 15, 42, 15, 
	74, 74, 15, 15, 15, 42, 15, 76, 
	76, 15, 15, 15, 75, 15, 77, 77, 
	15, 15, 15, 42, 15, 78, 78, 15, 
	15, 15, 42, 15, 79, 79, 15, 15, 
	15, 42, 15, 80, 80, 15, 15, 15, 
	42, 15, 81, 81, 15, 15, 15, 42, 
	15, 82, 82, 15, 15, 15, 42, 15, 
	83, 83, 15, 15, 15, 42, 15, 84, 
	84, 15, 15, 15, 42, 15, 85, 85, 
	15, 15, 15, 42, 15, 86, 86, 15, 
	15, 15, 42, 15, 87, 87, 15, 15, 
	15, 42, 15, 88, 88, 15, 15, 15, 
	42, 15, 89, 89, 15, 15, 15, 42, 
	15, 90, 90, 15, 15, 15, 42, 41, 
	91, 92, 41, 41, 41, 8, 41, 41, 
	41, 41, 8, 0
};

static const char _lexer_trans_targs[] = {
	7, 1, 7, 2, 7, 3, 13, 4, 
	5, 6, 7, 7, 0, 8, 10, 9, 
	9, 12, 9, 9, 7, 15, 7, 15, 
	16, 9, 17, 18, 19, 7, 20, 21, 
	24, 25, 28, 31, 36, 38, 42, 45, 
	50, 54, 7, 7, 9, 11, 12, 14, 
	7, 16, 7, 7, 7, 7, 7, 22, 
	23, 9, 9, 9, 26, 27, 9, 29, 
	30, 9, 32, 33, 34, 9, 35, 9, 
	37, 9, 39, 7, 40, 41, 9, 43, 
	44, 9, 46, 47, 48, 49, 9, 51, 
	52, 53, 9, 55, 9
};

static const char _lexer_trans_actions[] = {
	37, 0, 19, 0, 39, 0, 104, 0, 
	0, 0, 21, 23, 0, 0, 5, 107, 
	89, 107, 92, 95, 15, 80, 17, 83, 
	107, 86, 0, 0, 0, 7, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 5, 35, 13, 98, 5, 104, 107, 
	33, 41, 25, 31, 11, 29, 9, 0, 
	0, 53, 71, 68, 0, 0, 74, 0, 
	0, 62, 0, 0, 0, 59, 0, 77, 
	0, 56, 0, 27, 0, 0, 65, 0, 
	0, 47, 0, 0, 0, 0, 44, 0, 
	0, 0, 50, 5, 101
};

static const char _lexer_to_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0
};

static const char _lexer_from_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0
};

static const short _lexer_eof_trans[] = {
	0, 1, 1, 5, 5, 1, 1, 0, 
	43, 5, 43, 43, 5, 49, 43, 5, 
	5, 43, 51, 52, 54, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 76, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43
};

static const int lexer_start = 7;
static const int lexer_first_final = 7;
static const int lexer_error = 0;

static const int lexer_en_main = 7;


#line 85 "lexer.rl"

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

  
#line 300 "lexer-rl.cc"
	{
	cs = lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 101 "lexer.rl"
  
#line 310 "lexer-rl.cc"
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
#line 331 "lexer-rl.cc"
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
#line 56 "lexer.rl"
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
#line 63 "lexer.rl"
	{act = 21;}
	break;
	case 22:
#line 74 "lexer.rl"
	{act = 30;}
	break;
	case 23:
#line 75 "lexer.rl"
	{act = 31;}
	break;
	case 24:
#line 76 "lexer.rl"
	{act = 32;}
	break;
	case 25:
#line 78 "lexer.rl"
	{act = 33;}
	break;
	case 26:
#line 66 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_EQ); }}
	break;
	case 27:
#line 67 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_GE); }}
	break;
	case 28:
#line 68 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_LE); }}
	break;
	case 29:
#line 69 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_NE); }}
	break;
	case 30:
#line 70 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_STAR) }}
	break;
	case 31:
#line 71 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_COMMA) }}
	break;
	case 32:
#line 74 "lexer.rl"
	{te = p+1;{ STRING() }}
	break;
	case 33:
#line 75 "lexer.rl"
	{te = p+1;{ STRING() }}
	break;
	case 34:
#line 80 "lexer.rl"
	{te = p+1;}
	break;
	case 35:
#line 41 "lexer.rl"
	{te = p;p--;{ INTEGER() }}
	break;
	case 36:
#line 47 "lexer.rl"
	{te = p;p--;{ KEYWORD(TK_OR) }}
	break;
	case 37:
#line 64 "lexer.rl"
	{te = p;p--;{ SYMBOL(TK_GT); }}
	break;
	case 38:
#line 65 "lexer.rl"
	{te = p;p--;{ SYMBOL(TK_LT); }}
	break;
	case 39:
#line 76 "lexer.rl"
	{te = p;p--;{ STRING() }}
	break;
	case 40:
#line 78 "lexer.rl"
	{te = p;p--;{ ID() }}
	break;
	case 41:
#line 78 "lexer.rl"
	{{p = ((te))-1;}{ ID() }}
	break;
	case 42:
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
	{{p = ((te))-1;} KEYWORD(TK_LIKE) }
	break;
	case 10:
	{{p = ((te))-1;} KEYWORD(TK_FROM) }
	break;
	case 11:
	{{p = ((te))-1;} KEYWORD(TK_ORDER) }
	break;
	case 12:
	{{p = ((te))-1;} KEYWORD(TK_BY) }
	break;
	case 13:
	{{p = ((te))-1;} KEYWORD(TK_ASC) }
	break;
	case 14:
	{{p = ((te))-1;} KEYWORD(TK_DESC) }
	break;
	case 15:
	{{p = ((te))-1;} KEYWORD(TK_LIMIT) }
	break;
	case 16:
	{{p = ((te))-1;} SYMBOL(TK_PLUS) }
	break;
	case 17:
	{{p = ((te))-1;} SYMBOL(TK_MINUS) }
	break;
	case 18:
	{{p = ((te))-1;} SYMBOL(TK_DIV) }
	break;
	case 19:
	{{p = ((te))-1;} SYMBOL(TK_MOD) }
	break;
	case 20:
	{{p = ((te))-1;} SYMBOL(TK_LP) }
	break;
	case 21:
	{{p = ((te))-1;} SYMBOL(TK_RP) }
	break;
	case 30:
	{{p = ((te))-1;} STRING() }
	break;
	case 31:
	{{p = ((te))-1;} STRING() }
	break;
	case 32:
	{{p = ((te))-1;} STRING() }
	break;
	case 33:
	{{p = ((te))-1;} ID() }
	break;
	}
	}
	break;
#line 632 "lexer-rl.cc"
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
#line 645 "lexer-rl.cc"
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

#line 102 "lexer.rl"

  if (cs < 
#line 668 "lexer-rl.cc"
7
#line 103 "lexer.rl"
) {
    printf("unrecognized: %s\n", p);
    context.error = true;
  } else {
    Parse(parser, 0, 0, &context);
  }

  ParseFree(parser, free);

  return context;
}


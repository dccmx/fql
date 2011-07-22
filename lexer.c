
#line 1 "lexer.rl"
#include <string.h>
#include <stdlib.h>

#include "lexer.h"
#include "parser.h"
#include "parser.c"


#line 40 "lexer.rl"



#line 16 "lexer.c"
static const char _lexer_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	7, 1, 8, 1, 9, 1, 10, 1, 
	11
};

static const char _lexer_key_offsets[] = {
	0, 0, 2, 4, 6, 8, 10, 12, 
	14, 16, 18, 20, 22, 24, 26, 28, 
	30, 32, 34, 36, 38, 40, 42, 44, 
	46, 64
};

static const char _lexer_trans_keys[] = {
	89, 121, 82, 114, 79, 111, 77, 109, 
	73, 105, 77, 109, 73, 105, 84, 116, 
	65, 97, 77, 109, 69, 101, 82, 114, 
	68, 100, 69, 101, 82, 114, 69, 101, 
	76, 108, 69, 101, 67, 99, 84, 116, 
	73, 105, 77, 109, 69, 101, 32, 44, 
	66, 70, 76, 78, 79, 83, 84, 98, 
	102, 108, 110, 111, 115, 116, 49, 57, 
	48, 57, 0
};

static const char _lexer_single_lengths[] = {
	0, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	16, 0
};

static const char _lexer_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1
};

static const char _lexer_index_offsets[] = {
	0, 0, 3, 6, 9, 12, 15, 18, 
	21, 24, 27, 30, 33, 36, 39, 42, 
	45, 48, 51, 54, 57, 60, 63, 66, 
	69, 87
};

static const char _lexer_indicies[] = {
	0, 0, 1, 2, 2, 1, 3, 3, 
	1, 4, 4, 1, 5, 5, 1, 6, 
	6, 1, 7, 7, 1, 8, 8, 1, 
	9, 9, 1, 10, 10, 1, 11, 11, 
	1, 12, 12, 1, 13, 13, 1, 14, 
	14, 1, 15, 15, 1, 16, 16, 1, 
	17, 17, 1, 18, 18, 1, 19, 19, 
	1, 20, 20, 1, 21, 21, 1, 22, 
	22, 1, 23, 23, 1, 24, 25, 27, 
	28, 29, 30, 31, 32, 33, 27, 28, 
	29, 30, 31, 32, 33, 26, 1, 26, 
	34, 0
};

static const char _lexer_trans_targs[] = {
	24, 0, 3, 4, 24, 6, 7, 8, 
	24, 10, 11, 24, 13, 14, 15, 24, 
	17, 18, 19, 20, 24, 22, 23, 24, 
	24, 24, 25, 1, 2, 5, 9, 12, 
	16, 21, 24
};

static const char _lexer_trans_actions[] = {
	11, 0, 0, 0, 7, 0, 0, 0, 
	13, 0, 0, 15, 0, 0, 0, 9, 
	0, 0, 0, 0, 5, 0, 0, 17, 
	21, 19, 0, 0, 0, 0, 0, 0, 
	0, 0, 23
};

static const char _lexer_to_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 0
};

static const char _lexer_from_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 0
};

static const char _lexer_eof_trans[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 35
};

static const int lexer_start = 24;
static const int lexer_first_final = 24;
static const int lexer_error = 0;

static const int lexer_en_main = 24;


#line 43 "lexer.rl"

AST *Parse(char *str) {
  int cs, act;
  char *ts, *te;
  char *p = str;
  char *pe = p + strlen(p);
  char *eof = pe;

  void *parser = ParseAlloc(malloc);

  
#line 135 "lexer.c"
	{
	cs = lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 54 "lexer.rl"
  
#line 145 "lexer.c"
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
#line 166 "lexer.c"
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
#line 14 "lexer.rl"
	{te = p+1;{ 
      Parse(parser, TK_SELECT, NULL);
    }}
	break;
	case 3:
#line 17 "lexer.rl"
	{te = p+1;{ 
      Parse(parser, TK_FROM, NULL);
    }}
	break;
	case 4:
#line 20 "lexer.rl"
	{te = p+1;{ 
      Parse(parser, TK_ORDER, NULL);
    }}
	break;
	case 5:
#line 23 "lexer.rl"
	{te = p+1;{ 
      Parse(parser, TK_BY, NULL);
    }}
	break;
	case 6:
#line 26 "lexer.rl"
	{te = p+1;{ 
      Parse(parser, TK_LIMIT, NULL);
    }}
	break;
	case 7:
#line 29 "lexer.rl"
	{te = p+1;{ 
      Parse(parser, TK_LIMIT, NULL);
    }}
	break;
	case 8:
#line 32 "lexer.rl"
	{te = p+1;{ 
      Parse(parser, TK_LIMIT, NULL);
    }}
	break;
	case 9:
#line 35 "lexer.rl"
	{te = p+1;{ 
      Parse(parser, TK_COMMA, NULL);
    }}
	break;
	case 10:
#line 38 "lexer.rl"
	{te = p+1;}
	break;
	case 11:
#line 11 "lexer.rl"
	{te = p;p--;{
      Parse(parser, TK_INTEGER, 0);
    }}
	break;
#line 290 "lexer.c"
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
#line 303 "lexer.c"
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

#line 55 "lexer.rl"

  Parse(parser, TK_INTEGER, NULL);
  Parse(parser, 0, 0);

  ParseFree(parser, free);

  return NULL;
}


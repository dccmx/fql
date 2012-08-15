
#line 1 "lexer.rl"
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


#line 76 "lexer.rl"



#line 38 "lexer.c"
static const char _lexer_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	25, 1, 26, 1, 27, 1, 28, 1, 
	29, 1, 30, 1, 31, 1, 32, 1, 
	33, 1, 34, 1, 35, 1, 36, 1, 
	37, 1, 38, 1, 39, 1, 40, 1, 
	41, 1, 42, 1, 43, 2, 2, 3, 
	2, 2, 4, 2, 2, 5, 2, 2, 
	6, 2, 2, 7, 2, 2, 8, 2, 
	2, 9, 2, 2, 10, 2, 2, 11, 
	2, 2, 12, 2, 2, 13, 2, 2, 
	14, 2, 2, 15, 2, 2, 16, 2, 
	2, 17, 2, 2, 18, 2, 2, 19, 
	2, 2, 20, 2, 2, 21, 2, 2, 
	22, 2, 2, 23, 2, 2, 24
};

static const short _lexer_key_offsets[] = {
	0, 0, 2, 2, 5, 5, 7, 7, 
	53, 61, 68, 77, 84, 94, 97, 104, 
	117, 128, 140, 152, 167, 168, 169, 180, 
	189, 198, 207, 216, 225, 234, 243, 252, 
	261, 270, 281, 290, 299, 308, 317, 326, 
	335, 344, 353, 362, 371, 380, 389, 398, 
	407, 416, 425, 434, 443, 452, 461, 470, 
	479
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
	43, 46, 48, 82, 114, 33, 41, 45, 
	47, 49, 57, 58, 59, 63, 126, 61, 
	61, 43, 78, 83, 110, 115, 33, 41, 
	45, 59, 63, 126, 43, 68, 100, 33, 
	41, 45, 59, 63, 126, 43, 67, 99, 
	33, 41, 45, 59, 63, 126, 43, 89, 
	121, 33, 41, 45, 59, 63, 126, 43, 
	69, 101, 33, 41, 45, 59, 63, 126, 
	43, 83, 115, 33, 41, 45, 59, 63, 
	126, 43, 67, 99, 33, 41, 45, 59, 
	63, 126, 43, 82, 114, 33, 41, 45, 
	59, 63, 126, 43, 79, 111, 33, 41, 
	45, 59, 63, 126, 43, 77, 109, 33, 
	41, 45, 59, 63, 126, 43, 73, 105, 
	33, 41, 45, 59, 63, 126, 43, 75, 
	77, 107, 109, 33, 41, 45, 59, 63, 
	126, 43, 69, 101, 33, 41, 45, 59, 
	63, 126, 43, 73, 105, 33, 41, 45, 
	59, 63, 126, 43, 84, 116, 33, 41, 
	45, 59, 63, 126, 43, 79, 111, 33, 
	41, 45, 59, 63, 126, 43, 84, 116, 
	33, 41, 45, 59, 63, 126, 43, 82, 
	114, 33, 41, 45, 59, 63, 126, 43, 
	68, 100, 33, 41, 45, 59, 63, 126, 
	43, 69, 101, 33, 41, 45, 59, 63, 
	126, 43, 82, 114, 33, 41, 45, 59, 
	63, 126, 43, 85, 117, 33, 41, 45, 
	59, 63, 126, 43, 73, 105, 33, 41, 
	45, 59, 63, 126, 43, 84, 116, 33, 
	41, 45, 59, 63, 126, 43, 69, 101, 
	33, 41, 45, 59, 63, 126, 43, 76, 
	108, 33, 41, 45, 59, 63, 126, 43, 
	69, 101, 33, 41, 45, 59, 63, 126, 
	43, 67, 99, 33, 41, 45, 59, 63, 
	126, 43, 84, 116, 33, 41, 45, 59, 
	63, 126, 43, 72, 104, 33, 41, 45, 
	59, 63, 126, 43, 69, 101, 33, 41, 
	45, 59, 63, 126, 43, 82, 114, 33, 
	41, 45, 59, 63, 126, 43, 69, 101, 
	33, 41, 45, 59, 63, 126, 43, 92, 
	96, 33, 41, 45, 59, 63, 126, 43, 
	33, 41, 45, 59, 63, 126, 0
};

static const char _lexer_single_lengths[] = {
	0, 2, 0, 3, 0, 2, 0, 38, 
	2, 1, 3, 1, 4, 3, 1, 3, 
	1, 2, 2, 5, 1, 1, 5, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 5, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	1
};

static const char _lexer_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 4, 
	3, 3, 3, 3, 3, 0, 3, 5, 
	5, 5, 5, 5, 0, 0, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3
};

static const short _lexer_index_offsets[] = {
	0, 0, 3, 4, 8, 9, 12, 13, 
	56, 62, 67, 74, 79, 87, 91, 96, 
	105, 112, 120, 128, 139, 141, 143, 152, 
	159, 166, 173, 180, 187, 194, 201, 208, 
	215, 222, 231, 238, 245, 252, 259, 266, 
	273, 280, 287, 294, 301, 308, 315, 322, 
	329, 336, 343, 350, 357, 364, 371, 378, 
	385
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
	49, 15, 15, 15, 50, 15, 15, 4, 
	15, 24, 15, 15, 26, 15, 15, 42, 
	15, 24, 15, 15, 27, 15, 15, 51, 
	15, 24, 26, 53, 53, 15, 15, 27, 
	15, 15, 52, 55, 54, 57, 56, 15, 
	58, 59, 58, 59, 15, 15, 15, 42, 
	15, 60, 60, 15, 15, 15, 42, 15, 
	61, 61, 15, 15, 15, 42, 15, 62, 
	62, 15, 15, 15, 42, 15, 63, 63, 
	15, 15, 15, 42, 15, 64, 64, 15, 
	15, 15, 42, 15, 65, 65, 15, 15, 
	15, 42, 15, 66, 66, 15, 15, 15, 
	42, 15, 67, 67, 15, 15, 15, 42, 
	15, 68, 68, 15, 15, 15, 42, 15, 
	69, 69, 15, 15, 15, 42, 15, 70, 
	71, 70, 71, 15, 15, 15, 42, 15, 
	72, 72, 15, 15, 15, 42, 15, 73, 
	73, 15, 15, 15, 42, 15, 74, 74, 
	15, 15, 15, 42, 15, 75, 75, 15, 
	15, 15, 42, 15, 76, 76, 15, 15, 
	15, 42, 15, 77, 77, 15, 15, 15, 
	42, 15, 79, 79, 15, 15, 15, 78, 
	15, 80, 80, 15, 15, 15, 42, 15, 
	81, 81, 15, 15, 15, 42, 15, 82, 
	82, 15, 15, 15, 42, 15, 83, 83, 
	15, 15, 15, 42, 15, 84, 84, 15, 
	15, 15, 42, 15, 85, 85, 15, 15, 
	15, 42, 15, 86, 86, 15, 15, 15, 
	42, 15, 87, 87, 15, 15, 15, 42, 
	15, 88, 88, 15, 15, 15, 42, 15, 
	89, 89, 15, 15, 15, 42, 15, 90, 
	90, 15, 15, 15, 42, 15, 91, 91, 
	15, 15, 15, 42, 15, 92, 92, 15, 
	15, 15, 42, 15, 93, 93, 15, 15, 
	15, 42, 41, 94, 95, 41, 41, 41, 
	8, 41, 41, 41, 41, 8, 0
};

static const char _lexer_trans_targs[] = {
	7, 1, 7, 2, 7, 3, 13, 4, 
	5, 6, 7, 7, 0, 8, 10, 9, 
	9, 12, 9, 9, 7, 15, 7, 19, 
	16, 9, 17, 18, 20, 7, 21, 22, 
	25, 26, 29, 32, 37, 39, 43, 46, 
	51, 55, 7, 7, 9, 11, 12, 14, 
	7, 7, 16, 7, 7, 9, 7, 7, 
	7, 7, 23, 24, 9, 9, 9, 27, 
	28, 9, 30, 31, 9, 33, 34, 35, 
	9, 36, 9, 38, 9, 40, 7, 41, 
	42, 9, 44, 45, 9, 47, 48, 49, 
	50, 9, 52, 53, 54, 9, 56, 9
};

static const char _lexer_trans_actions[] = {
	41, 0, 19, 0, 43, 0, 105, 0, 
	0, 0, 21, 23, 0, 0, 5, 108, 
	90, 108, 93, 96, 15, 0, 17, 0, 
	108, 87, 0, 0, 0, 7, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 5, 39, 13, 99, 5, 105, 108, 
	37, 29, 45, 25, 31, 69, 35, 11, 
	33, 9, 0, 0, 57, 78, 75, 0, 
	0, 81, 0, 0, 66, 0, 0, 0, 
	63, 0, 84, 0, 60, 0, 27, 0, 
	0, 72, 0, 0, 51, 0, 0, 0, 
	0, 48, 0, 0, 0, 54, 5, 102
};

static const char _lexer_to_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0
};

static const char _lexer_from_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0
};

static const short _lexer_eof_trans[] = {
	0, 1, 1, 5, 5, 1, 1, 0, 
	43, 5, 43, 43, 5, 49, 43, 50, 
	5, 43, 52, 53, 55, 57, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	79, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43
};

static const int lexer_start = 7;
static const int lexer_first_final = 7;
static const int lexer_error = 0;

static const int lexer_en_main = 7;


#line 79 "lexer.rl"

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

  
#line 303 "lexer.c"
	{
	cs = lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 95 "lexer.rl"
  
#line 313 "lexer.c"
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
#line 334 "lexer.c"
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
#line 35 "lexer.rl"
	{act = 2;}
	break;
	case 4:
#line 37 "lexer.rl"
	{act = 3;}
	break;
	case 5:
#line 38 "lexer.rl"
	{act = 4;}
	break;
	case 6:
#line 39 "lexer.rl"
	{act = 5;}
	break;
	case 7:
#line 41 "lexer.rl"
	{act = 7;}
	break;
	case 8:
#line 42 "lexer.rl"
	{act = 8;}
	break;
	case 9:
#line 43 "lexer.rl"
	{act = 9;}
	break;
	case 10:
#line 44 "lexer.rl"
	{act = 10;}
	break;
	case 11:
#line 45 "lexer.rl"
	{act = 11;}
	break;
	case 12:
#line 46 "lexer.rl"
	{act = 12;}
	break;
	case 13:
#line 47 "lexer.rl"
	{act = 13;}
	break;
	case 14:
#line 48 "lexer.rl"
	{act = 14;}
	break;
	case 15:
#line 49 "lexer.rl"
	{act = 15;}
	break;
	case 16:
#line 50 "lexer.rl"
	{act = 16;}
	break;
	case 17:
#line 54 "lexer.rl"
	{act = 19;}
	break;
	case 18:
#line 55 "lexer.rl"
	{act = 20;}
	break;
	case 19:
#line 56 "lexer.rl"
	{act = 21;}
	break;
	case 20:
#line 57 "lexer.rl"
	{act = 22;}
	break;
	case 21:
#line 68 "lexer.rl"
	{act = 31;}
	break;
	case 22:
#line 69 "lexer.rl"
	{act = 32;}
	break;
	case 23:
#line 70 "lexer.rl"
	{act = 33;}
	break;
	case 24:
#line 72 "lexer.rl"
	{act = 34;}
	break;
	case 25:
#line 60 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_EQ); }}
	break;
	case 26:
#line 61 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_GE); }}
	break;
	case 27:
#line 62 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_LE); }}
	break;
	case 28:
#line 63 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_NE); }}
	break;
	case 29:
#line 64 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_STAR) }}
	break;
	case 30:
#line 65 "lexer.rl"
	{te = p+1;{ SYMBOL(TK_COMMA) }}
	break;
	case 31:
#line 68 "lexer.rl"
	{te = p+1;{ STRING() }}
	break;
	case 32:
#line 69 "lexer.rl"
	{te = p+1;{ STRING() }}
	break;
	case 33:
#line 74 "lexer.rl"
	{te = p+1;}
	break;
	case 34:
#line 34 "lexer.rl"
	{te = p;p--;{ INTEGER() }}
	break;
	case 35:
#line 40 "lexer.rl"
	{te = p;p--;{ KEYWORD(TK_OR) }}
	break;
	case 36:
#line 52 "lexer.rl"
	{te = p;p--;{ SYMBOL(TK_PLUS) }}
	break;
	case 37:
#line 53 "lexer.rl"
	{te = p;p--;{ SYMBOL(TK_MINUS) }}
	break;
	case 38:
#line 58 "lexer.rl"
	{te = p;p--;{ SYMBOL(TK_GT); }}
	break;
	case 39:
#line 59 "lexer.rl"
	{te = p;p--;{ SYMBOL(TK_LT); }}
	break;
	case 40:
#line 70 "lexer.rl"
	{te = p;p--;{ STRING() }}
	break;
	case 41:
#line 72 "lexer.rl"
	{te = p;p--;{ ID() }}
	break;
	case 42:
#line 72 "lexer.rl"
	{{p = ((te))-1;}{ ID() }}
	break;
	case 43:
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
	{{p = ((te))-1;} KEYWORD(TK_RECURSIVE) }
	break;
	case 12:
	{{p = ((te))-1;} KEYWORD(TK_ORDER) }
	break;
	case 13:
	{{p = ((te))-1;} KEYWORD(TK_BY) }
	break;
	case 14:
	{{p = ((te))-1;} KEYWORD(TK_ASC) }
	break;
	case 15:
	{{p = ((te))-1;} KEYWORD(TK_DESC) }
	break;
	case 16:
	{{p = ((te))-1;} KEYWORD(TK_LIMIT) }
	break;
	case 19:
	{{p = ((te))-1;} SYMBOL(TK_DIV) }
	break;
	case 20:
	{{p = ((te))-1;} SYMBOL(TK_MOD) }
	break;
	case 21:
	{{p = ((te))-1;} SYMBOL(TK_LP) }
	break;
	case 22:
	{{p = ((te))-1;} SYMBOL(TK_RP) }
	break;
	case 31:
	{{p = ((te))-1;} STRING() }
	break;
	case 32:
	{{p = ((te))-1;} STRING() }
	break;
	case 33:
	{{p = ((te))-1;} STRING() }
	break;
	case 34:
	{{p = ((te))-1;} ID() }
	break;
	}
	}
	break;
#line 636 "lexer.c"
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
#line 649 "lexer.c"
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

#line 96 "lexer.rl"

  if (cs < 
#line 672 "lexer.c"
7
#line 97 "lexer.rl"
) {
    printf("unrecognized: %s\n", p);
    context.error = true;
  } else {
    Parse(parser, 0, 0, &context);
  }

  ParseFree(parser, free);

  return context;
}

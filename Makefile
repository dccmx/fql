#
# fql - Makefile
#
# Author: dccmx <dccmx@dccmx.com>
#

VERSION    = 0.1

OBJFILES   = fql.cc ast.cc lexer.cc table.cc
INCFILES   = lexer.h ast.h table.h

CFLAGS_GEN = -Wall -g $(CFLAGS) -DVERSION=\"$(VERSION)\"
CFLAGS_DBG = -ggdb $(CFLAGS_GEN)
CFLAGS_OPT = -O3 -Wno-format -Wno-unused-result $(CFLAGS_GEN)

LDFLAGS   += 
LIBS      += 

all: fql
	@echo
	@echo "Make Complete. See README for how to use."
	@echo
	@echo "Having problems with it? Send complains and bugs to dccmx@dccmx.com"
	@echo

lexer.cc: lexer.rl parser.y
	lemon parser.y
	ragel -o lexer.cc -C lexer.rl

fql: fql.cc $(OBJFILES) $(INCFILES)
	$(CXX) $(LDFLAGS) -o fql $(CFLAGS_OPT) $(LIBS) $^

clean:
	rm -f fql core core.[1-9][0-9]* memcheck.out callgrind.out.[1-9][0-9]* massif.out.[1-9][0-9]*

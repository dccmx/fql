#
# fql - Makefile
#
# Author: dccmx <dccmx@dccmx.com>
#

VERSION    = 0.1

OBJFILES   = fql.cc ast.cc lexer.cc lexer-rl.cc table.cc variant.cc sys.cc expr.cc
INCFILES   = lexer.h ast.h table.h variant.h sys.h expr.h

CFLAGS_GEN = -g $(CFLAGS) -DVERSION=\"$(VERSION)\"
CFLAGS_DBG = -Wall -ggdb $(CFLAGS_GEN)
CFLAGS_OPT = -O3 -Wno-format -Wno-unused-variable -Wno-unused-result $(CFLAGS_GEN)
CFLAGS_MAC = -O3 -Wno-format -Wno-unused-variable $(CFLAGS_GEN)

LDFLAGS   += 
LIBS      += 

all: fql
	@echo
	@echo "Make Complete. See README for how to use."
	@echo
	@echo "Having problems with it? Send complains and bugs to dccmx@dccmx.com"
	@echo

mac: fql.cc $(OBJFILES) $(INCFILES)
	$(CXX) $(LDFLAGS) -o fql $(CFLAGS_MAC) $(LIBS) $^
	@echo
	@echo "Make Complete. See README for how to use."
	@echo
	@echo "Having problems with it? Send complains and bugs to dccmx@dccmx.com"
	@echo

lexer-rl.cc: lexer.rl parser.y
	lemon parser.y
	mv parser.c parser.cc
	ragel -o lexer-rl.cc -C lexer.rl

debug: fql.cc $(OBJFILES) $(INCFILES)
	$(CXX) $(LDFLAGS) -o fql $(CFLAGS_DBG) $(LIBS) $^

fql: fql.cc $(OBJFILES) $(INCFILES)
	$(CXX) $(LDFLAGS) -o fql $(CFLAGS_OPT) $(LIBS) $^

clean:
	rm -f fql core core.[1-9][0-9]* memcheck.out callgrind.out.[1-9][0-9]* massif.out.[1-9][0-9]*

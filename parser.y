%include {
#include <assert.h>
}
%token_destructor { delete $$; }

%parse_accept {}
%syntax_error {
  printf("parse error near: %s\n", TOKEN->str);
  exit(-1);
}

%stack_overflow {
  printf("Stack overflowed\n");
}

%extra_argument {ParserContext *ctx}

%token_type {Token*}
%token_prefix TK_

%type select {Select*}
%type attrlist {vector<string>*}
%type folderlist {vector<string>*}
%type from {vector<string>*}

stmt ::= select(A). {
  ctx->stmt = A;
}

select(A) ::= SELECT distinct(D) attrlist(C) from(F) where orderby limit. {
  A = new Select();
  if (D != NULL) {
    A->set_distinct(true);
    delete D;
  }
  A->set_attrs(C);
  A->set_folders(F);
}

distinct ::= DISTINCT.
distinct ::= .

name(A) ::= ID|STRING(B). {
  A = B;
}

attrlist(A) ::= name(B). {
  A = new vector<string>();
  A->push_back(string(B->str));
  delete B;
}

attrlist(A) ::= STAR(B). {
  A = new vector<string>();
  A->push_back(string(B->str));
  delete B;
}

attrlist(A) ::= attrlist(B) COMMA name(C). {
  B->push_back(string(C->str));
  delete C;
  A = B;
}

from ::= .
from(A) ::= FROM folderlist(B). {
  A = B;
}

folderlist(A) ::= name(B). {
  A = new vector<string>();
  A->push_back(string(B->str));
  delete B;
}

folderlist(A) ::= folderlist(B) COMMA name(C). {
  B->push_back(string(C->str));
  delete C;
  A = B;
}

op(A) ::= GT|LT|EQ(B). {
  A = B;
}

value(A) ::= INTEGER|STRING(B). {
  A = B;
}

condition ::= ID op value.
condition ::= NOT ID op value.

conditionlist ::= condition.
conditionlist ::= conditionlist AND|OR condition.

where ::= .
where ::= WHERE conditionlist.

orderby ::= .
orderby ::= ORDER BY attrlist order.

order ::= ASC|DESC.

limit ::= .
limit ::= LIMIT INTEGER.

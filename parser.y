%include {
#include <assert.h>
}
%token_destructor { delete $$; }

%parse_accept {}
%syntax_error {
    printf("parse error\n");
}

%stack_overflow {
    printf("Stack overflowed\n");
}

%extra_argument {Stmt **stmt}

%token_type {Token*}
%token_prefix TK_

%type stmt {Stmt*}
%type select {Select*}
%type attrlist {vector<string>*}
%type folderlist {vector<string>*}
%type from {vector<string>*}

stmt(A) ::= select(B). {
  A = new Stmt();
  A->set_select(B);
  *stmt = A;
}

select(A) ::= SELECT distinct(D) attrlist(C) from(F) where orderby limit. {
  A = new Select();
  if (D != NULL) A->set_distinct(true);
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
}

attrlist(A) ::= STAR(B). {
  A = new vector<string>();
  A->push_back(string(B->str));
}

attrlist(A) ::= attrlist(B) COMMA name(C). {
  B->push_back(string(C->str));
  A = B;
}

from ::= .
from(A) ::= FROM folderlist(B). {
  A = B;
}

folderlist(A) ::= name(B). {
  A = new vector<string>();
  A->push_back(string(B->str));
}

folderlist(A) ::= folderlist(B) COMMA name(C). {
  B->push_back(string(C->str));
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

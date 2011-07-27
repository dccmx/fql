%include {
#include <assert.h>
}
%token_destructor { delete $$; }

%parse_accept {
}

%syntax_error {
    printf("parse error\n");
}

%stack_overflow {
    printf("Stack overflowed\n");
}

%token_type {Token*}
%token_prefix TK_

%type stmt {Stmt*}
%type select {Select*}

stmt(A) ::= select(B). {
  A->set_select(B);
}

select(A) ::= SELECT distinct(D) attrlist(C) from where orderby limit. {
  if (D != NULL) A->set_distinct(true);
  A->set_attrs(*C);
}

distinct ::= DISTINCT.
distinct ::= .

name ::= ID|STRING.

%type attrlist {vector<string>*}
attrlist(A) ::= name(B). {
  //A = new vector<string>();
  printf("%s\n", B->str);
  printf("%d\n", A);
  //A->push_back(string(B->str));
}

attrlist ::= STAR.
attrlist ::= attrlist COMMA name.

from ::= FROM folderlist.
from ::= .

folderlist ::= name.
folderlist ::= folderlist COMMA name.

op ::= GT|LT|EQ.

value ::= INTEGER|STRING.

condition ::= ID op value.
condition ::= NOT ID op value.

conditionlist ::= condition.
conditionlist ::= conditionlist AND|OR condition.

where ::= WHERE conditionlist.
where ::= .

orderby ::= .
orderby ::= ORDER BY attrlist order.

order ::= ASC|DESC.

limit ::= LIMIT INTEGER.
limit ::= .

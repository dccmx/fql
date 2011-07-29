%include {
#include <assert.h>
}
%token_destructor { delete $$; }

%parse_accept {}
%syntax_error {
  if (TOKEN) printf("syntax error near: %s\n", TOKEN->str);
  else printf("syntax error\n");
  ctx->error = true;
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
%type orderlist {OrderList*}
%type orderby {OrderList*}

stmt ::= select(A). {
  ctx->stmt = A;
}

stmt ::= QUIT. {
  exit(0);
}

select(A) ::= SELECT distinct(D) attrlist(C) from(F) where orderby(O) limit. {
  A = new Select();
  if (D != NULL) {
    A->set_distinct(true);
    delete D;
  }
  A->set_attrs(C);
  A->set_folders(F);
  A->set_orders(O);
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

/*
folderlist(A) ::= folderlist(B) COMMA name(C). {
  B->push_back(string(C->str));
  delete C;
  A = B;
}
*/

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

orderlist(A) ::= name(B) order(C). {
  A = new OrderList();
  A->attrs.push_back(string(B->str));
  if (C) A->dirs.push_back(C->value);
  else A->dirs.push_back(TK_ASC);
}
orderlist(A) ::= orderlist(B) COMMA name(C) order(D). {
  B->attrs.push_back(string(C->str));
  if (D) B->dirs.push_back(D->value);
  else B->dirs.push_back(TK_ASC);
  A = B;
}

order ::= .
order(A) ::= ASC|DESC(B). {
  A = B;
}

orderby ::= .
orderby(A) ::= ORDER BY orderlist(B). {
  A = B;
}

limit ::= .
limit ::= LIMIT INTEGER.

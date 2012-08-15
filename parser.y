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
%type cols {vector<string>*}
%type attrlist {vector<string>*}
%type folder {Folder*}
%type from {Folder*}
%type expr {Expr*}
%type where {Expr*}
%type orderlist {OrderList*}
%type orderby {OrderList*}
%type limit {Limit*}

stmt ::= select(A). {
  ctx->stmt = A;
}

stmt ::= QUIT. {
  exit(0);
}

select(A) ::= SELECT distinct(D) cols(C) from(F) where(W) orderby(O) limit(L). {
  A = new Select();
  if (D != NULL) {
    A->set_distinct(true);
    delete D;
  }
  A->set_attrs(C);
  A->set_folder(F);
  A->set_where(W);
  A->set_orders(O);
  A->set_limit(L);
}

distinct(A) ::= DISTINCT(B). {
  A = B;
}
distinct ::= .

name(A) ::= ID|STRING|FLOAT|INTEGER(B). {
  A = B;
}

cols(A) ::= attrlist(B). {
  A = B;
}

attrlist(A) ::= STAR(B). {
  A = new vector<string>();
  A->push_back(string("tperms"));
  A->push_back(string("nlink"));
  A->push_back(string("uname"));
  A->push_back(string("gname"));
  A->push_back(string("size"));
  A->push_back(string("time"));
  A->push_back(string("name"));
  delete B;
}

attrlist(A) ::= name(B). {
  A = new vector<string>();
  A->push_back(string(B->str));
  delete B;
}

attrlist(A) ::= attrlist(B) COMMA name(C). {
  A = B;
  A->push_back(string(C->str));
  delete C;
}

attrlist(A) ::= attrlist(B) COMMA STAR(C). {
  A = B;
  A->push_back(string("tperms"));
  A->push_back(string("nlink"));
  A->push_back(string("uname"));
  A->push_back(string("gname"));
  A->push_back(string("size"));
  A->push_back(string("time"));
  A->push_back(string("name"));
  delete C;
}

from ::= .
from(A) ::= FROM folder(B). {
  A = B;
}

folder(A) ::= name(B) recursive(C). {
  A = new Folder();
  A->name = string(B->str);
  A->recursive = false;
  if (C != NULL) {
    A->recursive =true;
    delete C;
  }
  delete B;
}

recursive(A) ::= RECURSIVE(B). {
  A = B;
}
recursive ::= .

%left PLUS MINUS.
%left DIV MOD STAR.
%right NOT.
%left OR.
%left AND.
%left LIKE.
%left GT LT EQ GE LE NE.

expr(A) ::= name(B). {
  A = new Value(B->ToVariant(), @B);
  delete B;
}
expr(A) ::= NOT expr(B). {
  A = new UnaryExpr(TK_NOT, B);
}
expr(A) ::= LP expr(B) RP. {
  A = B;
}
expr(A) ::= expr(B) AND expr(C). {
  A = new BinaryExpr(TK_AND, B, C);
}
expr(A) ::= expr(B) OR expr(C). {
  A = new BinaryExpr(TK_OR, B, C);
}
expr(A) ::= expr(B) LIKE expr(C). {
  A = new BinaryExpr(TK_LIKE, B, C);
}
expr(A) ::= expr(B) PLUS|MINUS(OP) expr(C). {
  A = new BinaryExpr(@OP, B, C);
  delete OP;
}
expr(A) ::= expr(B) DIV|MOD|STAR(OP) expr(C). {
  A = new BinaryExpr(@OP, B, C);
  delete OP;
}
expr(A) ::= expr(B) GT|LT|EQ|GE|LE|NE(OP) expr(C). {
  A = new BinaryExpr(@OP, B, C);
  delete OP;
}

where ::= .
where(A) ::= WHERE expr(B). {
  A = B;
}

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

limit(A) ::= . {
  A = new Limit();
}
limit(A) ::= LIMIT INTEGER(B). {
  A = new Limit();
  A->limit = B->value;
  delete B;
}
limit(A) ::= LIMIT INTEGER(P) COMMA INTEGER(L). {
  A = new Limit();
  A->start = P->value;
  A->limit = L->value;
  delete P;
  delete L;
}

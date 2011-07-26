%include {
#include <assert.h>
}

%token_type {Token*}
%token_prefix TK_

stmt ::= select.

select ::= SELECT distinct attrlist from where orderby limit.

distinct ::= DISTINCT.
distinct ::= .

attr ::= ID.

attrlist ::= attr.
attrlist ::= STAR.
attrlist ::= attrlist COMMA attr.

from ::= FROM folderlist.
from ::= .

folderlist ::= FILE_NAME.
folderlist ::= folderlist COMMA FILE_NAME.

op ::= GT|LT|EQ.

value ::= INTEGER.

condition ::= attr op value.
condition ::= NOT attr op value.

conditionlist ::= condition.
conditionlist ::= conditionlist AND|OR condition.

where ::= WHERE conditionlist.
where ::= .

orderby ::= .
orderby ::= ORDER BY attrlist order.

order ::= ASC|DESC.

limit ::= LIMIT INTEGER.
limit ::= .

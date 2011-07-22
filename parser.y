%include {
#include <assert.h>
}

%token_type {Token*}
%token_prefix TK_

stmt ::= select.

select ::= SELECT distinct attrlist from where orderby limit. {
}

distinct ::= DISTINCT.
distinct ::= .

attrlist ::= NAME|TIME.

from ::= FROM folderlist.
from ::= .

folderlist ::= FILE_NAME.
folderlist ::= folderlist COMMA FILE_NAME.

where ::= WHERE.
where ::= .

orderby ::= .
orderby ::= ORDER BY attrlist.

limit ::= LIMIT INTEGER.
limit ::= .

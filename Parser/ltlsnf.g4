grammar ltlsnf;

// Lexer rules

LPAREN : '(';
RPAREN : ')';
LBRACK : '[';
RBRACK : ']';
COMMA : ',';
NOT : 'not';
AND : 'and';
OR : 'or';
ALWAYS : 'always';
NEXT : 'next';
SOMETIME : 'sometime';
WS : [ \t\r\n] -> skip;
fragment DIGIT : [0-9];
fragment LETTER : [a-z];
IDENTIFIER : LETTER (LETTER | DIGIT)*;

// Parser rules
formula : AND LPAREN listOfSnfClauses RPAREN '.';

listOfSnfClauses : LBRACK snfClauseList? RBRACK;

snfClauseList : snfClause (COMMA snfClause)*;

snfClause : alwaysClause | propositionalClause;

alwaysClause : ALWAYS LPAREN temporalClause RPAREN;

temporalClause : propositionalClause | stepClause | sometimeClause;

propositionalClause : OR LPAREN LBRACK literalList RBRACK RPAREN;

stepClause : OR LPAREN LBRACK literalList COMMA nextLiteralList RBRACK RPAREN;

sometimeClause : OR LPAREN LBRACK literalList COMMA SOMETIME LPAREN literal RPAREN RBRACK RPAREN;

literalList : literal (COMMA literal)*;

nextLiteralList : NEXT LPAREN literal RPAREN (COMMA NEXT LPAREN literal RPAREN)*;

literal : NOT LPAREN IDENTIFIER RPAREN | IDENTIFIER;


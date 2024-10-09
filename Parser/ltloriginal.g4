grammar ltloriginal;

NOT : 'not' | '~' | '-';
AND : 'and' | '&';
OR : 'or' | '|';
ALWAYS : 'always' | '[]';
NEXT : 'next';
SOMETIME : 'sometime' | '<>';
UNTIL : 'U' | 'until';
IMPLIES : '=>' | '->';
IFF : '<=>' | '<->';
WS : [ \t\r\n] -> skip;
fragment DIGIT : [0-9];
fragment LETTER : [a-z];
IDENTIFIER : [a-zA-Z_][a-zA-Z0-9_]*;

start : ltl_formula EOF;

ltl_formula : ltl_formula AND ltl_term
            | ltl_formula OR ltl_term
            | ltl_formula IMPLIES ltl_term
            | ltl_formula IFF ltl_term
            | ltl_term
            ;

ltl_term : ltl_term UNTIL ltl_factor
         | ltl_factor
         ;

ltl_factor : NOT ltl_factor
           | NEXT ltl_factor
           | ALWAYS ltl_factor
           | SOMETIME ltl_factor
           | '(' ltl_formula ')'
           | IDENTIFIER
           ;

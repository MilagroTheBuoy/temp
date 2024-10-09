grammar kspclauses;

file: section* EOF;

section: section_header clause*;

section_header: SECTION_NAME;

clause: '(' INT ',' INT ')' '[' INT ',' INT '].' term '=>' clause_body;

clause_body: 
      box_clause
    | diamond_clause
    | classical_clause
    ;

diamond_clause: ( '~' 'box' INT '~' term );

box_clause: ( 'box' INT term );

classical_clause: term ( '|' term )* ; 

term: NOT? ID;

SECTION_NAME: ('Usable: Literal Clauses' | 'SoS: Literal Clauses' | 'SoS: Modal Clauses' | 'Deleted clauses:' | 'Learnt Clauses');  
INT: [0-9]+;
NOT: '~';
ID: '_'? '$'? [a-zA-Z][a-zA-Z0-9]*;
WS: [ \t\n]+ -> skip;  

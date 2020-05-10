D                       [0-9]
L                       [a-zA-Z_]


%{
#include <stdio.h>
#include "y.tab.h"
%}

%option yylineno
%%
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] {printf("Detection d'un commentaire ligne %d\n", yylineno);}
[/][*]    { yyerror("Commentaire non ferme ligne\n", yylineno); }
"extern"                return EXTERN;
"goto"                  return GOTO;
"if"                    return IF;
"int"                   return INT;
"return"                return RETURN;
"void"                  return VOID;

{D}*                    return CONSTANT;
{L}({L}|{D})*           return IDENTIFIER;

"="     return '=';
";"			return ';';
("{")		return '{';
("}")		return '}';
("[")		return '[';
("]")		return ']';
"("			return '(';
")"			return ')';
"&"			return '&';
"*"			return '*';
"-"			return '-'; 
"/"			return '/'; 
"+"			return '+';
"<"			return '<';
">"			return '>'; 
","			return ',';
"."			return '.';
":"			return ':';
"!"			return '!';
"~"			return '~';
"%"			return '%';
"^"			return '^';
"|"			return '|';
"?"			return '?';

[ \r\t\n]+        ;

"<="    return LE_OP;
">="    return GE_OP;
"=="    return EQ_OP;
"!="    return NE_OP;

.       {printf("Echec analyse lexicale ligne %d \n", yylineno);};
%%

int yywrap(void)
{
  return 1;
}

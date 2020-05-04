D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
S						[ \t\v\n\f\s\r]

%{
#include <stdio.h>
#include "y.tab.h"
void comment();

%}

%option yylineno

%%
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] {printf("Detection d'un commentaire\n");}
[/][*]    { printf("Commentaire non ferme\n"); }
"else"                 return ELSE; 
"extern"               return EXTERN;
"for"                  return FOR;
"if"                   return IF;
"int"                  return INT;
"return"               return RETURN;
"sizeof"               return SIZEOF;
"struct"               return STRUCT;
"void"                 return VOID;
"while"                return WHILE;

{D}*                   return CONSTANT;
{L}({L}|{D})*          return IDENTIFIER;

"="                    return EQ;

";"			return ';';
("{")			return '{';
("}")			return '}';
("[")			return '[';
("]")			return ']';
"("			return '(';
")"			return ')';




"&"			return '&';
"*"			return STAR;
"-"			return MINUS; 
"/"			return SLASH; 
"+"			return PLUS;
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

[\n]                    {}
[ \r\t]+           	;

"->"                    return PTR_OP;
"&&"                    return AND_OP;
"||"                    return OR_OP;
"<="                    return LE_OP;
">="                    return GE_OP;
"=="                    return EQ_OP;
"!="                    return NE_OP;

">>"			return SHIFTRIGHT_OP;
"<<"			return SHIFTLEFT_OP;
"++"			return INC_OP;
"--"			return DEC_OP;

.                       {printf("Caractere non reconnu ligne %d \n", yylineno);};

%%

int yywrap(void)
{
  return 1;
}

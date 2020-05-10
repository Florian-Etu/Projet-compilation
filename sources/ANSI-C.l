D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]


%{
#include <stdio.h>
#include "TestLex.h"

void comment();

%}

%option yylineno
%%
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] {printf("Detection d'un commentaire ligne %d\n", yylineno);}
[/][*]    {yyerror("Commentaire non ferme");}
"auto"                  return AUTO;
"break"                 return BREAK;
"case"                  return CASE;
"char"                  return CHAR;
"const"                 return CONST;
"continue"              return CONTINUE;
"default"               return DEFAULT;
"do"                    return DO;
"double"                return DOUBLE;
"else"                  return ELSE;
"enum"                  return ENUM;
"extern"                return EXTERN;
"float"                 return FLOAT;
"for"                   return FOR;
"goto"                  return GOTO;
"if"                    return IF;
"int"                   return INT;
"long"                  return LONG;
"register"              return REGISTER;
"return"                return RETURN;
"short"                 return SHORT;
"signed"                return SIGNED;
"sizeof"                return SIZEOF;
"static"                return STATIC;
"struct"                return STRUCT;
"switch"                return SWITCH;
"typedef"               return TYPEDEF;
"union"                 return UNION;
"unsigned"              return UNSIGNED;
"void"                  return VOID;
"volatile"              return VOLATILE;
"while"                 return WHILE;

{D}*                    return NUMBER;
{L}({L}|{D})*           return IDENTIFIER;

"="                     return EQ;

";" 			return ';';
"{" 			return '{';
"}" 			return '}';
"(" 			return '(';
")" 			return ')';

[ \r\t\n]+           	;
"&&"                    return AND_OP;
"||"                    return OR_OP;
"<="                    return LE_OP;
">="                    return GE_OP;
"=="                    return EQ_OP;
"!="                    return NE_OP;

.                       {yyerror("Caractere non reconnu");};
%%

int yywrap(void)
{
  return 1;
}

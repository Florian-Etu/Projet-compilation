D                       [0-9]
L                       [a-zA-Z_]


%{
#include <stdio.h>
#include "y.tab.h"

int yylex();
extern void yyerror(char *s);
%}

%option yylineno
%%
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] {printf("Detection d'un commentaire (ignore pour l'analyse syntaxique) ligne %d\n", yylineno);}
[/][*]    {yyerror("Commentaire non ferme");}
"extern"                return EXTERN;
"goto"                  return GOTO;
"if"                    return IF;
"int"                   return INT;
"return"                return RETURN;
"void"                  return VOID;

[-]?{D}*                return CONSTANT;
[-]?{L}({L}|{D})*           return IDENTIFIER;

[+-/&;\{\}\[\]\(\)\<\>,.:!~%^|?\*=] return *yytext;

[ \r\t\n]+        ;

"<="    return LE_OP;
">="    return GE_OP;
"=="    return EQ_OP;
"!="    return NE_OP;

.       yyerror("Detection d'un caractere invalide");
%%

int yywrap(void)
{
  return 1;
}
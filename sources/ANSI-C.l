D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
E                       [Ee][+-]?{D}+
FS                      (f|F|l|L)
IS                      (u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"

/* Ne gère pas les commentaires. A rajouter */
/* Supprimer les lignes dont vous n'avez pas besoin. */

%}

%%
"/*"			{ comment(); }

"auto"                  {return AUTO;}
"break"                 {return BREAK;}
"case"                  {return CASE;}
"char"                  {return CHAR;}
"const"                 {return CONST;}
"continue"              {return CONTINUE;}
"default"               {return DEFAULT}
"do"                    {return DO;}
"double"                {return DOUBLE;}
"else"                  {return ELSE;}
"enum"                  {return ENUM;}
"extern"                {return EXTERN;}
"float"                 {return FLOAT;}
"for"                   {return FOR;}
"goto"                  {return GOTO;}
"if"                    {return IF;}
"int"                   {return INT;}
"long"                  {return LONG;}
"register"              {return REGISTER;}
"return"                {return RETURN;}
"short"                 {return SHORT;}
"signed"                {return SIGNED;}
"sizeof"                {return SIZEOF;}
"static"                {return STATIC;}
"struct"                {return STRUCT;}
"switch"                {return SWITCH;}
"typedef"               {return TYPEDEF;}
"union"                 {return UNION;}
"unsigned"              {return UNSIGNED;}
"void"                  {return VOID;}
"volatile"              {return VOLATILE;}
"while"                 {return WHILE;}

{L}({L}|{D})*           {return IDENTIFIER;}

0[xX]{H}+{IS}?          { /* A completer */ }
0{D}+{IS}?              { /* A completer */ }
{D}+{IS}?               { /* A completer */ }
L?'(\\.|[^\\'])+'       { /* A completer */ }

{D}+{E}{FS}?            { /* A completer */ }
{D}*"."{D}+({E})?{FS}?  { /* A completer */ }
{D}+"."{D}*({E})?{FS}?  { /* A completer */ }

L?\"(\\.|[^\\"])*\"     { /* A completer */ }

"..."                   { /* A completer */ }
">>="                   { /* A completer */ }
"<<="                   { /* A completer */ }
"+="                    { /* A completer */ }
"-="                    { /* A completer */ }
"*="                    { /* A completer */ }
"/="                    { /* A completer */ }
"%="                    { /* A completer */ }
"&="                    { /* A completer */ }
"^="                    { /* A completer */ }
"|="                    { /* A completer */ }
">>"                    { /* A completer */ }
"<<"                    { /* A completer */ }
"++"                    { /* A completer */ }
"--"                    { /* A completer */ }
"->"                    { /* A completer */ }
"&&"                    {return (AND_OP);}
"||"                    {return (OR_OP);}
"<="                    {return (LE_OP);}
">="                    {return (GE_OP);}
"=="                    {return (EQ_OP);}
"!="                    {return (NE_OP);}

[ \t\v\n\f]             { /* A completer */ }
.                       {return yytext[0];}
%%

void comment()
{
	int c;

	while ((c = input()) != 0) {
		if (c == '*') {
			while ((c = input()) == '*') ;
			if (c == '/') return;
			if (c == 0) break;
		}
	}
	yyerror("unterminated comment\n");
}

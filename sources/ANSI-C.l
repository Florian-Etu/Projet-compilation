D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
S			[ \t\v\n\f\s\r]

%{
#include <stdio.h>
#include "TestLex.h"

void comment();
void comptposition(void);

int col = 1;
int prevCol = 1;
int line = 1;

%}

%%
"/*"			{ comment(); }
"auto"                  { comptposition(); return AUTO; }
"break"                 { comptposition();return BREAK; }
"case"                  { comptposition();return CASE; }
"char"                  { comptposition();return CHAR; }
"const"                 { comptposition(); return CONST; }
"continue"              { comptposition(); return CONTINUE; }
"default"               { comptposition(); return DEFAULT; }
"do"                    { comptposition(); return DO; }
"double"                { comptposition(); return DOUBLE; }
"else"                  { comptposition(); return ELSE; }
"enum"                  { comptposition(); return ENUM; }
"extern"                { comptposition(); return EXTERN; }
"float"                 { comptposition(); return FLOAT; }
"for"                   { comptposition(); return FOR; }
"goto"                  { comptposition(); return GOTO; }
"if"                    { comptposition(); return IF; }
"int"                   { comptposition(); return INT; }
"long"                  { comptposition(); return LONG; }
"register"              { comptposition(); return REGISTER; }
"return"                { comptposition(); return RETURN; }
"short"                 { comptposition(); return SHORT; }
"signed"                { comptposition(); return SIGNED; }
"sizeof"                { comptposition(); return SIZEOF; }
"static"                { comptposition(); return STATIC; }
"struct"                { comptposition(); return STRUCT; }
"switch"                { comptposition(); return SWITCH; }
"typedef"               { comptposition(); return TYPEDEF; }
"union"                 { comptposition(); return UNION; }
"unsigned"              { comptposition(); return UNSIGNED; }
"void"                  { comptposition(); return VOID; }
"volatile"              { comptposition(); return VOLATILE; }
"while"                 { comptposition(); return WHILE; }

{D}*                    { comptposition(); return NUMBER; }
{L}({L}|{D})*           { comptposition(); return IDENTIFIER; }

"="                     { comptposition(); return EQ; }

";"								{ comptposition(); return(';'); }
("{")								{ comptposition(); return('{'); }
("}")								{ comptposition(); return('}'); }
("[")								{ comptposition(); return('['); }
("]")								{ comptposition(); return(']'); }
"("								{ comptposition(); return('('); }
")"								{ comptposition(); return(')'); }




"&"								{ comptposition(); return('&'); }
"*"								{ comptposition(); return('*'); }
"-"								{ comptposition(); return('-'); }
"/"								{ comptposition(); return('/'); }
"+"								{ comptposition(); return('+'); }
"<"								{ comptposition(); return('<'); }
">"								{ comptposition(); return('>'); }
","								{ comptposition(); return(','); }
"."								{ comptposition(); return('.'); }
":"								{ comptposition(); return(':'); }


"!"								{ comptposition(); return('!'); }
"~"								{ comptposition(); return('~'); }
"%"								{ comptposition(); return('%'); }
"^"								{ comptposition(); return('^'); }
"|"								{ comptposition(); return('|'); }
"?"								{ comptposition(); return('?'); }




"&&"                    return AND_OP;
"||"                    return OR_OP;
"<="                    return LE_OP;
">="                    return GE_OP;
"=="                    return EQ_OP;
"!="                    return NE_OP;

{S}+								{comptposition();}

.                       {printf("Caractere non reconnu à la ligne : %d, colonne : %d \n", line, col);}
%%

int yywrap(void)
{
  return 1;
}

void comment()
{
	int c;
	int startLine = line, startCol = prevCol;
	while (c = input())
	{
		if (c == '*')
		{
			while ((c = input()) == '*') ;
			if (c == '/') return;
			prevCol = col;
			if (c == 0) break;
		}

		if (c == '\n')
		{
			col = 1;
			line++;
		}

		else if (c == '\t')
		{
			col += 4;
		}
		else
		{
			col++;
		}
	}
	printf("Commentaire non ferme à la ligne : %d, colonne : %d \n", startLine,startCol);
}

void comptposition(void)
{
	int i;
	for (i = 0; yytext[i] != '\0'; i++)
	{
		prevCol = col;
		if (yytext[i] == '\n')
		{
			col = 1;
			line++;
		}
		else if (yytext[i] == '\t')
		{
			col += 4;
		}
		else
		{
			col++;
		}
	}

}

D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
S						[ \t\v\n\f\s\r]

%{
#include <stdio.h>
#include "y.tab.h"

void comment();
void comptposition(void);

int col = 1;
int prevCol = 1;
int line = 1;

%}

%%
"/*"					{ comment(); }
"else"                  { comptposition(); return ELSE; }

"extern"                { comptposition(); return EXTERN; }
"for"                   { comptposition(); return FOR; }
"if"                    { comptposition(); return IF; }
"int"                   { comptposition(); return INT; }
"return"                { comptposition(); return RETURN; }
"sizeof"                { comptposition(); return SIZEOF; }
"struct"                { comptposition(); return STRUCT; }
"void"                  { comptposition(); return VOID; }
"while"                 { comptposition(); return WHILE; }

{D}*                    { comptposition(); return CONSTANT; }
{L}({L}|{D})*           { comptposition(); return IDENTIFIER; }

"="                     { comptposition(); return EQ; }

";"						{ comptposition(); return(';'); }
("{")					{ comptposition(); return('{'); }
("}")					{ comptposition(); return('}'); }
("[")					{ comptposition(); return('['); }
("]")					{ comptposition(); return(']'); }
"("						{ comptposition(); return('('); }
")"						{ comptposition(); return(')'); }




"&"						{ comptposition(); return('&'); }
"*"						{ comptposition(); return STAR; }
"-"						{ comptposition(); return MINUS; }
"/"						{ comptposition(); return SLASH; }
"+"						{ comptposition(); return PLUS; }
"<"						{ comptposition(); return('<'); }
">"						{ comptposition(); return('>'); }
","						{ comptposition(); return(','); }
"."						{ comptposition(); return('.'); }
":"						{ comptposition(); return(':'); }


"!"						{ comptposition(); return('!'); }
"~"						{ comptposition(); return('~'); }
"%"						{ comptposition(); return('%'); }
"^"						{ comptposition(); return('^'); }
"|"						{ comptposition(); return('|'); }
"?"						{ comptposition(); return('?'); }



"->"                    return PTR_OP;
"&&"                    return AND_OP;
"||"                    return OR_OP;
"<="                    return LE_OP;
">="                    return GE_OP;
"=="                    return EQ_OP;
"!="                    return NE_OP;

{S}+					{comptposition();}

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

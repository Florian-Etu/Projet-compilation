D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
S						[ \t\v\n\f\s\r]

%{
#include <stdio.h>
#include "y.tab.h"
#include "symbtab.h"
void comment();

%}

%option yylineno

%%
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] {printf("Detection d'un commentaire ligne %d\n", yylineno);}
[/][*]    { printf("Commentaire non ferme ligne %d\n", yylineno); }
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

{D}*                  {yylval.val = yytext; return CONSTANT; }
{L}({L}|{D})*         {yylval.var = add(yytext); return IDENTIFIER; }

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

.                       {printf("Echec analyse lexicale ligne %d \n", yylineno);};

%%

int yywrap(void)
{
  return 1;
}


int hash( char *name ) {
  int i, r;
  int taille = strlen(name);
  r = 0;
  for ( i = 0; i < MAXSYMB; i++ )
    r = ((r << 8) + name[i]) % MAXSYMB;
  return r;
}

void reset() {
  int i;
  for( i = 0; i < MAXSYMB; i++ )
    table[i] = NULL;
}

symbtab * add( char *name ) {
  int h;
  symbtab *s;
  symbtab *precedent;
  h = hash(name);
  s = table[h];
  precedent = NULL;
  while ( s != NULL ) {
    if ( strcmp( s->name, name ) == 0 )
      return s;
    precedent = s;
    s = s->next;
  }
  if ( precedent == NULL ) {
    table[h] = (symbtab *) malloc(sizeof(symbtab));
    s = table[h];
  }
  else {
    precedent->next = (symbtab *) malloc(sizeof(symbtab));
    s = precedent->next;
  }
  s->name = strdup(name);
  s->next = NULL;
  return s;
}

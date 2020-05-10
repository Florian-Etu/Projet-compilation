D                       [0-9]
L                       [a-zA-Z_]

%{
#include "y.tab.h"
#include "symbtab.h"
#define ID_TYPE 0
#define INT_TYPE 1

extern size_t strlen( const char * theString );
extern char* strdup(const char*);
%}

%option yylineno

%%
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] {printf("Detection d'un commentaire (ignore pour l'analyse syntaxique) ligne %d\n", yylineno); fprintf(yyout, "%s\n", yytext);}
[/][*]    {yyerror("Commentaire non ferme");}
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

{D}*                  {yylval.symbolValue = addTS(yytext, INT_TYPE); return CONSTANT;}
{L}({L}|{D})*         {yylval.symbolValue = addTS(yytext, ID_TYPE); return IDENTIFIER;}

"="     return EQ;

[;\{\}\[\]\(\)\<\>,.:!~%^|?&] return *yytext;
"*"			return STAR;
"-"			return MINUS; 
"/"			return SLASH; 
"+"			return PLUS;

[ \r\t\n]+           	;

"->"      return PTR_OP;
"&&"      return AND_OP;
"||"      return OR_OP;
"<="      return LE_OP;
">="      return GE_OP;
"=="      return EQ_OP;
"!="      return NE_OP;

">>"			return SHIFTRIGHT_OP;
"<<"			return SHIFTLEFT_OP;
"++"			return INC_OP;
"--"			return DEC_OP;

.         yyerror("Detection d'un caractere invalide");


%%

int yywrap(void)
{
  return 1;
}


int hash(char *name) {
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

tablesymboles* addTS(char* name, int type) {
  int h;
  tablesymboles *s;
  tablesymboles *precedent;
  h = hash(name);
  s = table[h];
  precedent = NULL;
  while (s != NULL) {
    if ( strcmp( s->name, name ) == 0 )
      return s;
    precedent = s;
    s = s->suivant;
  }
  if ( precedent == NULL ) {
    table[h] = (tablesymboles*) malloc(sizeof(tablesymboles));
    s = table[h];
  }
  else {
    precedent->suivant = (tablesymboles*) malloc(sizeof(tablesymboles));
    s = precedent->suivant;
  }
  s->name = strdup(name);
  s->type = type;
  s->suivant = NULL;
  return s;
}

char* nomTable(tablesymboles* symbolTable) {
  return symbolTable->name;
}

void affichageTable(tablesymboles* symbolTable) {
  printf("Affichage table des symboles : name = %s, type = %d, val = %d, suivant = %p\n",symbolTable->name, symbolTable->type, symbolTable->val, symbolTable->suivant);
}
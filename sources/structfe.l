D                       [0-9]
L                       [a-zA-Z_]

%{
#include "y.tab.h"
#include "symbtab.h"
#define MAXBLOCIMBRIQUE 50

extern size_t strlen( const char * theString );
extern char* strdup(const char*);
extern void yyerror(char *s);

int yylex();
int majLigneBloc(int typeBloc);
int getLineNumber();
void affectation(tablesymboles* destination, tablesymboles* valeur);

int compteurGoto = 1; //Compteur goto pour avoir un id unique à chaque goto
char* nomDestination; //Nom du fichier yyout
int blocO[MAXBLOCIMBRIQUE]; //Numéro de lignes des blocs ouvrants imbriqués
int nblocO = -1; //Nombre de blocs ouvrants imbriqués
%}

%option yylineno

%%
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] {printf("Detection d'un commentaire (ignore pour l'analyse syntaxique) ligne %d\n", yylineno); fprintf(yyout, "%s\n", yytext);}
[/][*]    {yyerror("Commentaire non ferme");}
"else"                 {fprintf(yyout, "Lelse%d:\n{\n", compteurGoto-1); majLigneBloc(0); return ELSE;}
"extern"               {fprintf(yyout, "extern "); return EXTERN;}
"for"                  return FOR;
"if"                   return IF;
"int"                  return INT;
"return"               return RETURN;
"sizeof"               return SIZEOF;
"struct"               return STRUCT;
"void"                 return VOID;
"while"                return WHILE;

{D}*                  {yylval.symbolValue = addDTS(yytext); return CONSTANT;}
{L}({L}|{D})*         {yylval.symbolValue = addTS(yytext);  return IDENTIFIER;}

"="     return EQ;

[;\{\}\[\]\(\)\<\>,.:!~%^|?&] return *yytext;
"*"			return STAR;
"-"			{yylval.symbolValue = addTS("MINUS"); return MINUS;}
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


unsigned int hash(char *name) {
  unsigned int Code = 0;
  size_t const len = strlen (name);
  size_t i;
   for (i = 0; i < len; i++)
   {
      Code = name[i] + 31 * Code;
   }
   return Code % MAXSYMB;
}

void reset() {
  int i;
  for( i = 0; i < MAXSYMB; i++ )
    table[i] = NULL;
}

tablesymboles* addTS(char* name) {
  int h;
  tablesymboles *s;
  tablesymboles *precedent;
  h = hash(name);
  s = table[h];
  precedent = NULL;
  while (s != NULL) {
    if (strcmp(s->name, name ) == 0 )
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
  s->suivant = NULL;
  return s;
}

tablesymboles* addDTS(char* name) {
  tablesymboles* TS = addTS(name);
  TS->val=atoi(name);
  return TS;
}

tablesymboles* findTS(char* id) {
  tablesymboles *s;
  s = table[hash(id)];
  while (s != NULL) {
    if (strcmp(s->name, id) == 0 )
      return s;
    s = s->suivant;
  }
  return NULL;
}

void affichageTable(tablesymboles* symbolTable) {
  printf("Affichage table des symboles : name = %s, type = %d, val = %d, suivant = %p\n",symbolTable->name, symbolTable->type, symbolTable->val, symbolTable->suivant);
}

void affectation(tablesymboles* destination, tablesymboles* valeur) {
  if(destination->type == 2 && valeur->type == 0) {
    destination->val=atoi(valeur->name);
    printf("La valeur %d a bien ete affectee a la variable %s\n", destination->val, destination->name);
  }
}
	
int getLineNumber()
{
    fflush(yyout);
    FILE *fileptr;
    int count_lines = 0;
    fileptr = fopen(nomDestination, "r");
    char chr = getc(fileptr);
    while (chr != EOF)
    {
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        chr = getc(fileptr);
    }
    fclose(fileptr);
    return count_lines;
}

/* La fonction suivante permet de retenir les données relatives au début / fin de blocs afin d'écrire les déclarations de variables en début de bloc 
Le paramètre prend 0 si c'est un début de bloc, 1 si c'est une fin de bloc  */
int majLigneBloc(int typeBloc) { 
        if(typeBloc) {
                if(nblocO>0) {
                nblocO--;
                }
                return 1;
        }
        else {
                nblocO++;
                blocO[nblocO] = getLineNumber();
                return 0;
        }
}
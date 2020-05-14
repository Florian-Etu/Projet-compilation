%{
#include <stdio.h>
#include <stdlib.h>
#include "symbtab.h"
#include <ctype.h>
#define MAXSIZEVARTEMP 50
	
void yyerror(char *s);
char *createTemp();
void inserttext(int ligne, char* texte);
int istemp(char *s);
char* nomFichierDestination(char *nom);
char *substring(char *string, int position, int length);
char* concat(const char *s1, const char *s2);
int isnumber(char *s);
void declaration(char* nomVariable);

extern int yylineno;
extern int compteurGoto;
extern FILE *yyin;
extern FILE *yyout;
extern char* nomDestination;
extern int blocO[]; //Numéro de lignes des blocs ouvrants imbriqués
extern int nblocO; //Nombre de blocs ouvrants imbriqués

extern int yylex();
extern int majLigneBloc(int typeBloc);
extern int getLineNumber();
extern void affectation(tablesymboles* destination, tablesymboles* valeur);
extern char* strdup(const char*);
extern char *strcat(char *destination, const char *source);
extern char * strcpy( char * destination, const char * source ); 
extern size_t strlen( const char * theString );
extern int strcmp(const char *s1, const char *s2);

%}
%union {
        char *nom;
        int entier;
        int type;
	struct tablesymboles* symbolValue;
}

%token PTR_OP LE_OP GE_OP EQ_OP NE_OP SHIFTRIGHT_OP SHIFTLEFT_OP
%token EQ
%token AND_OP OR_OP
%token EXTERN
%token <type> VOID
%token <symbolValue> STRUCT SIZEOF
%token IF ELSE WHILE FOR RETURN
%token <symbolValue> PLUS MINUS STAR SLASH INC_OP DEC_OP
%token <type> IDENTIFIER
%token <entier> CONSTANT
%token <type> INT
%token <symbolValue> '&'

%left PLUS MINUS
%left STAR SLASH

%type <symbolValue> multiplicative_expression additive_expression relational_expression direct_declarator declarator shift_expression equality_expression logical_and_expression logical_or_expression unary_expression postfix_expression primary_expression expression type_specifier struct_specifier unary_operator
%type <nom> argument_expression_list

%start program
%%

primary_expression
        : IDENTIFIER {$$->type = ID_TYPE;}
        | CONSTANT {$$->type = INT_TYPE;}
        | '(' expression ')' {$$ = $2;}
        ;

postfix_expression
        : primary_expression 
        | postfix_expression '(' ')'
        | postfix_expression '(' argument_expression_list ')' {fprintf(yyout, "%s(%s);\n", $1->name, $3);}
        | postfix_expression '.' IDENTIFIER
        | postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP {fprintf(yyout,"%s = %s + 1 ;\n", $1->name, $1->name);}
	| postfix_expression DEC_OP {fprintf(yyout,"%s = %s - 1 ;\n", $1->name, $1->name);}
        ;

argument_expression_list
        : expression {$$=$1->name;}
        | argument_expression_list ',' expression {$$ = concat(concat($1, ","), $$);}
        ;

unary_expression
        : postfix_expression
        | unary_operator unary_expression {if(strcmp($1->name, "MINUS")==0) {$$->name=concat("-", $2->name);}}
	| INC_OP unary_expression {fprintf(yyout,"%s = %s + 1 ;\n", $2->name, $2->name); fprintf(yyout,"%s = %s ;\n", $$->name, $2->name);}
	| DEC_OP unary_expression {fprintf(yyout,"%s = %s - 1 ;\n", $2->name, $2->name); fprintf(yyout,"%s = %s ;\n", $$->name, $2->name);}
        | SIZEOF unary_expression
	| SIZEOF '(' type_specifier ')'
        ;

unary_operator
        : '&'
        | STAR
        | MINUS
        ;

multiplicative_expression
        : unary_expression
        | multiplicative_expression STAR unary_expression {char* temp=$1->name; $$->name=createTemp(); declaration($$->name); fprintf(yyout,"%s = %s * %s ;\n", $$->name, temp, $3->name);}



        | multiplicative_expression SLASH unary_expression {char* temp=$1->name; $$->name=createTemp(); declaration($$->name); fprintf(yyout,"%s = %s / %s ;\n", $$->name, temp, $3->name);}
        ;

additive_expression
        : multiplicative_expression
        | additive_expression PLUS multiplicative_expression {char* temp=$1->name; $$->name=createTemp(); declaration($$->name); fprintf(yyout,"%s = %s + %s ;\n", $$->name, temp, $3->name);}
        | additive_expression MINUS multiplicative_expression {char* temp=$1->name; $$->name=createTemp(); declaration($$->name); fprintf(yyout,"%s = %s - %s ;\n", $$->name, temp, $3->name);}
        ;

shift_expression
		: additive_expression 
		| shift_expression SHIFTRIGHT_OP additive_expression {if(isnumber($3->name))
									{	
										int l = atoi($3->name);
										char* leftid=$1->name;
										char* prevtemp;
										$$->name=createTemp();
                                                                                declaration($$->name);
										fprintf(yyout,"%s = %s / 2 ;\n", $$->name, leftid);
                                                                                int i;
										for (i =0; i<(l-1) ; i++)
										{
											prevtemp=$$->name;
											$$->name=createTemp();
                                                                                        declaration($$->name);
											fprintf(yyout,"%s = %s / 2 ;\n", $$->name, prevtemp);
										}
									}}
										

		| shift_expression SHIFTLEFT_OP additive_expression  {if(isnumber($3->name))
									{	
										int l = atoi($3->name);
										char* leftid=$1->name;
										char* prevtemp;
										$$->name=createTemp();
                                                                                declaration($$->name);
										fprintf(yyout,"%s = %s * 2 ;\n", $$->name, leftid);
                                                                                int i;
										for (i =0; i<(l-1) ; i++)
										{
											prevtemp=$$->name;
											$$->name=createTemp();
                                                                                        declaration($$->name);
											fprintf(yyout,"%s = %s * 2 ;\n", $$->name, prevtemp);
										}
									}}
		;

relational_expression
        : shift_expression 
        | relational_expression '<' shift_expression {printf("%s < %s (ligne %d) ;\n", $1->name,  $3->name, yylineno); fprintf(yyout, "if (%s>=%s) goto Lelse%d;\n{\n", $1->name, $3->name, compteurGoto); compteurGoto++; majLigneBloc(0);}
        | relational_expression '>' shift_expression {printf("%s > %s (ligne %d) ;\n", $1->name,  $3->name, yylineno) ; fprintf(yyout, "if (%s<=%s) goto Lelse%d;\n{\n", $1->name, $3->name, compteurGoto); compteurGoto++; majLigneBloc(0);}
        | relational_expression LE_OP shift_expression {printf("%s <= %s (ligne %d) ;\n", $1->name,  $3->name, yylineno); fprintf(yyout, "if (%s>%s) goto Lelse%d;\n{\n", $1->name, $3->name, compteurGoto); compteurGoto++; majLigneBloc(0);} 
        | relational_expression GE_OP shift_expression {printf("%s >= %s (ligne %d) ;\n", $1->name,  $3->name, yylineno); fprintf(yyout, "if (%s<%s) goto Lelse%d;\n{\n", $1->name, $3->name, compteurGoto); compteurGoto++; majLigneBloc(0);}
        ;

equality_expression
        : relational_expression
        | equality_expression EQ_OP relational_expression {printf("%s == %s (ligne %d) ;\n", $1->name,  $3->name, yylineno); fprintf(yyout, "if (%s!=%s) goto Lelse%d;\n{\n", $1->name, $3->name, compteurGoto); compteurGoto++; majLigneBloc(0);}
        | equality_expression NE_OP relational_expression {printf("%s != %s (ligne %d) ;\n", $1->name,  $3->name, yylineno); printf("Type 1 : %d Type 2 : %d (0 = INT, 1 = VOID, 2 = ID)\n", $1->type, $3->type); fprintf(yyout, "if (%s==%s) goto Lelse%d;\n{\n", $1->name, $3->name, compteurGoto); compteurGoto++; majLigneBloc(0);}
        ;

logical_and_expression 
        : equality_expression
        | logical_and_expression AND_OP equality_expression {printf("%s && %s (ligne %d) ;\n", $1->name,  $3->name, yylineno) ;  }
        ;

logical_or_expression
        : logical_and_expression
        | logical_or_expression OR_OP logical_and_expression {printf("%s || %s (ligne %d) ;\n", $1->name,  $3->name, yylineno);}
        ;

expression
        : logical_or_expression 
        | unary_expression EQ expression {if (strcmp($1->name,$3->name))
						{
							fprintf(yyout,"%s = %s;\n", $1->name, $3->name); 
							affectation($1, $3); 
							$$=$1;
						}
					}
        ;

declaration
        : declaration_specifiers declarator ';' {fprintf(yyout, ";\n");}
        | struct_specifier ';'
        ;

declaration_specifiers
        : EXTERN type_specifier
        | type_specifier
        ;

type_specifier
        : VOID {$1 = VOID_TYPE; fprintf(yyout,"void ");}
        | INT {$1 = INT_TYPE; fprintf(yyout,"int "); }
        | struct_specifier {$1->type = STRUCT_TYPE;}
        ;

struct_specifier
        : STRUCT IDENTIFIER '{' struct_declaration_list '}'
        | STRUCT '{' struct_declaration_list '}'
        | STRUCT IDENTIFIER
        ;

struct_declaration_list
        : struct_declaration
        | struct_declaration_list struct_declaration
        ;

struct_declaration
        : type_specifier declarator ';'
        ;

declarator
        : STAR direct_declarator {$$=$2;}
        | direct_declarator
        ;

direct_declarator
        : IDENTIFIER {$$->type=ID_TYPE; fprintf(yyout,"%s", $$->name);}
        | '(' declarator ')' {$$=$2;}
        | direct_declarator '(' ACT1 parameter_list ')' {fprintf(yyout, ")");}
        | direct_declarator '(' ACT1 ')' {fprintf(yyout, ")");}
        ;

parameter_list
        : parameter_declaration
        | parameter_list ',' parameter_declaration
        ;

parameter_declaration
        : declaration_specifiers declarator
        ;

statement
        : compound_statement
        | expression_statement
        | if_statement
	| else_statement
        | iteration_statement
        | jump_statement 
        ;

compound_statement
        : '{' ACT2 ACT3 '}'
        | '{' statement_list '}'
        | '{' ACT2 declaration_list ACT3 '}'
        | '{' ACT2 declaration_list statement_list ACT3 '}'
        ;

declaration_list
        : declaration
        | declaration_list declaration
        ;

statement_list
        : statement
        | statement_list statement
        ;

expression_statement
        : ';'
        | expression ';'
        ;
if_statement
        : IF '(' expression ')' statement {fprintf(yyout, "}\n\n"); majLigneBloc(1);}
        ;

else_statement
		: ELSE statement {fprintf(yyout, "}\n\n"); majLigneBloc(1);}
		;

iteration_statement
        : WHILE '(' expression ')' statement
        | FOR '(' expression_statement expression_statement expression ')' statement
        ;

jump_statement
        : RETURN ';' {fprintf(yyout, "return;\n");}
        | RETURN expression ';' {fprintf(yyout, "return %s;\n", $2->name);}
        ;

program
        : external_declaration
        | program external_declaration
        ;

external_declaration
        : function_definition
        | declaration
        ;

function_definition
        : declaration_specifiers declarator compound_statement
        ;

ACT1	: {fprintf(yyout, "(");}; 
ACT2	: {fprintf(yyout, "{\n"); majLigneBloc(0);};
ACT3	: {fprintf(yyout, "}\n"); majLigneBloc(1);}; 
%%
int main(int argc, char* argv[])
{
        if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp) {
			yyin = fp;
                        nomDestination = nomFichierDestination(argv[1]);
                        printf("Generation du fichier : %s\n", nomDestination);
                        yyout = fopen(nomDestination, "w");
                }
                else {
                        printf("Le fichier %s est introuvable (arret du compilateur)\n", argv[1]);
                        exit(1);
                }
	}
        if(!yyparse())
		printf("\nAnalyse syntaxique reussite\n");
	else
		yyerror("\nL'analyse syntaxique a echoue\n");
        fclose(yyin);
        fclose(yyout);
    return 0;
}


char* nomFichierDestination(char *nom)
{
   char *f, *e;
   int length;
   
   length = strlen(nom);

   int position = length-1;
   f = substring(nom, 1, position - 1 );      
   e = substring(nom, position, length-position+1);

   strcpy(nom, "");
   strcat(nom, f);
   free(f);
   strcat(nom, "_3");
   strcat(nom, e);
   free(e);
   return nom;
}

char *substring(char *string, int position, int length)
{
   char *pointer;
   int c;
 
   pointer = malloc(length+1);
   
   if( pointer == NULL )
       exit(EXIT_FAILURE);
 
   for( c = 0 ; c < length ; c++ )
      *(pointer+c) = *((string+position-1)+c);      
       
   *(pointer+c) = '\0';
 
   return pointer;
}

void yyerror (char *s)
{
  fprintf (stderr, "ERREUR : %s (ligne %d)\n", s, yylineno);
}

char* createTemp()
{
        char* t = (char*) malloc(MAXSIZEVARTEMP * sizeof(char));
        sprintf(t, "t1");
        int compteur=1;
	while(findTS(t)!=NULL) {
                sprintf(t, "t%d", compteur);
                compteur++;
        }
        addTS(t);
	return  t;
}

int istemp(char *s)
{ 
    char * temps = "Z";
    if(s[0] == temps[0]){
        return 1;
    }
    else{
        return 0;
    }
}

int isnumber(char *s)
{
	int l= strlen(s);
        int i;
	for(i =0; i< l; i++)
	{
		if(!isdigit(s[i]))
		{
			return 0;
		}
	}
	return 1;
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); 
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void inserttext(int ligne, char* texte)
{
    fclose(yyout);
    ligne--;
    FILE *file1,*file2;
    char *t = texte;
    int l,i,r,y,n,index,nl=0;
    int linelength = 0;;
    long offset = 0;

    char *f = nomDestination;
        file1=fopen(f, "r+");
        file2=fopen("f2", "w+");
        fclose(file1);
        fclose(file2);

            file1=fopen(f, "r+");
            file2=fopen("f2", "w+");
            l = ligne;

            while((r=fgetc(file1))!=EOF)
            {
                fputc(r,file2);
                if(r == '\n' && ++nl == l){
                    offset = ftell ( file1);
                    while ( ( r = fgetc ( file1)) != '\n' && r != EOF) {
                        linelength++;
                    }
                    fseek ( file1, offset, SEEK_SET);
                    index = linelength;

                    while ( index) {
                        r = fgetc ( file1);
                        fputc(r,file2);
                        index--;
                    }
                    fprintf(file2, "%s ", t);
                }
            }
            fclose(file1);
            fclose(file2);

            file1=fopen(f, "w+");
            file2=fopen("f2", "r");
            while((y=fgetc(file2))!=EOF){
                    fputc(y,file1);
            }
            fclose(file2);
            fclose(file1);
            remove("f2");
            yyout = fopen(f, "a");
}

void declaration(char* nomVariable) {
        char* temp = (char*) malloc(MAXSIZEVARTEMP * sizeof(char));
        sprintf(temp, "\nint %s;", nomVariable); 
        inserttext(blocO[nblocO], temp); 
}
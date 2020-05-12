%{
#include <stdio.h>
#include <stdlib.h>
#include "symbtab.h"
#include <ctype.h>
	
void yyerror(char *s);
FILE *yyin;
FILE *yyout;

char *createTemp();
int istemp(char *s);
char* nomFichierDestination(char *nom);
char *substring(char *string, int position, int length);


extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;

extern char* strdup(const char*);
extern char *strcat(char *destination, const char *source);
extern char * strcpy( char * destination, const char * source ); 
extern size_t strlen( const char * theString );

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

%start program
%%

primary_expression
        : IDENTIFIER {$$->type = ID_TYPE;  }
        | CONSTANT {$$->type = INT_TYPE;}
        | '(' expression ')' {$$ = $2;}
        ;

postfix_expression
        : primary_expression { $$ = $1 ;}
        | postfix_expression '(' ')'
        | postfix_expression '(' argument_expression_list ')'
        | postfix_expression '.' IDENTIFIER
        | postfix_expression PTR_OP IDENTIFIER
		| postfix_expression INC_OP
		| postfix_expression DEC_OP
        ;

argument_expression_list
        : expression
        | argument_expression_list ',' expression
        ;

unary_expression
        : postfix_expression { $$ = $1 ;}
        | unary_operator unary_expression { if ($1 == MINUS) { $$->val = -$$->val} 
						else if ($1 == STAR) { } 
						else {} }
	| INC_OP unary_expression
	| DEC_OP unary_expression
        | SIZEOF unary_expression
	| SIZEOF '(' type_specifier ')'
        ;

unary_operator
        : '&'
        | STAR
        | MINUS
        ;

multiplicative_expression
        : unary_expression { $$ = $1 ;}
        | multiplicative_expression STAR unary_expression {fprintf(yyout,"%s = %s * %s ;\n", &&=createTemp(), $1, $3);}
        | multiplicative_expression SLASH unary_expression {fprintf(yyout,"%s = %s / %s ;\n", &&=createTemp(), $1, $3);}
        ;

additive_expression
        : multiplicative_expression { $$ = $1 ;}
        | additive_expression PLUS multiplicative_expression {printf("TESTS"); fprintf(yyout,"%s = %s + %s ;\n", &&=createTemp(), $1, $3);}
        | additive_expression MINUS multiplicative_expression {fprintf(yyout,"%s = %s - %s ;\n", &&=createTemp(), $1, $3);}
        ;

shift_expression
		: additive_expression { $$ = $1 ;}
		| shift_expression SHIFTRIGHT_OP additive_expression {fprintf(yyout,"%s = %s >> %s ;\n", &&=createTemp(), $1, $3);}
		| shift_expression SHIFTLEFT_OP additive_expression {fprintf(yyout,"%s = %s << %s ;\n", &&=createTemp(), $1, $3);}
		;

relational_expression
        : shift_expression { $$ = $1 ;}
        | relational_expression '<' shift_expression { fprintf(yyout,"%s < %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno) ;  }
        | relational_expression '>' shift_expression { fprintf(yyout,"%s > %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno) ;  }
        | relational_expression LE_OP shift_expression { fprintf(yyout,"%s <= %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno) ;  }
        | relational_expression GE_OP shift_expression { fprintf(yyout,"%s >= %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno) ;  }
        ;

equality_expression
        : relational_expression { $$ = $1 ;}
        | equality_expression EQ_OP relational_expression { fprintf(yyout,"%s == %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno);}
        | equality_expression NE_OP relational_expression {fprintf(yyout,"%s != %s (ligne %d) ;\n", $1->name,  $3->name, yylineno); printf("Type 1 : %d Type 2 : %d (0 = INT, 1 = VOID, 2 = ID)\n", $1->type, $3->type);}
        ;

logical_and_expression 
        : equality_expression { $$ = $1 ;}
        | logical_and_expression AND_OP equality_expression {fprintf(yyout,"%s && %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno) ;  }
        ;

logical_or_expression
        : logical_and_expression { $$ = $1 ;}
        | logical_or_expression OR_OP logical_and_expression {fprintf(yyout,"%s || %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno);}
        ;

expression
        : logical_or_expression 
        | unary_expression EQ expression {affectation($1, $3); $$=$1;}
        ;

declaration
        : declaration_specifiers declarator ';'
        | struct_specifier ';'
        ;

declaration_specifiers
        : EXTERN type_specifier
        | type_specifier
        ;

type_specifier
        : VOID {$1 = VOID_TYPE;}
        | INT {$1 = INT_TYPE;}
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
        : IDENTIFIER {$$->type=ID_TYPE;}
        | '(' declarator ')' {$$=$2;}
        | direct_declarator '(' parameter_list ')'
        | direct_declarator '(' ')'
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
        : '{' '}'
        | '{' statement_list '}'
        | '{' declaration_list '}'
        | '{' declaration_list statement_list '}'
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
        : IF '(' expression ')' statement
        ;

else_statement
		: ELSE statement
		;

iteration_statement
        : WHILE '(' expression ')' statement
        | FOR '(' expression_statement expression_statement expression ')' statement
        ;

jump_statement
        : RETURN ';'
        | RETURN expression ';'
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

%%
int main(int argc, char* argv[])
{
        if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp) {
			yyin = fp;
                        char* nomDestination = nomFichierDestination(argv[1]);
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

char *createTemp()
{
	char random[6] = "";
	char randomletter;
	int i=0;
	for (i; i < 6; i++){
		randomletter = 'a' + (rand() % 26);
		random[i]=randomletter;
	}

	char *temp_specifier;	
	temp_specifier= strdup("Z");
	return  strcat(temp_specifier, random); 
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

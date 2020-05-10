%{
#include <stdio.h>
#include <stdlib.h>
#include "symbtab.h"
#include <ctype.h>
	
void yyerror(char *s);
	
int tempAmount = 0;
char *createTemp();
int istemp(char *s);
extern int yylineno;

extern char* strdup(const char*);
extern char *strcat(char *destination, const char *source);
extern char * strcpy( char * destination, const char * source ); 
extern size_t strlen( const char * theString );

%}
%union {
	struct tablesymboles* symbolValue;
}

%token PTR_OP LE_OP GE_OP EQ_OP NE_OP SHIFTRIGHT_OP SHIFTLEFT_OP
%token EQ
%token AND_OP OR_OP
%token EXTERN
%token <symbolValue> VOID
%token <symbolValue> STRUCT SIZEOF
%token IF ELSE WHILE FOR RETURN
%token <symbolValue> PLUS MINUS STAR SLASH INC_OP DEC_OP
%token <symbolValue> IDENTIFIER
%token <symbolValue> CONSTANT
%token <symbolValue> INT
%token <symbolValue> '&'

%left PLUS MINUS
%left STAR SLASH

%type <symbolValue> multiplicative_expression additive_expression relational_expression shift_expression equality_expression logical_and_expression logical_or_expression unary_expression postfix_expression primary_expression expression type_specifier struct_specifier unary_operator

%start program
%%

primary_expression
        : IDENTIFIER
        | CONSTANT
        | '(' expression ')' {$$=$2;}
        ;

postfix_expression
        : primary_expression
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
        : postfix_expression
        | unary_operator unary_expression
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
        : unary_expression
        | multiplicative_expression STAR unary_expression
        | multiplicative_expression SLASH unary_expression
        ;

additive_expression
        : multiplicative_expression
        | additive_expression PLUS multiplicative_expression
        | additive_expression MINUS multiplicative_expression
        ;

shift_expression
		: additive_expression
		| shift_expression SHIFTRIGHT_OP additive_expression
		| shift_expression SHIFTLEFT_OP additive_expression
		;

relational_expression
        : shift_expression
        | relational_expression '<' shift_expression { printf("%s < %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno) ;  }
        | relational_expression '>' shift_expression { printf("%s > %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno) ;  }
        | relational_expression LE_OP shift_expression { printf("%s <= %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno) ;  }
        | relational_expression GE_OP shift_expression { printf("%s >= %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno) ;  }
        ;

equality_expression
        : relational_expression
        | equality_expression EQ_OP relational_expression { printf("%s == %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno);}
        | equality_expression NE_OP relational_expression { printf("%s != %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno);}
        ;

logical_and_expression
        : equality_expression
        | logical_and_expression AND_OP equality_expression { printf("%s && %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno) ;  }
        ;

logical_or_expression
        : logical_and_expression
        | logical_or_expression OR_OP logical_and_expression { printf("%s || %s (ligne %d) ;\n", nomTable($1),  nomTable($3), yylineno);}
        ;

expression
        : logical_or_expression
        | unary_expression EQ expression
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
        : VOID
        | INT
        | struct_specifier
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
        : STAR direct_declarator
        | direct_declarator
        ;

direct_declarator
        : IDENTIFIER
        | '(' declarator ')'
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
int main(void)
{
   if(!yyparse())
		printf("\nAnalyse syntaxique reussite\n");
	else
		yyerror("\nL'analyse syntaxique a echoue\n");
    return 0;
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
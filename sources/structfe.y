%{
    	#include <stdio.h>
   	#include <stdlib.h>
	#include "symbtab.h"
	void yyerror(char *s);
%}


%token PTR_OP LE_OP GE_OP EQ_OP NE_OP SHIFTRIGHT_OP SHIFTLEFT_OP
%token EQ
%token AND_OP OR_OP
%token EXTERN
%token VOID
%token STRUCT SIZEOF
%token IF ELSE WHILE FOR RETURN
%token PLUS MINUS STAR SLASH INC_OP DEC_OP

%union {
	int val;
	struct symbtab *var;
}

%token <var> IDENTIFIER
%token <val> CONSTANT
%token <val> INT

%left PLUS MINUS
%left STAR SLASH



%start program
%%

primary_expression
        : IDENTIFIER
        | CONSTANT
        | '(' expression ')'
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
        | relational_expression '<' shift_expression
        | relational_expression '>' shift_expression
        | relational_expression LE_OP shift_expression
        | relational_expression GE_OP shift_expression
        ;

equality_expression
        : relational_expression
        | equality_expression EQ_OP relational_expression
        | equality_expression NE_OP relational_expression
        ;

logical_and_expression
        : equality_expression
        | logical_and_expression AND_OP equality_expression
        ;

logical_or_expression
        : logical_and_expression
        | logical_or_expression OR_OP logical_and_expression
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
#include<ctype.h>

int main(void)
{
   if(!yyparse())
		printf("\nAnalyse syntaxique reussite\n");
	else
		printf("\nL'analyse syntaxique a echoue\n");
    return 0;
}

void yyerror (char *s)
{
  extern int yylineno;
  fprintf (stderr, "line %d : %s\n", yylineno ,s);
}

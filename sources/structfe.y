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
void declarationPointeur(char* nomPointeur);
int sizeoflowcost(int type);

char* conditionFor;
char *actstructdef;

extern int yylineno;
extern int compteurGoto;
extern FILE *yyin;
extern FILE *yyout;
extern char* nomDestination;
extern int blocO[]; //Numéro de lignes des blocs ouvrants imbriqués
extern int nblocO; //Nombre de blocs ouvrants imbriqués
extern int inFor;
extern int compteurFor;
extern int inStruct;
extern int inSizeOf;

extern int yylex();
extern void yyrestart(FILE * input_file );
extern int majLigneBloc(int typeBloc);
extern int getLineNumber();
extern void affectation(tablesymboles* destination, tablesymboles* valeur);
extern char* strdup(const char*);
extern char *strcat(char *destination, const char *source);
extern char * strcpy( char * destination, const char * source ); 
extern size_t strlen( const char * theString );
extern int strcmp(const char *s1, const char *s2);


int offset=0;
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
%token <symbolValue> IDENTIFIER
%token <entier> CONSTANT
%token <type> INT
%token <symbolValue> '&'

%left PLUS MINUS
%left STAR SLASH

%type <symbolValue> multiplicative_expression additive_expression relational_expression direct_declarator declarator shift_expression equality_expression logical_and_expression logical_or_expression unary_expression postfix_expression primary_expression expression type_specifier struct_specifier unary_operator expression_statement declaration_specifiers
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
        | postfix_expression '(' argument_expression_list ')' {if(!inSizeOf){fprintf(yyout, "%s(%s);\n", $1->name, $3);} inSizeOf=0;}
        | postfix_expression '.' IDENTIFIER

        | postfix_expression PTR_OP IDENTIFIER {char* namestruct = (char*) malloc(MAXSIZEVARTEMP * sizeof(char));
						sprintf(namestruct,"struct_%s_%s_offset",actstructdef,$3->name);
						printf("%s",namestruct);
						tablesymboles *s = findTS(namestruct);
						int val = s->val;
						char* temp = (char*) malloc(MAXSIZEVARTEMP * sizeof(char));
						temp = $1->name;
						$$->name=createTemp();
						fprintf(yyout,"void* %s;\n" ,$$->name);
						fprintf(yyout,"%s = %s + %d;\n",$$->name, temp, val);
						}

	| postfix_expression INC_OP {fprintf(yyout,"%s = %s + 1 ;\n", $1->name, $1->name);}
	| postfix_expression DEC_OP {fprintf(yyout,"%s = %s - 1 ;\n", $1->name, $1->name);}
        ;

argument_expression_list
        : expression {$$=$1->name;}
        | argument_expression_list ',' expression {$$ = concat(concat($1, ","), $$);}
        ;

unary_expression
        : postfix_expression
        | unary_operator unary_expression {if(strcmp($1->name, "MINUS")==0) {$$->name=createTemp(); declaration($$->name); fprintf(yyout,"%s = -%s;\n", $$->name, $2->name);}
                                            else if(strcmp($1->name, "STAR")==0) {$$->name=createTemp(); declarationPointeur($$->name); fprintf(yyout,"%s = *%s;\n", $$->name, $2->name);}}
	| INC_OP unary_expression {fprintf(yyout,"%s = %s + 1 ;\n", $2->name, $2->name); fprintf(yyout,"%s = %s ;\n", $$->name, $2->name);}
	| DEC_OP unary_expression {fprintf(yyout,"%s = %s - 1 ;\n", $2->name, $2->name); fprintf(yyout,"%s = %s ;\n", $$->name, $2->name);}
        | SIZEOF unary_expression {sprintf($$->name, "malloc(%lu)", sizeof(int));}
	| SIZEOF '(' type_specifier ')'{sprintf($3->name, "malloc(%lu)", sizeof(int));}
        ;

unary_operator
        : '&'
        | STAR
        | MINUS
        ;

multiplicative_expression
        : unary_expression
        | multiplicative_expression STAR unary_expression {if(inFor) {fprintf(yyout,"%s = %s * %s ;\n", $$->name, $1->name, $3->name);} else{char* temp=$1->name; $$->name=createTemp(); declaration($$->name); fprintf(yyout,"%s = %s * %s ;\n", $$->name, temp, $3->name);}}



        | multiplicative_expression SLASH unary_expression {if(inFor) {fprintf(yyout,"%s = %s / %s ;\n", $$->name, $1->name, $3->name);} else{char* temp=$1->name; $$->name=createTemp(); declaration($$->name); fprintf(yyout,"%s = %s / %s ;\n", $$->name, temp, $3->name);}}
        ;

additive_expression
        : multiplicative_expression
        | additive_expression PLUS multiplicative_expression {if(inFor) {fprintf(yyout,"%s = %s + %s ;\n", $$->name, $1->name, $3->name);} else{char* temp=$1->name; $$->name=createTemp(); declaration($$->name); fprintf(yyout,"%s = %s + %s ;\n", $$->name, temp, $3->name);}}
        | additive_expression MINUS multiplicative_expression {if(inFor) {fprintf(yyout,"%s = %s + %s ;\n", $$->name, $1->name, $3->name);} else{char* temp=$1->name; $$->name=createTemp(); declaration($$->name); fprintf(yyout,"%s = %s - %s ;\n", $$->name, temp, $3->name);}}
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
        | relational_expression '<' shift_expression {
                if(inFor) {
                        sprintf(conditionFor, "Ltest%d:\nif (%s<%s) goto Lfor%d;\n", compteurFor, $1->name,  $3->name, compteurFor);
                }
                else {
                        printf("%s < %s (ligne %d) ;\n", $1->name,  $3->name, yylineno); fprintf(yyout, "\nif (%s>=%s) goto Lelse%d;\n", $1->name, $3->name, compteurGoto); compteurGoto++;}}
        | relational_expression '>' shift_expression {
                if(inFor) {
                        sprintf(conditionFor, "Ltest%d:\nif (%s>%s) goto Lfor%d;\n", compteurFor, $1->name,  $3->name, compteurFor);
                }
                else {
                printf("%s > %s (ligne %d) ;\n", $1->name,  $3->name, yylineno) ; fprintf(yyout, "\nif (%s<=%s) goto Lelse%d;\n", $1->name, $3->name, compteurGoto); compteurGoto++;}}
        | relational_expression LE_OP shift_expression {
                if(inFor) {
                        sprintf(conditionFor, "Ltest%d:\nif (%s<=%s) goto Lfor%d;\n", compteurFor, $1->name,  $3->name, compteurFor);
                }
                else {
                printf("%s <= %s (ligne %d) ;\n", $1->name,  $3->name, yylineno); fprintf(yyout, "\nif (%s>%s) goto Lelse%d;\n", $1->name, $3->name, compteurGoto); compteurGoto++;}}
        | relational_expression GE_OP shift_expression {
                if(inFor) {
                        sprintf(conditionFor, "Ltest%d:\nif (%s>=%s) goto Lfor%d;\n", compteurFor, $1->name,  $3->name, compteurFor);
                }
                else {printf("%s >= %s (ligne %d) ;\n", $1->name,  $3->name, yylineno); fprintf(yyout, "\nif (%s<%s) goto Lelse%d;\n", $1->name, $3->name, compteurGoto); compteurGoto++;}}
        ;

equality_expression
        : relational_expression
        | equality_expression EQ_OP relational_expression { if(inFor) {
                        sprintf(conditionFor, "Ltest%d:\nif (%s==%s) goto Lfor%d;\n", compteurFor, $1->name,  $3->name, compteurFor);
                }
                else {
                printf("%s == %s (ligne %d) ;\n", $1->name,  $3->name, yylineno); fprintf(yyout, "\nif (%s!=%s) goto Lelse%d;\n", $1->name, $3->name, compteurGoto); compteurGoto++;}}
        | equality_expression NE_OP relational_expression {
                if(inFor) {
                        sprintf(conditionFor, "Ltest%d:\nif (%s!=%s) goto Lfor%d;\n", compteurFor, $1->name,  $3->name, compteurFor);
                }
                else {
                printf("%s != %s (ligne %d) ;\n", $1->name,  $3->name, yylineno); printf("Type 1 : %d Type 2 : %d (0 = INT, 1 = VOID, 2 = ID)\n", $1->type, $3->type); fprintf(yyout, "\nif (%s==%s) goto Lelse%d;\n", $1->name, $3->name, compteurGoto); compteurGoto++;}}
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
        : declaration_specifiers declarator ';' {$2->type=$1->type; fprintf(yyout, ";\n");}
        | struct_specifier ';'
        ;

declaration_specifiers
        : EXTERN type_specifier {$$=$2;}
        | type_specifier {$$=$1; printf("Type entree : %d Type Sortie : %d\n",$1->type,$$->type);}
        ;

type_specifier
        : VOID {if(!inSizeOf){$$ = findTS("void");} if (!inStruct) {fprintf(yyout,"void ");}}
        | INT {if(!inSizeOf){$$ = findTS("int");} if (!inStruct && !inSizeOf) {fprintf(yyout,"int "); }}
        | struct_specifier {if (!inStruct) {$$ = findTS("struct") ; $1->type = STRUCT_TYPE;}}
        ;

struct_specifier
        : STRUCT IDENTIFIER '{'ACT4 struct_declaration_list '}' {inStruct=0;offset=0;}
        | STRUCT '{' struct_declaration_list '}'
        | STRUCT IDENTIFIER {if (!inStruct) {fprintf(yyout,"void ");}}
        ;

struct_declaration_list
        : struct_declaration
        | struct_declaration_list struct_declaration
        ;

struct_declaration
        : type_specifier declarator ';' {char* t = (char*) malloc(MAXSIZEVARTEMP * sizeof(char));
					printf("struct_%s_%s de type %d\n",actstructdef,$2->name,$1->type);
					sprintf(t,"struct_%s_%s",actstructdef,$2->name);
					tablesymboles *s1 = addTS(t);
					s1->type = $1->type;	
					char* offsetvar = (char*) malloc(MAXSIZEVARTEMP * sizeof(char));
					sprintf(offsetvar,"struct_%s_%s_offset",actstructdef,$2->name);
					printf("%s\n",offsetvar);
					tablesymboles *s2 = addTS(offsetvar);
					s2->val=offset;
					if($1->type != 3){offset+=sizeoflowcost($1->type);}
					else{(offset+=offset);}
					}
        ;

declarator
        : STAR ACT5 direct_declarator {$$=$3;}
        | direct_declarator
        ;

direct_declarator
        : IDENTIFIER {$$->type=ID_TYPE; if(!inStruct && !inSizeOf){fprintf(yyout,"%s", $$->name);}}
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
        : ';' {}
        | expression ';'
        ;
if_statement
        : IF '(' expression ')' statement {fprintf(yyout, "\n");}
        ;

else_statement
		: ELSE statement {fprintf(yyout, "\n");}
		;

iteration_statement
        : WHILE ACT2 '(' expression ')' statement {inFor=0; fprintf(yyout, "\n%s\n", conditionFor); compteurFor++;}
        | FOR '(' expression_statement ACT2 expression_statement expression ')' ACT3 statement {fprintf(yyout, "\n%s\n", conditionFor); compteurFor++;}
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

ACT1	: {fprintf(yyout, "(");}
ACT2    : {inFor=1; fprintf(yyout, "\ngoto Ltest%d;\n\nLfor%d:\n", compteurFor, compteurFor); conditionFor = (char*) malloc((MAXSIZEVARTEMP+30) * sizeof(char));}
ACT3    : {inFor=0;}
ACT4    : {inStruct=1;
	   actstructdef = (char*) malloc(MAXSIZEVARTEMP * sizeof(char));
	   sprintf(actstructdef,"%s",$<symbolValue>-1->name);}
ACT5	: {if (!inStruct) {fprintf(yyout, "*");}}
%%
int main(int argc, char* argv[])
{
	tablesymboles *s1 = addTS("int");
	s1->type=INT_TYPE;
	tablesymboles *s2 = addTS("void");
	s2->type=VOID_TYPE;
	tablesymboles *s3 = addTS("struct");
	s3->type=STRUCT_TYPE;
        int i;
        if(argc<=1) {
        printf("\n!!!! ATTTENTION : pour generer un fichier traduit le compilateur doit prendre le nom du fichier en argument de la ligne de commande (pas de \"<\" devant le nom du fichier en entree par exemple, se referer au README pour plus d'informations\n\n");
        if(!yyparse())
		printf("\nAnalyse syntaxique reussite\n");
	else
		yyerror("\nL'analyse syntaxique a echoue\n");
        return 0;
        }
        for(i=1; i<argc; i++)
	{
                yylineno=1;
		FILE *fp = fopen(argv[i], "r");
		if(fp) {
			yyin = fp;
                        yyrestart(yyin);
                        nomDestination = nomFichierDestination(argv[i]);
                        printf("Generation du fichier : %s\n", nomDestination);
                        yyout = fopen(nomDestination, "w");
                }
                else {
                        printf("Le fichier %s est introuvable (arret du compilateur)\n", argv[i]);
                        exit(1);
                }
        if(!yyparse())
		printf("\nAnalyse syntaxique reussite\n");
	else
		yyerror("\nL'analyse syntaxique a echoue\n");
        fclose(yyin);
        fclose(yyout);
        }
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

void declarationPointeur(char* nomPointeur) {
        char* temp = (char*) malloc(MAXSIZEVARTEMP * sizeof(char));
        sprintf(temp, "\nint* %s;", nomPointeur); 
        inserttext(blocO[nblocO], temp); 
}


int sizeoflowcost(int type) {
        if(type == 0)
	{return sizeof(int);}
	else if (type == 1 )
	{/*Mettre une erreur*/}
	else if (type == 2 )
	{/*Pas le type des nos ID*/}
	else if (type == 3 )
	{/*Mettre une erreur*/} 
}

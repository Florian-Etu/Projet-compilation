
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     SIZEOF = 260,
     PTR_OP = 261,
     LE_OP = 262,
     GE_OP = 263,
     EQ_OP = 264,
     NE_OP = 265,
     EQ = 266,
     AND_OP = 267,
     OR_OP = 268,
     EXTERN = 269,
     INT = 270,
     VOID = 271,
     STRUCT = 272,
     IF = 273,
     ELSE = 274,
     WHILE = 275,
     FOR = 276,
     RETURN = 277,
     PLUS = 278,
     MINUS = 279,
     STAR = 280,
     SLASH = 281
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define SIZEOF 260
#define PTR_OP 261
#define LE_OP 262
#define GE_OP 263
#define EQ_OP 264
#define NE_OP 265
#define EQ 266
#define AND_OP 267
#define OR_OP 268
#define EXTERN 269
#define INT 270
#define VOID 271
#define STRUCT 272
#define IF 273
#define ELSE 274
#define WHILE 275
#define FOR 276
#define RETURN 277
#define PLUS 278
#define MINUS 279
#define STAR 280
#define SLASH 281




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 18 "structfe.y"

	char *name;
	char type;
	struct symtab *symp;



/* Line 1676 of yacc.c  */
#line 112 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



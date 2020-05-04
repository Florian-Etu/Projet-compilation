/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    SIZEOF = 260,
    PTR_OP = 261,
    LE_OP = 262,
    GE_OP = 263,
    EQ_OP = 264,
    NE_OP = 265,
    SHIFTRIGHT_OP = 266,
    SHIFTLEFT_OP = 267,
    EQ = 268,
    AND_OP = 269,
    OR_OP = 270,
    EXTERN = 271,
    INT = 272,
    VOID = 273,
    STRUCT = 274,
    IF = 275,
    ELSE = 276,
    WHILE = 277,
    FOR = 278,
    RETURN = 279,
    PLUS = 280,
    MINUS = 281,
    STAR = 282,
    SLASH = 283,
    INC_OP = 284,
    DEC_OP = 285
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
#define SHIFTRIGHT_OP 266
#define SHIFTLEFT_OP 267
#define EQ 268
#define AND_OP 269
#define OR_OP 270
#define EXTERN 271
#define INT 272
#define VOID 273
#define STRUCT 274
#define IF 275
#define ELSE 276
#define WHILE 277
#define FOR 278
#define RETURN 279
#define PLUS 280
#define MINUS 281
#define STAR 282
#define SLASH 283
#define INC_OP 284
#define DEC_OP 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "structfe.y" /* yacc.c:1909  */

	char *name;
	char type;
	struct symtab *symp;

#line 120 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

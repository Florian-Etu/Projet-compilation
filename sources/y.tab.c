
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "structfe.y"

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
int isnumber(char *s);

extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;

extern char* strdup(const char*);
extern char *strcat(char *destination, const char *source);
extern char * strcpy( char * destination, const char * source ); 
extern size_t strlen( const char * theString );



/* Line 189 of yacc.c  */
#line 101 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PTR_OP = 258,
     LE_OP = 259,
     GE_OP = 260,
     EQ_OP = 261,
     NE_OP = 262,
     SHIFTRIGHT_OP = 263,
     SHIFTLEFT_OP = 264,
     EQ = 265,
     AND_OP = 266,
     OR_OP = 267,
     EXTERN = 268,
     VOID = 269,
     STRUCT = 270,
     SIZEOF = 271,
     IF = 272,
     ELSE = 273,
     WHILE = 274,
     FOR = 275,
     RETURN = 276,
     PLUS = 277,
     MINUS = 278,
     STAR = 279,
     SLASH = 280,
     INC_OP = 281,
     DEC_OP = 282,
     IDENTIFIER = 283,
     CONSTANT = 284,
     INT = 285
   };
#endif
/* Tokens.  */
#define PTR_OP 258
#define LE_OP 259
#define GE_OP 260
#define EQ_OP 261
#define NE_OP 262
#define SHIFTRIGHT_OP 263
#define SHIFTLEFT_OP 264
#define EQ 265
#define AND_OP 266
#define OR_OP 267
#define EXTERN 268
#define VOID 269
#define STRUCT 270
#define SIZEOF 271
#define IF 272
#define ELSE 273
#define WHILE 274
#define FOR 275
#define RETURN 276
#define PLUS 277
#define MINUS 278
#define STAR 279
#define SLASH 280
#define INC_OP 281
#define DEC_OP 282
#define IDENTIFIER 283
#define CONSTANT 284
#define INT 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 27 "structfe.y"

        char *nom;
        int entier;
        int type;
	struct tablesymboles* symbolValue;



/* Line 214 of yacc.c  */
#line 206 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 218 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNRULES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,     2,
      32,    33,     2,     2,    35,     2,    34,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      36,     2,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    13,    17,    22,    26,
      30,    33,    36,    38,    42,    44,    47,    50,    53,    56,
      61,    63,    65,    67,    69,    73,    77,    79,    83,    87,
      89,    93,    97,    99,   103,   107,   111,   115,   117,   121,
     125,   127,   131,   133,   137,   139,   143,   147,   150,   153,
     155,   157,   158,   161,   163,   169,   174,   177,   179,   182,
     186,   189,   191,   193,   197,   202,   206,   208,   212,   215,
     217,   219,   221,   223,   225,   227,   230,   234,   238,   243,
     245,   248,   250,   253,   255,   258,   264,   267,   273,   281,
     284,   288,   290,   293,   295,   297
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      75,     0,    -1,    28,    -1,    29,    -1,    32,    54,    33,
      -1,    42,    -1,    43,    32,    33,    -1,    43,    32,    44,
      33,    -1,    43,    34,    28,    -1,    43,     3,    28,    -1,
      43,    26,    -1,    43,    27,    -1,    54,    -1,    44,    35,
      54,    -1,    43,    -1,    46,    45,    -1,    26,    45,    -1,
      27,    45,    -1,    16,    45,    -1,    16,    32,    57,    33,
      -1,    31,    -1,    24,    -1,    23,    -1,    45,    -1,    47,
      24,    45,    -1,    47,    25,    45,    -1,    47,    -1,    48,
      22,    47,    -1,    48,    23,    47,    -1,    48,    -1,    49,
       8,    48,    -1,    49,     9,    48,    -1,    49,    -1,    50,
      36,    49,    -1,    50,    37,    49,    -1,    50,     4,    49,
      -1,    50,     5,    49,    -1,    50,    -1,    51,     6,    50,
      -1,    51,     7,    50,    -1,    51,    -1,    52,    11,    51,
      -1,    52,    -1,    53,    12,    52,    -1,    53,    -1,    45,
      10,    54,    -1,    56,    62,    38,    -1,    59,    38,    -1,
      13,    57,    -1,    57,    -1,    14,    -1,    -1,    30,    58,
      -1,    59,    -1,    15,    28,    39,    60,    40,    -1,    15,
      39,    60,    40,    -1,    15,    28,    -1,    61,    -1,    60,
      61,    -1,    57,    62,    38,    -1,    24,    63,    -1,    63,
      -1,    28,    -1,    32,    62,    33,    -1,    63,    32,    64,
      33,    -1,    63,    32,    33,    -1,    65,    -1,    64,    35,
      65,    -1,    56,    62,    -1,    67,    -1,    70,    -1,    71,
      -1,    72,    -1,    73,    -1,    74,    -1,    39,    40,    -1,
      39,    69,    40,    -1,    39,    68,    40,    -1,    39,    68,
      69,    40,    -1,    55,    -1,    68,    55,    -1,    66,    -1,
      69,    66,    -1,    38,    -1,    54,    38,    -1,    17,    32,
      54,    33,    66,    -1,    18,    66,    -1,    19,    32,    54,
      33,    66,    -1,    20,    32,    70,    70,    54,    33,    66,
      -1,    21,    38,    -1,    21,    54,    38,    -1,    76,    -1,
      75,    76,    -1,    77,    -1,    55,    -1,    56,    62,    67,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    57,    58,    62,    63,    64,    65,    66,
      67,    68,    72,    73,    77,    78,    79,    80,    81,    82,
      86,    87,    88,    92,    93,    97,   101,   102,   103,   107,
     108,   125,   143,   144,   145,   146,   147,   151,   152,   153,
     157,   158,   162,   163,   167,   168,   180,   181,   185,   186,
     190,   191,   191,   192,   196,   197,   198,   202,   203,   207,
     211,   212,   216,   217,   218,   219,   223,   224,   228,   232,
     233,   234,   235,   236,   237,   241,   242,   243,   244,   248,
     249,   253,   254,   258,   259,   262,   266,   270,   271,   275,
     276,   280,   281,   285,   286,   290
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PTR_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "SHIFTRIGHT_OP", "SHIFTLEFT_OP", "EQ", "AND_OP", "OR_OP",
  "EXTERN", "VOID", "STRUCT", "SIZEOF", "IF", "ELSE", "WHILE", "FOR",
  "RETURN", "PLUS", "MINUS", "STAR", "SLASH", "INC_OP", "DEC_OP",
  "IDENTIFIER", "CONSTANT", "INT", "'&'", "'('", "')'", "'.'", "','",
  "'<'", "'>'", "';'", "'{'", "'}'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "logical_and_expression", "logical_or_expression", "expression",
  "declaration", "declaration_specifiers", "type_specifier", "$@1",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "declarator", "direct_declarator", "parameter_list",
  "parameter_declaration", "statement", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "if_statement", "else_statement", "iteration_statement",
  "jump_statement", "program", "external_declaration",
  "function_definition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    38,    40,    41,    46,    44,    60,    62,    59,   123,
     125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    42,    43,    43,    43,    43,    43,
      43,    43,    44,    44,    45,    45,    45,    45,    45,    45,
      46,    46,    46,    47,    47,    47,    48,    48,    48,    49,
      49,    49,    50,    50,    50,    50,    50,    51,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      57,    58,    57,    57,    59,    59,    59,    60,    60,    61,
      62,    62,    63,    63,    63,    63,    64,    64,    65,    66,
      66,    66,    66,    66,    66,    67,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     4,     3,     3,
       2,     2,     1,     3,     1,     2,     2,     2,     2,     4,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     3,     2,     2,     1,
       1,     0,     2,     1,     5,     4,     2,     1,     2,     3,
       2,     1,     1,     3,     4,     3,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     4,     1,
       2,     1,     2,     1,     2,     5,     2,     5,     7,     2,
       3,     1,     2,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    50,     0,    51,    94,     0,    49,    53,     0,
      91,    93,    48,    53,    56,     0,    52,     0,    62,     0,
       0,    61,    47,     1,    92,     0,     0,     0,    57,    60,
       0,    46,     0,    95,     0,     0,     0,    55,    58,    63,
       0,     0,     0,     0,     0,     0,    22,    21,     0,     0,
       2,     3,    20,     0,    83,    75,     5,    14,    23,     0,
      26,    29,    32,    37,    40,    42,    44,     0,    79,     0,
      81,    69,     0,     0,    70,    71,    72,    73,    74,    65,
       0,     0,    66,    54,    59,     0,    18,     0,    86,     0,
       0,    89,     0,    16,    17,     0,     0,    10,    11,     0,
       0,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    77,
      80,     0,    76,    82,    68,    64,     0,     0,     0,     0,
       0,    90,     4,     9,     6,     0,    12,     8,    45,    24,
      25,    23,    27,    28,    30,    31,    35,    36,    33,    34,
      38,    39,    41,    43,    78,    67,    19,     0,     0,     0,
       7,     0,    85,    87,     0,    13,     0,    88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    56,    57,   135,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     5,     6,     7,    16,    13,    27,
      28,    20,    21,    81,    82,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     9,    10,    11
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -82
static const yytype_int16 yypact[] =
{
     132,    10,   -82,    46,   -82,   -82,    89,   -82,   -21,     8,
     -82,   -82,   -82,   -82,   -29,    10,   -82,   -17,   -82,    89,
      37,   -12,   -82,   -82,   -82,    10,    89,    15,   -82,   -12,
      28,   -82,   112,   -82,    58,    50,    31,   -82,   -82,   -82,
     299,    34,   215,    55,    57,   232,   -82,   -82,   313,   313,
     -82,   -82,   -82,   313,   -82,   -82,   -82,    36,    84,   313,
      68,   100,   103,    14,    26,    67,   102,    81,   -82,    89,
     -82,   -82,   140,   165,   -82,   -82,   -82,   -82,   -82,   -82,
      89,    19,   -82,   -82,   -82,   268,   -82,   313,   -82,   313,
     249,   -82,    96,   -82,   -82,    63,   109,   -82,   -82,   285,
     137,   313,   -82,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   -82,   139,   -82,
     -82,   190,   -82,   -82,   -82,   -82,   132,   154,   157,   162,
     249,   -82,   -82,   -82,   -82,    24,   -82,   -82,   -82,   -82,
     -82,   -82,    68,    68,   100,   100,   103,   103,   103,   103,
      14,    14,    26,    67,   -82,   -82,   -82,   215,   215,   313,
     -82,   313,   -82,   -82,   166,   -82,   215,   -82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   -82,   -82,    -6,   -82,    43,    66,   -28,    62,
      83,    85,   -82,   -41,   -25,   -31,     1,   -82,     5,   175,
       0,   -13,   185,   -82,    86,   -42,   195,   -82,   148,   -81,
     -82,   -82,   -82,   -82,   -82,   214,   -82
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      88,    69,    12,    80,    92,     8,    30,    68,    23,   130,
      25,    18,    95,    36,     8,    19,    26,    22,   109,   110,
      34,     1,     2,     3,     2,     3,    26,    38,    26,     2,
       3,   123,   113,   114,    86,    38,    26,     8,     4,    96,
       4,    69,    93,    94,    95,     4,   128,   120,   129,   159,
     111,   112,   125,   102,   126,    37,   118,   160,   136,   161,
     138,    39,    97,    98,     2,     3,    87,   124,    99,    84,
     100,     1,     2,     3,    14,    31,    32,     8,   115,   123,
       4,   146,   147,   148,   149,    15,   127,    89,     4,    90,
      83,    79,   103,   104,   101,    80,   132,   139,   140,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   107,   108,    17,   116,   162,   163,    18,   164,   117,
     165,    19,   105,   106,   167,     1,     2,     3,    40,    41,
      42,    43,    44,    45,   131,    46,    47,   133,    48,    49,
      50,    51,     4,    52,    53,     1,     2,     3,   142,   143,
      54,    32,    55,     1,     2,     3,    40,    41,    42,    43,
      44,    45,     4,    46,    47,   137,    48,    49,    50,    51,
       4,    52,    53,   144,   145,   150,   151,    31,    54,    32,
     119,    40,    41,    42,    43,    44,    45,   156,    46,    47,
     157,    48,    49,    50,    51,   158,    52,    53,   152,   166,
      35,   153,    29,    54,    32,   122,    40,    41,    42,    43,
      44,    45,   155,    46,    47,    33,    48,    49,    50,    51,
     121,    52,    53,    24,     0,     0,     0,     0,    54,    32,
     154,    40,    41,    42,    43,    44,    45,     0,    46,    47,
       0,    48,    49,    50,    51,     0,    52,    53,    40,     0,
       0,     0,     0,    54,    32,    46,    47,     0,    48,    49,
      50,    51,     0,    52,    53,    40,     0,     0,     0,     0,
      91,     0,    46,    47,     0,    48,    49,    50,    51,     0,
      52,    53,     2,     3,    40,     0,     0,    54,     0,     0,
       0,    46,    47,     0,    48,    49,    50,    51,     4,    52,
      53,    40,     0,     0,     0,     0,     0,     0,    46,    47,
       0,    48,    49,    50,    51,    40,    52,    53,   134,     0,
       0,     0,    46,    47,     0,    48,    49,    50,    51,    40,
      52,    85,     0,     0,     0,     0,    46,    47,     0,    48,
      49,    50,    51,     0,    52,    53
};

static const yytype_int16 yycheck[] =
{
      42,    32,     1,    34,    45,     0,    19,    32,     0,    90,
      39,    28,    53,    26,     9,    32,    15,    38,     4,     5,
      32,    13,    14,    15,    14,    15,    25,    27,    27,    14,
      15,    73,     6,     7,    40,    35,    35,    32,    30,     3,
      30,    72,    48,    49,    85,    30,    87,    72,    89,   130,
      36,    37,    33,    59,    35,    40,    69,    33,    99,    35,
     101,    33,    26,    27,    14,    15,    32,    80,    32,    38,
      34,    13,    14,    15,    28,    38,    39,    72,    11,   121,
      30,   109,   110,   111,   112,    39,    85,    32,    30,    32,
      40,    33,    24,    25,    10,   126,    33,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     8,     9,    24,    12,   157,   158,    28,   159,    38,
     161,    32,    22,    23,   166,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    38,    23,    24,    28,    26,    27,
      28,    29,    30,    31,    32,    13,    14,    15,   105,   106,
      38,    39,    40,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    30,    23,    24,    28,    26,    27,    28,    29,
      30,    31,    32,   107,   108,   113,   114,    38,    38,    39,
      40,    16,    17,    18,    19,    20,    21,    33,    23,    24,
      33,    26,    27,    28,    29,    33,    31,    32,   115,    33,
      25,   116,    17,    38,    39,    40,    16,    17,    18,    19,
      20,    21,   126,    23,    24,    20,    26,    27,    28,    29,
      72,    31,    32,     9,    -1,    -1,    -1,    -1,    38,    39,
      40,    16,    17,    18,    19,    20,    21,    -1,    23,    24,
      -1,    26,    27,    28,    29,    -1,    31,    32,    16,    -1,
      -1,    -1,    -1,    38,    39,    23,    24,    -1,    26,    27,
      28,    29,    -1,    31,    32,    16,    -1,    -1,    -1,    -1,
      38,    -1,    23,    24,    -1,    26,    27,    28,    29,    -1,
      31,    32,    14,    15,    16,    -1,    -1,    38,    -1,    -1,
      -1,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    26,    27,    28,    29,    16,    31,    32,    33,    -1,
      -1,    -1,    23,    24,    -1,    26,    27,    28,    29,    16,
      31,    32,    -1,    -1,    -1,    -1,    23,    24,    -1,    26,
      27,    28,    29,    -1,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    14,    15,    30,    55,    56,    57,    59,    75,
      76,    77,    57,    59,    28,    39,    58,    24,    28,    32,
      62,    63,    38,     0,    76,    39,    57,    60,    61,    63,
      62,    38,    39,    67,    32,    60,    62,    40,    61,    33,
      16,    17,    18,    19,    20,    21,    23,    24,    26,    27,
      28,    29,    31,    32,    38,    40,    42,    43,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    33,
      56,    64,    65,    40,    38,    32,    45,    32,    66,    32,
      32,    38,    54,    45,    45,    54,     3,    26,    27,    32,
      34,    10,    45,    24,    25,    22,    23,     8,     9,     4,
       5,    36,    37,     6,     7,    11,    12,    38,    62,    40,
      55,    69,    40,    66,    62,    33,    35,    57,    54,    54,
      70,    38,    33,    28,    33,    44,    54,    28,    54,    45,
      45,    45,    47,    47,    48,    48,    49,    49,    49,    49,
      50,    50,    51,    52,    40,    65,    33,    33,    33,    70,
      33,    35,    66,    66,    54,    54,    33,    66
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 56 "structfe.y"
    {(yyval.symbolValue)->type = ID_TYPE;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 57 "structfe.y"
    {(yyval.symbolValue)->type = INT_TYPE;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 58 "structfe.y"
    {(yyval.symbolValue) = (yyvsp[(2) - (3)].symbolValue);}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 67 "structfe.y"
    {fprintf(yyout,"%s = %s + 1 ;\n", (yyvsp[(1) - (2)].symbolValue)->name, (yyvsp[(1) - (2)].symbolValue)->name);}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 68 "structfe.y"
    {fprintf(yyout,"%s = %s - 1 ;\n", (yyvsp[(1) - (2)].symbolValue)->name, (yyvsp[(1) - (2)].symbolValue)->name);}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 79 "structfe.y"
    {fprintf(yyout,"%s = %s + 1 ;\n", (yyvsp[(2) - (2)].symbolValue)->name, (yyvsp[(2) - (2)].symbolValue)->name); fprintf(yyout,"%s = %s ;\n", (yyval.symbolValue)->name, (yyvsp[(2) - (2)].symbolValue)->name);}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 80 "structfe.y"
    {fprintf(yyout,"%s = %s - 1 ;\n", (yyvsp[(2) - (2)].symbolValue)->name, (yyvsp[(2) - (2)].symbolValue)->name); fprintf(yyout,"%s = %s ;\n", (yyval.symbolValue)->name, (yyvsp[(2) - (2)].symbolValue)->name);}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 93 "structfe.y"
    {char* temp=(yyvsp[(1) - (3)].symbolValue)->name; (yyval.symbolValue)->name=createTemp(); fprintf(yyout,"%s = %s * %s ;\n", (yyval.symbolValue)->name, temp, (yyvsp[(3) - (3)].symbolValue)->name);}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 97 "structfe.y"
    {char* temp=(yyvsp[(1) - (3)].symbolValue)->name; (yyval.symbolValue)->name=createTemp(); fprintf(yyout,"%s = %s / %s ;\n", (yyval.symbolValue)->name, temp, (yyvsp[(3) - (3)].symbolValue)->name);}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 102 "structfe.y"
    {char* temp=(yyvsp[(1) - (3)].symbolValue)->name; (yyval.symbolValue)->name=createTemp(); fprintf(yyout,"%s = %s + %s ;\n", (yyval.symbolValue)->name, temp, (yyvsp[(3) - (3)].symbolValue)->name);}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 103 "structfe.y"
    {char* temp=(yyvsp[(1) - (3)].symbolValue)->name; (yyval.symbolValue)->name=createTemp(); fprintf(yyout,"%s = %s - %s ;\n", (yyval.symbolValue)->name, temp, (yyvsp[(3) - (3)].symbolValue)->name);}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 108 "structfe.y"
    {if(isnumber((yyvsp[(3) - (3)].symbolValue)->name))
									{	
										int l = atoi((yyvsp[(3) - (3)].symbolValue)->name);
										char* leftid=(yyvsp[(1) - (3)].symbolValue)->name;
										char* prevtemp;
										(yyval.symbolValue)->name=createTemp();
										fprintf(yyout,"%s = %s / 2 ;\n", (yyval.symbolValue)->name, leftid);
                                                                                int i;
										for (i =0; i<(l-1) ; i++)
										{
											prevtemp=(yyval.symbolValue)->name;
											(yyval.symbolValue)->name=createTemp();
											fprintf(yyout,"%s = %s / 2 ;\n", (yyval.symbolValue)->name, prevtemp);
										}
									}}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 125 "structfe.y"
    {if(isnumber((yyvsp[(3) - (3)].symbolValue)->name))
									{	
										int l = atoi((yyvsp[(3) - (3)].symbolValue)->name);
										char* leftid=(yyvsp[(1) - (3)].symbolValue)->name;
										char* prevtemp;
										(yyval.symbolValue)->name=createTemp();
										fprintf(yyout,"%s = %s * 2 ;\n", (yyval.symbolValue)->name, leftid);
                                                                                int i;
										for (i =0; i<(l-1) ; i++)
										{
											prevtemp=(yyval.symbolValue)->name;
											(yyval.symbolValue)->name=createTemp();
											fprintf(yyout,"%s = %s * 2 ;\n", (yyval.symbolValue)->name, prevtemp);
										}
									}}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 144 "structfe.y"
    { fprintf(yyout,"%s < %s (ligne %d) ;\n", nomTable((yyvsp[(1) - (3)].symbolValue)),  nomTable((yyvsp[(3) - (3)].symbolValue)), yylineno) ;  }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 145 "structfe.y"
    { fprintf(yyout,"%s > %s (ligne %d) ;\n", nomTable((yyvsp[(1) - (3)].symbolValue)),  nomTable((yyvsp[(3) - (3)].symbolValue)), yylineno) ;  }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 146 "structfe.y"
    { fprintf(yyout,"%s <= %s (ligne %d) ;\n", nomTable((yyvsp[(1) - (3)].symbolValue)),  nomTable((yyvsp[(3) - (3)].symbolValue)), yylineno) ;  }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 147 "structfe.y"
    { fprintf(yyout,"%s >= %s (ligne %d) ;\n", nomTable((yyvsp[(1) - (3)].symbolValue)),  nomTable((yyvsp[(3) - (3)].symbolValue)), yylineno) ;  }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 152 "structfe.y"
    { fprintf(yyout,"%s == %s (ligne %d) ;\n", nomTable((yyvsp[(1) - (3)].symbolValue)),  nomTable((yyvsp[(3) - (3)].symbolValue)), yylineno);}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 153 "structfe.y"
    {fprintf(yyout,"%s != %s (ligne %d) ;\n", (yyvsp[(1) - (3)].symbolValue)->name,  (yyvsp[(3) - (3)].symbolValue)->name, yylineno); printf("Type 1 : %d Type 2 : %d (0 = INT, 1 = VOID, 2 = ID)\n", (yyvsp[(1) - (3)].symbolValue)->type, (yyvsp[(3) - (3)].symbolValue)->type);}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 158 "structfe.y"
    {fprintf(yyout,"%s && %s (ligne %d) ;\n", nomTable((yyvsp[(1) - (3)].symbolValue)),  nomTable((yyvsp[(3) - (3)].symbolValue)), yylineno) ;  }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 163 "structfe.y"
    {fprintf(yyout,"%s || %s (ligne %d) ;\n", nomTable((yyvsp[(1) - (3)].symbolValue)),  nomTable((yyvsp[(3) - (3)].symbolValue)), yylineno);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 168 "structfe.y"
    {printf("TEST1 %s\n", findTS("a")->name); 
                                        if (strcmp((yyvsp[(1) - (3)].symbolValue)->name,(yyvsp[(3) - (3)].symbolValue)->name))
						{
							fprintf(yyout,"%s = %s ;\n", (yyvsp[(1) - (3)].symbolValue)->name, (yyvsp[(3) - (3)].symbolValue)->name); 
							affectation((yyvsp[(1) - (3)].symbolValue), (yyvsp[(3) - (3)].symbolValue)); 
							(yyval.symbolValue)=(yyvsp[(1) - (3)].symbolValue);
						}
                                                printf("TEST2 %s\n", findTS("a")->name);
					}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 190 "structfe.y"
    {(yyvsp[(1) - (1)].type) = VOID_TYPE; fprintf(yyout,"void");}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 191 "structfe.y"
    {(yyvsp[(1) - (1)].type) = INT_TYPE;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 191 "structfe.y"
    {fprintf(yyout,"int ");}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 192 "structfe.y"
    {(yyvsp[(1) - (1)].symbolValue)->type = STRUCT_TYPE;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 211 "structfe.y"
    {(yyval.symbolValue)=(yyvsp[(2) - (2)].symbolValue);}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 216 "structfe.y"
    {(yyval.symbolValue)->type=ID_TYPE; fprintf(yyout,"%s\n", (yyval.symbolValue)->name);}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 217 "structfe.y"
    {(yyval.symbolValue)=(yyvsp[(2) - (3)].symbolValue);}
    break;



/* Line 1455 of yacc.c  */
#line 1845 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 293 "structfe.y"

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
	


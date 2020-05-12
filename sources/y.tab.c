/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "structfe.y" /* yacc.c:339  */

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


#line 93 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "structfe.y" /* yacc.c:355  */

        char *nom;
        int entier;
        int type;
	struct tablesymboles* symbolValue;

#line 200 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 217 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    56,    56,    57,    58,    62,    63,    64,    65,    66,
      67,    68,    72,    73,    77,    78,    81,    82,    83,    84,
      88,    89,    90,    94,    95,    96,   100,   101,   102,   106,
     107,   108,   112,   113,   114,   115,   116,   120,   121,   122,
     126,   127,   131,   132,   136,   137,   141,   142,   146,   147,
     151,   152,   153,   157,   158,   159,   163,   164,   168,   172,
     173,   177,   178,   179,   180,   184,   185,   189,   193,   194,
     195,   196,   197,   198,   202,   203,   204,   205,   209,   210,
     214,   215,   219,   220,   223,   227,   231,   232,   236,   237,
     241,   242,   246,   247,   251
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "declaration", "declaration_specifiers", "type_specifier",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "declarator", "direct_declarator", "parameter_list",
  "parameter_declaration", "statement", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "if_statement", "else_statement", "iteration_statement",
  "jump_statement", "program", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    38,    40,    41,    46,    44,    60,    62,    59,   123,
     125
};
# endif

#define YYPACT_NINF -81

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-81)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     132,    -4,   -81,   -11,   -81,   -81,    54,   -81,   -23,     8,
     -81,   -81,   -81,   -81,   -19,    -4,    29,   -81,    54,    45,
      27,   -81,   -81,   -81,    -4,    54,    15,   -81,    27,     0,
     -81,   112,   -81,    58,    50,    -1,   -81,   -81,   -81,   299,
      34,   215,    37,    49,   232,   -81,   -81,   313,   313,   -81,
     -81,   -81,   313,   -81,   -81,   -81,    36,    30,   313,    68,
      99,   166,    14,   142,    63,    75,    51,   -81,    54,   -81,
     -81,   140,   165,   -81,   -81,   -81,   -81,   -81,   -81,    54,
      19,   -81,   -81,   -81,   268,   -81,   313,   -81,   313,   249,
     -81,    56,   -81,   -81,    84,    91,   -81,   -81,   285,    95,
     313,   -81,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   -81,    96,   -81,   -81,
     190,   -81,   -81,   -81,   -81,   132,   104,   154,   157,   249,
     -81,   -81,   -81,   -81,    42,   -81,   -81,   -81,   -81,   -81,
     -81,    68,    68,    99,    99,   166,   166,   166,   166,    14,
      14,   142,    63,   -81,   -81,   -81,   215,   215,   313,   -81,
     313,   -81,   -81,   162,   -81,   215,   -81
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    50,     0,    51,    93,     0,    49,    52,     0,
      90,    92,    48,    52,    55,     0,     0,    61,     0,     0,
      60,    47,     1,    91,     0,     0,     0,    56,    59,     0,
      46,     0,    94,     0,     0,     0,    54,    57,    62,     0,
       0,     0,     0,     0,     0,    22,    21,     0,     0,     2,
       3,    20,     0,    82,    74,     5,    14,    23,     0,    26,
      29,    32,    37,    40,    42,    44,     0,    78,     0,    80,
      68,     0,     0,    69,    70,    71,    72,    73,    64,     0,
       0,    65,    53,    58,     0,    18,     0,    85,     0,     0,
      88,     0,    16,    17,     0,     0,    10,    11,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,    76,    79,
       0,    75,    81,    67,    63,     0,     0,     0,     0,     0,
      89,     4,     9,     6,     0,    12,     8,    45,    24,    25,
      23,    27,    28,    30,    31,    35,    36,    33,    34,    38,
      39,    41,    43,    77,    66,    19,     0,     0,     0,     7,
       0,    84,    86,     0,    13,     0,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,   -81,   -81,    -5,   -81,    72,    92,     3,    88,
     -18,    87,   -81,   -40,   -24,   -30,     1,     5,   141,    -2,
     -12,   196,   -81,    48,   -41,   201,   -81,   144,   -80,   -81,
     -81,   -81,   -81,   -81,   214,   -81
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    55,    56,   134,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     5,     6,     7,    13,    26,    27,
      19,    20,    80,    81,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     9,    10,    11
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      87,    68,    12,    79,    91,     8,    29,    67,    22,   129,
       2,     3,    94,    35,     8,    21,    25,    14,   108,   109,
      24,     1,     2,     3,    37,    25,     4,    25,    15,     2,
       3,   122,    37,    38,    85,    25,     8,    83,     4,    95,
     100,    68,    92,    93,    94,     4,   127,   119,   128,   158,
     110,   111,   124,   101,   125,    36,   117,    17,   135,    33,
     137,    18,    96,    97,     2,     3,    86,   123,    98,    88,
      99,     1,     2,     3,   114,   159,     8,   160,    16,   122,
       4,    89,    17,    30,    31,   126,    18,   115,     4,   116,
      82,    78,   102,   103,   130,    79,   151,   138,   139,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   145,   146,   147,   148,   161,   162,   131,   163,   132,
     164,   104,   105,   136,   166,     1,     2,     3,    39,    40,
      41,    42,    43,    44,    30,    45,    46,   155,    47,    48,
      49,    50,     4,    51,    52,     1,     2,     3,   112,   113,
      53,    31,    54,     1,     2,     3,    39,    40,    41,    42,
      43,    44,     4,    45,    46,    34,    47,    48,    49,    50,
       4,    51,    52,   154,   106,   107,   141,   142,    53,    31,
     118,    39,    40,    41,    42,    43,    44,   156,    45,    46,
     157,    47,    48,    49,    50,   165,    51,    52,   143,   144,
     149,   150,   152,    53,    31,   121,    39,    40,    41,    42,
      43,    44,    28,    45,    46,   120,    47,    48,    49,    50,
      32,    51,    52,    23,     0,     0,     0,     0,    53,    31,
     153,    39,    40,    41,    42,    43,    44,     0,    45,    46,
       0,    47,    48,    49,    50,     0,    51,    52,    39,     0,
       0,     0,     0,    53,    31,    45,    46,     0,    47,    48,
      49,    50,     0,    51,    52,    39,     0,     0,     0,     0,
      90,     0,    45,    46,     0,    47,    48,    49,    50,     0,
      51,    52,     2,     3,    39,     0,     0,    53,     0,     0,
       0,    45,    46,     0,    47,    48,    49,    50,     4,    51,
      52,    39,     0,     0,     0,     0,     0,     0,    45,    46,
       0,    47,    48,    49,    50,    39,    51,    52,   133,     0,
       0,     0,    45,    46,     0,    47,    48,    49,    50,    39,
      51,    84,     0,     0,     0,     0,    45,    46,     0,    47,
      48,    49,    50,     0,    51,    52
};

static const yytype_int16 yycheck[] =
{
      41,    31,     1,    33,    44,     0,    18,    31,     0,    89,
      14,    15,    52,    25,     9,    38,    15,    28,     4,     5,
      39,    13,    14,    15,    26,    24,    30,    26,    39,    14,
      15,    72,    34,    33,    39,    34,    31,    38,    30,     3,
      10,    71,    47,    48,    84,    30,    86,    71,    88,   129,
      36,    37,    33,    58,    35,    40,    68,    28,    98,    32,
     100,    32,    26,    27,    14,    15,    32,    79,    32,    32,
      34,    13,    14,    15,    11,    33,    71,    35,    24,   120,
      30,    32,    28,    38,    39,    84,    32,    12,    30,    38,
      40,    33,    24,    25,    38,   125,   114,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   108,   109,   110,   111,   156,   157,    33,   158,    28,
     160,    22,    23,    28,   165,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    38,    23,    24,    33,    26,    27,
      28,    29,    30,    31,    32,    13,    14,    15,     6,     7,
      38,    39,    40,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    30,    23,    24,    24,    26,    27,    28,    29,
      30,    31,    32,   125,     8,     9,   104,   105,    38,    39,
      40,    16,    17,    18,    19,    20,    21,    33,    23,    24,
      33,    26,    27,    28,    29,    33,    31,    32,   106,   107,
     112,   113,   115,    38,    39,    40,    16,    17,    18,    19,
      20,    21,    16,    23,    24,    71,    26,    27,    28,    29,
      19,    31,    32,     9,    -1,    -1,    -1,    -1,    38,    39,
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
       0,    13,    14,    15,    30,    55,    56,    57,    58,    74,
      75,    76,    57,    58,    28,    39,    24,    28,    32,    61,
      62,    38,     0,    75,    39,    57,    59,    60,    62,    61,
      38,    39,    66,    32,    59,    61,    40,    60,    33,    16,
      17,    18,    19,    20,    21,    23,    24,    26,    27,    28,
      29,    31,    32,    38,    40,    42,    43,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    33,    56,
      63,    64,    40,    38,    32,    45,    32,    65,    32,    32,
      38,    54,    45,    45,    54,     3,    26,    27,    32,    34,
      10,    45,    24,    25,    22,    23,     8,     9,     4,     5,
      36,    37,     6,     7,    11,    12,    38,    61,    40,    55,
      68,    40,    65,    61,    33,    35,    57,    54,    54,    69,
      38,    33,    28,    33,    44,    54,    28,    54,    45,    45,
      45,    47,    47,    48,    48,    49,    49,    49,    49,    50,
      50,    51,    52,    40,    64,    33,    33,    33,    69,    33,
      35,    65,    65,    54,    54,    33,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    42,    43,    43,    43,    43,    43,
      43,    43,    44,    44,    45,    45,    45,    45,    45,    45,
      46,    46,    46,    47,    47,    47,    48,    48,    48,    49,
      49,    49,    50,    50,    50,    50,    50,    51,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    57,    58,    58,    58,    59,    59,    60,    61,
      61,    62,    62,    62,    62,    63,    63,    64,    65,    65,
      65,    65,    65,    65,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    71,    72,    72,    73,    73,
      74,    74,    75,    75,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     4,     3,     3,
       2,     2,     1,     3,     1,     2,     2,     2,     2,     4,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     3,     2,     2,     1,
       1,     1,     1,     5,     4,     2,     1,     2,     3,     2,
       1,     1,     3,     4,     3,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     2,     5,     7,     2,     3,
       1,     2,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 56 "structfe.y" /* yacc.c:1646  */
    { printf("TEST"); (yyval.symbolValue)->type = ID_TYPE;  }
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 57 "structfe.y" /* yacc.c:1646  */
    {(yyval.symbolValue)->type = INT_TYPE;}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 58 "structfe.y" /* yacc.c:1646  */
    {(yyval.symbolValue) = (yyvsp[-1].symbolValue);}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 62 "structfe.y" /* yacc.c:1646  */
    { (yyval.symbolValue) = (yyvsp[0].symbolValue) ;}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 77 "structfe.y" /* yacc.c:1646  */
    { (yyval.symbolValue) = (yyvsp[0].symbolValue) ;}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 78 "structfe.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].symbolValue) == MINUS) { (yyval.symbolValue)->val = -(yyval.symbolValue)->val} 
						else if ((yyvsp[-1].symbolValue) == STAR) { } 
						else {} }
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 94 "structfe.y" /* yacc.c:1646  */
    { (yyval.symbolValue) = (yyvsp[0].symbolValue) ;}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 95 "structfe.y" /* yacc.c:1646  */
    {fprintf(yyout,"%s = %s * %s ;\n", &&=createTemp(), (yyvsp[-2].symbolValue), (yyvsp[0].symbolValue));}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 96 "structfe.y" /* yacc.c:1646  */
    {fprintf(yyout,"%s = %s / %s ;\n", &&=createTemp(), (yyvsp[-2].symbolValue), (yyvsp[0].symbolValue));}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 100 "structfe.y" /* yacc.c:1646  */
    { (yyval.symbolValue) = (yyvsp[0].symbolValue) ;}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 101 "structfe.y" /* yacc.c:1646  */
    {printf("TESTS"); fprintf(yyout,"%s = %s + %s ;\n", &&=createTemp(), (yyvsp[-2].symbolValue), (yyvsp[0].symbolValue));}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 102 "structfe.y" /* yacc.c:1646  */
    {fprintf(yyout,"%s = %s - %s ;\n", &&=createTemp(), (yyvsp[-2].symbolValue), (yyvsp[0].symbolValue));}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 106 "structfe.y" /* yacc.c:1646  */
    { (yyval.symbolValue) = (yyvsp[0].symbolValue) ;}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 107 "structfe.y" /* yacc.c:1646  */
    {fprintf(yyout,"%s = %s >> %s ;\n", &&=createTemp(), (yyvsp[-2].symbolValue), (yyvsp[0].symbolValue));}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 108 "structfe.y" /* yacc.c:1646  */
    {fprintf(yyout,"%s = %s << %s ;\n", &&=createTemp(), (yyvsp[-2].symbolValue), (yyvsp[0].symbolValue));}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 112 "structfe.y" /* yacc.c:1646  */
    { (yyval.symbolValue) = (yyvsp[0].symbolValue) ;}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 113 "structfe.y" /* yacc.c:1646  */
    { fprintf(yyout,"%s < %s (ligne %d) ;\n", nomTable((yyvsp[-2].symbolValue)),  nomTable((yyvsp[0].symbolValue)), yylineno) ;  }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 114 "structfe.y" /* yacc.c:1646  */
    { fprintf(yyout,"%s > %s (ligne %d) ;\n", nomTable((yyvsp[-2].symbolValue)),  nomTable((yyvsp[0].symbolValue)), yylineno) ;  }
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 115 "structfe.y" /* yacc.c:1646  */
    { fprintf(yyout,"%s <= %s (ligne %d) ;\n", nomTable((yyvsp[-2].symbolValue)),  nomTable((yyvsp[0].symbolValue)), yylineno) ;  }
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 116 "structfe.y" /* yacc.c:1646  */
    { fprintf(yyout,"%s >= %s (ligne %d) ;\n", nomTable((yyvsp[-2].symbolValue)),  nomTable((yyvsp[0].symbolValue)), yylineno) ;  }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 120 "structfe.y" /* yacc.c:1646  */
    { (yyval.symbolValue) = (yyvsp[0].symbolValue) ;}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 121 "structfe.y" /* yacc.c:1646  */
    { fprintf(yyout,"%s == %s (ligne %d) ;\n", nomTable((yyvsp[-2].symbolValue)),  nomTable((yyvsp[0].symbolValue)), yylineno);}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 122 "structfe.y" /* yacc.c:1646  */
    {fprintf(yyout,"%s != %s (ligne %d) ;\n", (yyvsp[-2].symbolValue)->name,  (yyvsp[0].symbolValue)->name, yylineno); printf("Type 1 : %d Type 2 : %d (0 = INT, 1 = VOID, 2 = ID)\n", (yyvsp[-2].symbolValue)->type, (yyvsp[0].symbolValue)->type);}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 126 "structfe.y" /* yacc.c:1646  */
    { (yyval.symbolValue) = (yyvsp[0].symbolValue) ;}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 127 "structfe.y" /* yacc.c:1646  */
    {fprintf(yyout,"%s && %s (ligne %d) ;\n", nomTable((yyvsp[-2].symbolValue)),  nomTable((yyvsp[0].symbolValue)), yylineno) ;  }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 131 "structfe.y" /* yacc.c:1646  */
    { (yyval.symbolValue) = (yyvsp[0].symbolValue) ;}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 132 "structfe.y" /* yacc.c:1646  */
    {fprintf(yyout,"%s || %s (ligne %d) ;\n", nomTable((yyvsp[-2].symbolValue)),  nomTable((yyvsp[0].symbolValue)), yylineno);}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 137 "structfe.y" /* yacc.c:1646  */
    {affectation((yyvsp[-2].symbolValue), (yyvsp[0].symbolValue)); (yyval.symbolValue)=(yyvsp[-2].symbolValue);}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 151 "structfe.y" /* yacc.c:1646  */
    {(yyvsp[0].type) = VOID_TYPE;}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 152 "structfe.y" /* yacc.c:1646  */
    {(yyvsp[0].type) = INT_TYPE;}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 153 "structfe.y" /* yacc.c:1646  */
    {(yyvsp[0].symbolValue)->type = STRUCT_TYPE;}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 172 "structfe.y" /* yacc.c:1646  */
    {(yyval.symbolValue)=(yyvsp[0].symbolValue);}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 177 "structfe.y" /* yacc.c:1646  */
    {(yyval.symbolValue)->type=ID_TYPE;}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 178 "structfe.y" /* yacc.c:1646  */
    {(yyval.symbolValue)=(yyvsp[-1].symbolValue);}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1658 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 254 "structfe.y" /* yacc.c:1906  */

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

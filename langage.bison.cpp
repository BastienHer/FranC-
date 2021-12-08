/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "langage.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <cmath>   
  #include <map>
  #include <vector>
  #include <string>
  #include <iostream>
  #include <typeinfo>
  #include <stack>

  using namespace std;

  extern int yylex ();
  extern char* yytext;
  extern FILE* yyin;
  int yyerror(char *s);

  class instruction{
  public:
    instruction (const int &c,const double &v=0, const string &n="",const string &s="") {code = c,stringValue = s, value = v; name = n;};  
    int code;
    string stringValue; 
    double value;    
    string name;       
  };

  map<string,double> variables;
  map<string,string> variablesString;

  int ic = 0;

  map<string,int> adresses;

  vector <instruction> code_genere;    

  int add_instruction(const int &c, const double &v=0, const string &n="",const string &s="") {
      code_genere.push_back(instruction(c,v,n,s)); 
      ic++;
      return 0; 
   }; 



#line 116 "langage.bison.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "langage.bison.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_VAR = 5,                        /* VAR  */
  YYSYMBOL_SIN = 6,                        /* SIN  */
  YYSYMBOL_COS = 7,                        /* COS  */
  YYSYMBOL_SI = 8,                         /* SI  */
  YYSYMBOL_ALORS = 9,                      /* ALORS  */
  YYSYMBOL_ADDSTRING = 10,                 /* ADDSTRING  */
  YYSYMBOL_SINON = 11,                     /* SINON  */
  YYSYMBOL_FINSI = 12,                     /* FINSI  */
  YYSYMBOL_SUP = 13,                       /* SUP  */
  YYSYMBOL_INF = 14,                       /* INF  */
  YYSYMBOL_SUPEG = 15,                     /* SUPEG  */
  YYSYMBOL_INFEG = 16,                     /* INFEG  */
  YYSYMBOL_NEG = 17,                       /* NEG  */
  YYSYMBOL_EGA = 18,                       /* EGA  */
  YYSYMBOL_PRINT = 19,                     /* PRINT  */
  YYSYMBOL_PRINTSTRING = 20,               /* PRINTSTRING  */
  YYSYMBOL_RAND = 21,                      /* RAND  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_ASSIGNSTRING = 23,              /* ASSIGNSTRING  */
  YYSYMBOL_GOTO = 24,                      /* GOTO  */
  YYSYMBOL_LABEL = 25,                     /* LABEL  */
  YYSYMBOL_JMP = 26,                       /* JMP  */
  YYSYMBOL_JMPCOND = 27,                   /* JMPCOND  */
  YYSYMBOL_FUNCTION = 28,                  /* FUNCTION  */
  YYSYMBOL_TANTQUE = 29,                   /* TANTQUE  */
  YYSYMBOL_FINTANTQUE = 30,                /* FINTANTQUE  */
  YYSYMBOL_ADD = 31,                       /* ADD  */
  YYSYMBOL_SUB = 32,                       /* SUB  */
  YYSYMBOL_MULT = 33,                      /* MULT  */
  YYSYMBOL_DIV = 34,                       /* DIV  */
  YYSYMBOL_35_n_ = 35,                     /* '\n'  */
  YYSYMBOL_36_ = 36,                       /* ':'  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_bloc = 41,                      /* bloc  */
  YYSYMBOL_label = 42,                     /* label  */
  YYSYMBOL_instruction = 43,               /* instruction  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_46_3 = 46,                      /* $@3  */
  YYSYMBOL_47_4 = 47,                      /* $@4  */
  YYSYMBOL_expr = 48,                      /* expr  */
  YYSYMBOL_condition = 49                  /* condition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
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
typedef yytype_int8 yy_state_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  36
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  76

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      35,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    39,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,     2,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    95,    95,    96,    98,    99,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   114,   112,   121,   124,   121,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   160
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "STRING", "VAR",
  "SIN", "COS", "SI", "ALORS", "ADDSTRING", "SINON", "FINSI", "SUP", "INF",
  "SUPEG", "INFEG", "NEG", "EGA", "PRINT", "PRINTSTRING", "RAND", "ASSIGN",
  "ASSIGNSTRING", "GOTO", "LABEL", "JMP", "JMPCOND", "FUNCTION", "TANTQUE",
  "FINTANTQUE", "ADD", "SUB", "MULT", "DIV", "'\\n'", "':'", "'='", "'('",
  "')'", "$accept", "bloc", "label", "instruction", "$@1", "$@2", "$@3",
  "$@4", "expr", "condition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-19)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -56,    19,   -56,   -34,    18,   -56,   -56,   -56,   -24,   -18,
       5,     7,     0,    45,    28,    17,    45,    39,   100,    54,
      45,    45,    45,    40,   -56,   100,   100,   -56,    45,    55,
     -56,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    41,   100,    64,    91,   100,    46,    51,   -56,   100,
     100,   100,   100,   100,   100,   100,   100,    49,    49,   -56,
     -56,    56,    58,   -56,   -56,   -56,   -56,    29,    16,    73,
      69,    65,   -56,   -56,   -11,   -56
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     4,     1,     0,     6,     5,    20,    22,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,     0,    22,    21,     8,    10,    13,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    11,     0,     0,    36,     0,     0,    25,    31,
      30,    32,    33,    34,    35,    26,    27,    28,    29,    23,
      24,     0,     0,    14,    17,     2,     2,     4,     4,     0,
       0,     0,    19,     2,     4,    16
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -55,   -56,   -56,   -56,   -56,   -56,   -56,    -4,    74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     4,    17,    65,    69,    66,    70,    45,    46
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      18,    75,     5,     6,    23,    24,     9,    10,    25,    26,
      67,    68,    29,    19,     3,    42,    43,    44,    74,     2,
      20,     6,     7,     8,     9,    10,    11,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    12,    16,    13,
     -15,     3,    14,    21,     3,    22,   -18,    15,     6,     7,
      24,     9,    10,    27,     3,    28,    16,     6,    41,    24,
       9,    10,    31,    32,    33,    34,    35,    36,    31,    32,
      33,    34,    35,    36,    30,    -9,   -12,    31,    32,    33,
      34,    35,    36,    16,    71,    61,    37,    38,    39,    40,
      62,    63,    16,    64,    48,    37,    38,    39,    40,    72,
      73,     0,    47,    59,    31,    32,    33,    34,    35,    36,
       0,     0,     0,    31,    32,    33,    34,    35,    36,     0,
       0,     0,    37,    38,    39,    40,     0,     0,     0,     0,
      60,    37,    38,    39,    40
};

static const yytype_int8 yycheck[] =
{
       4,    12,    36,     3,     4,     5,     6,     7,    12,    13,
      65,    66,    16,    37,    25,    19,    20,    21,    73,     0,
      38,     3,     4,     5,     6,     7,     8,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    19,    38,    21,
      11,    25,    24,    38,    25,    38,    30,    29,     3,     4,
       5,     6,     7,    25,    25,    38,    38,     3,     4,     5,
       6,     7,    13,    14,    15,    16,    17,    18,    13,    14,
      15,    16,    17,    18,    35,    35,    35,    13,    14,    15,
      16,    17,    18,    38,    11,    39,    31,    32,    33,    34,
      39,    35,    38,    35,    39,    31,    32,    33,    34,    30,
      35,    -1,    28,    39,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      39,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,     0,    25,    42,    36,     3,     4,     5,     6,
       7,     8,    19,    21,    24,    29,    38,    43,    48,    37,
      38,    38,    38,     4,     5,    48,    48,    25,    38,    48,
      35,    13,    14,    15,    16,    17,    18,    31,    32,    33,
      34,     4,    48,    48,    48,    48,    49,    49,    39,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    39,
      39,    39,    39,    35,    35,    44,    46,    41,    41,    45,
      47,    11,    30,    35,    41,    12
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    43,    43,    43,    43,
      43,    43,    43,    43,    44,    45,    43,    46,    47,    43,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    49
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     2,     0,     1,     2,     2,
       2,     3,     3,     2,     0,     0,    12,     0,     0,     9,
       1,     1,     1,     4,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 5: /* label: LABEL ':'  */
#line 99 "langage.y"
                   { // Lorsque je rencontre un label
                     // je stocke le numéro d'instruction actelle
                     // dans la table des adresses. C'est tout!   
                     adresses[(yyvsp[-1].nom)] = ic;}
#line 1205 "langage.bison.cpp"
    break;

  case 7: /* instruction: expr  */
#line 105 "langage.y"
                           {  }
#line 1211 "langage.bison.cpp"
    break;

  case 8: /* instruction: PRINT expr  */
#line 106 "langage.y"
                           { add_instruction(PRINT); }
#line 1217 "langage.bison.cpp"
    break;

  case 9: /* instruction: PRINT STRING  */
#line 107 "langage.y"
                           { add_instruction(PRINTSTRING);}
#line 1223 "langage.bison.cpp"
    break;

  case 10: /* instruction: RAND expr  */
#line 108 "langage.y"
                        {add_instruction(RAND);}
#line 1229 "langage.bison.cpp"
    break;

  case 11: /* instruction: VAR '=' expr  */
#line 109 "langage.y"
                           { add_instruction(ASSIGN, 0, (yyvsp[-2].nom)); }
#line 1235 "langage.bison.cpp"
    break;

  case 12: /* instruction: VAR '=' STRING  */
#line 110 "langage.y"
                             { add_instruction(STRING,0,"",(yyvsp[0].valeurString));add_instruction(ASSIGNSTRING,0,(yyvsp[-2].nom),(yyvsp[0].valeurString));}
#line 1241 "langage.bison.cpp"
    break;

  case 13: /* instruction: GOTO LABEL  */
#line 111 "langage.y"
                           { add_instruction(JMP, -999, (yyvsp[0].nom)); }
#line 1247 "langage.bison.cpp"
    break;

  case 14: /* $@1: %empty  */
#line 112 "langage.y"
                                        { (yyvsp[-4].adresse).jc = ic;
                                          add_instruction(JMPCOND); }
#line 1254 "langage.bison.cpp"
    break;

  case 15: /* $@2: %empty  */
#line 114 "langage.y"
                                        { (yyvsp[-6].adresse).jmp = ic;
                                          add_instruction(JMP);
                                          code_genere[(yyvsp[-6].adresse).jc].value = ic;
                                        }
#line 1263 "langage.bison.cpp"
    break;

  case 16: /* instruction: SI '(' condition ')' '\n' $@1 bloc $@2 SINON '\n' bloc FINSI  */
#line 120 "langage.y"
                                        { code_genere[(yyvsp[-11].adresse).jmp].value = ic;}
#line 1269 "langage.bison.cpp"
    break;

  case 17: /* $@3: %empty  */
#line 121 "langage.y"
                                            {(yyvsp[-4].adresse).jc =ic ;
                                          add_instruction(JMPCOND);  
                                          }
#line 1277 "langage.bison.cpp"
    break;

  case 18: /* $@4: %empty  */
#line 124 "langage.y"
                                              {(yyvsp[-6].adresse).jmp = ic;
                                          add_instruction(JMP);
                                          code_genere[(yyvsp[-6].adresse).jc].value = ic;
                                          }
#line 1286 "langage.bison.cpp"
    break;

  case 19: /* instruction: TANTQUE '(' condition ')' '\n' $@3 bloc $@4 FINTANTQUE  */
#line 128 "langage.y"
                                              {
                                              
                                             
                                                
                                                code_genere[(yyvsp[-8].adresse).jmp].value=(yyvsp[-8].adresse).jc-3;
                                              
                                              
                                              
                                              cout<<"salut"<<endl;
                                              
                                              
                                              }
#line 1303 "langage.bison.cpp"
    break;

  case 20: /* expr: NUM  */
#line 142 "langage.y"
                        { add_instruction (NUM, (yyvsp[0].valeur));   }
#line 1309 "langage.bison.cpp"
    break;

  case 21: /* expr: VAR  */
#line 143 "langage.y"
                         { add_instruction (VAR, 0, (yyvsp[0].nom));  }
#line 1315 "langage.bison.cpp"
    break;

  case 22: /* expr: STRING  */
#line 144 "langage.y"
              { add_instruction(STRING,0,"",(yyvsp[0].valeurString));}
#line 1321 "langage.bison.cpp"
    break;

  case 23: /* expr: SIN '(' expr ')'  */
#line 145 "langage.y"
                         {  }
#line 1327 "langage.bison.cpp"
    break;

  case 24: /* expr: COS '(' expr ')'  */
#line 146 "langage.y"
                         {  }
#line 1333 "langage.bison.cpp"
    break;

  case 25: /* expr: '(' expr ')'  */
#line 147 "langage.y"
                         {  }
#line 1339 "langage.bison.cpp"
    break;

  case 26: /* expr: expr ADD expr  */
#line 148 "langage.y"
                         { (yyval.valeur)=(yyvsp[-2].valeur)+(yyvsp[0].valeur);cout<< (yyval.valeur)<<endl; add_instruction(ADD); }
#line 1345 "langage.bison.cpp"
    break;

  case 27: /* expr: expr SUB expr  */
#line 149 "langage.y"
                         { (yyval.valeur)=(yyvsp[-2].valeur)-(yyvsp[0].valeur);cout<<(yyval.valeur)<<endl; add_instruction(SUB);  }
#line 1351 "langage.bison.cpp"
    break;

  case 28: /* expr: expr MULT expr  */
#line 150 "langage.y"
                         { (yyval.valeur)=(yyvsp[-2].valeur)*(yyvsp[0].valeur);cout<<(yyval.valeur)<<endl; add_instruction(MULT);}
#line 1357 "langage.bison.cpp"
    break;

  case 29: /* expr: expr DIV expr  */
#line 151 "langage.y"
                         { (yyval.valeur)=(yyvsp[-2].valeur)/(yyvsp[0].valeur);cout<<(yyval.valeur)<<endl; add_instruction(DIV); }
#line 1363 "langage.bison.cpp"
    break;

  case 30: /* expr: expr INF expr  */
#line 152 "langage.y"
                         { if((yyvsp[-2].valeur)<3){(yyval.valeur)=true; cout<<1;} else{(yyval.valeur)=false;cout<<0; }add_instruction(INF);}
#line 1369 "langage.bison.cpp"
    break;

  case 31: /* expr: expr SUP expr  */
#line 153 "langage.y"
                          { if((yyvsp[-2].valeur)>3){(yyval.valeur)=true; cout<<1;} else{(yyval.valeur)=false;cout<<0; }add_instruction(SUP);}
#line 1375 "langage.bison.cpp"
    break;

  case 32: /* expr: expr SUPEG expr  */
#line 154 "langage.y"
                            { if((yyvsp[-2].valeur)>=(yyvsp[0].valeur)){(yyval.valeur)=true; cout<<1;} else{(yyval.valeur)=false;cout<<0; }add_instruction(SUPEG); }
#line 1381 "langage.bison.cpp"
    break;

  case 33: /* expr: expr INFEG expr  */
#line 155 "langage.y"
                            { if((yyvsp[-2].valeur)<=(yyvsp[0].valeur)){(yyval.valeur)=true; cout<<1;} else{(yyval.valeur)=false;cout<<0; }add_instruction(INFEG); }
#line 1387 "langage.bison.cpp"
    break;

  case 34: /* expr: expr NEG expr  */
#line 156 "langage.y"
                          { if((yyvsp[-2].valeur)!=(yyvsp[0].valeur)){(yyval.valeur)=true; cout<<1;} else{(yyval.valeur)=false;cout<<0; }add_instruction(NEG); }
#line 1393 "langage.bison.cpp"
    break;

  case 35: /* expr: expr EGA expr  */
#line 157 "langage.y"
                          { if((yyvsp[-2].valeur)==(yyvsp[0].valeur)){(yyval.valeur)=true; cout<<1;} else{(yyval.valeur)=false;cout<<0; }add_instruction(EGA); }
#line 1399 "langage.bison.cpp"
    break;

  case 36: /* condition: expr  */
#line 160 "langage.y"
                           {}
#line 1405 "langage.bison.cpp"
    break;


#line 1409 "langage.bison.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 162 "langage.y"


int yyerror(char *s) {					
    printf("%s : %s\n", s, yytext);
}

string print_code(int ins) {
  switch (ins) {
    case STRING : return "STR";
    case ADD      : return "ADD";
    case ADDSTRING      : return "ADDSTR";
    case SUB      : return "SUB";
    case MULT     : return "MUL";
    case DIV     : return "DIV";    
    case NUM      : return "NUM";
    case VAR      : return "VAR";
    case PRINT    : return "PRINT";
    case RAND : return "RAND";
    case ASSIGN   : return "ASSIGN";
    case ASSIGNSTRING   : return "ASSIGNSTR";
    case JMP      : return "JMP";
    case JMPCOND  : return "JC ";
    default : return "";
  }
}

void execution ( const vector <instruction> &code_genere, 
                 map<string,double> &variables )
{
printf("\n------- Exécution du programme ---------\n");
stack<int> pile;
stack<string> pileString;

int ic = 0;  // compteur instruction
double r1, r2;  // des registres
string s1, s2;


  while (ic < code_genere.size()){   // tant que nous ne sommes pas à la fin du programme
      auto ins = code_genere[ic];
      switch (ins.code){
        case ADD:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            pile.push(r1+r2);
            cout<< "Résultat du calcul: " << r1+r2<<endl;
            ic++;

          break;
          case ADDSTRING:
            s1 = pileString.top();    // Rrécupérer la tête de pile;
            pileString.pop();

            s2 = pileString.top();    // Rrécupérer la tête de pile;
            pileString.pop();

            pileString.push(s1+s2);
            cout<< "Résultat du calcul: " << s1+s2<<endl;
            ic++;
          break;

        case SUB:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            pile.push(r2-r1);
            cout<< "Résultat du calcul: " << r1+r2<<endl;
            ic++;
          break;

        case MULT:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            pile.push(r1*r2);
            cout<< "Résultat du calcul: " << r1+r2<<endl;
            ic++;
          break;

        case DIV:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            pile.push(r2/r1);
            cout<< "Résultat du calcul: " << r1+r2<<endl;
            ic++;
          break;

        case SUP:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            if(r2>r1){pile.push(true);}
            else{pile.push(false); cout<<1<<endl;}
            ic++;
          break;

        case SUPEG:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            if(r2>=r1){pile.push(true); cout<<1<<endl;}
            else{pile.push(false);}
            ic++;
          break;

        case INF:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            if(r2<r1){pile.push(true); cout<<1<<endl;}
            else{pile.push(false);}
            ic++;
          break;

        case INFEG:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            if(r2<=r1){pile.push(true); cout<<1<<endl;}
            else{pile.push(false);}
            ic++;
          break;
          
        case EGA:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            if(r2==r1){pile.push(true); cout<<1<<endl;}
            else{pile.push(false);cout<<0<<endl;}
            ic++;
          break;

        case NEG:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            if(r2!=r1){pile.push(true); cout<<1<<endl;}
            else{pile.push(false);}
            ic++;
          break;

        case ASSIGN:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();
            variables[ins.name] = r1;
            ic++;
          break;

        case ASSIGNSTRING:
            s1 = pileString.top();    // Rrécupérer la tête de pile;
            pileString.pop();
            variablesString[ins.name] = s1;
            ic++;
          break;

        case PRINT:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();
            cout << "" << r1 << endl; 
            ic++;
        break;

        case PRINTSTRING:
            s1 = pileString.top();    // Rrécupérer la tête de pile;
            pileString.pop();
            cout << s1 << endl; 
            ic++;
        break;

        case RAND:
          srand(time(NULL));
          r1 = pile.top();
          pile.pop();
          r1 = rand() % (int)r1;  
          cout << "Retour de la fonction aléatoire: " << r1 << endl;
          ic++;
        break;


        case NUM:   // pour un nombre, on empile
            pile.push(ins.value);
            ic++;
        break;

        case STRING:
            pileString.push(ins.stringValue);
            cout << ins.stringValue << endl;
            ic++;
        break;

        case JMP:
            if (ins.value != -999) // Est-ce un GoTo ?
              ic = ins.value;
            else
              // je récupère l'adresse à partir de la table
              ic = adresses[ins.name];
          break;

        case JMPCOND: 
             r1 = pile.top();    // Rrécupérer la tête de pile;
             pile.pop();
             if ( r1 != 0 ) 
                ic++;
             else 
                ic = (int)ins.value;             
          break;

        case VAR:    // je consulte la table de symbole et j'empile la valeur de la variable
             // Si elle existe bien sur... 
            
            try {
                pile.push(variables.at(ins.name));
                ic++;
            }
          catch(...) {
                variables[ins.name] = 0;
                pile.push(variables.at(ins.name));
                ic++;
            }
          break;
      }
  }
}


int main(int argc, char **argv) {

  if ( argc > 1 )
    yyin = fopen( argv[1], "r" );
  else
    yyin = stdin;


  


  yyparse();				

  for (int i = 0; i < code_genere.size(); i++){
    auto instruction = code_genere [i];
    cout << "instruction n°"<< i 
         << '\t'
         << "code: " << print_code(instruction.code) 
         << '\t'
         << " valeur: " << instruction.value 
         << '\t' 
         << " nom: " << instruction.name 
         << '\t'
         << " valeurStr: " << instruction.stringValue
         << endl;
  }

  execution(code_genere, variables);
  
  return 0;
}

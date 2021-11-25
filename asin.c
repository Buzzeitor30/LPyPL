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
#line 6 "src/asin.y"

#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
extern int yylineno;


#line 80 "asin.c"

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

#include "asin.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID_ = 3,                        /* ID_  */
  YYSYMBOL_CTE_ = 4,                       /* CTE_  */
  YYSYMBOL_PUNT_ = 5,                      /* PUNT_  */
  YYSYMBOL_COMA_ = 6,                      /* COMA_  */
  YYSYMBOL_FINL_ = 7,                      /* FINL_  */
  YYSYMBOL_WHILE_ = 8,                     /* WHILE_  */
  YYSYMBOL_BOOL_ = 9,                      /* BOOL_  */
  YYSYMBOL_STRUC_ = 10,                    /* STRUC_  */
  YYSYMBOL_RETURN_ = 11,                   /* RETURN_  */
  YYSYMBOL_READ_ = 12,                     /* READ_  */
  YYSYMBOL_PRINT_ = 13,                    /* PRINT_  */
  YYSYMBOL_IF_ = 14,                       /* IF_  */
  YYSYMBOL_ELSE_ = 15,                     /* ELSE_  */
  YYSYMBOL_APAR_ = 16,                     /* APAR_  */
  YYSYMBOL_CPAR_ = 17,                     /* CPAR_  */
  YYSYMBOL_ABLOQ_ = 18,                    /* ABLOQ_  */
  YYSYMBOL_CBLOQ_ = 19,                    /* CBLOQ_  */
  YYSYMBOL_AIND_ = 20,                     /* AIND_  */
  YYSYMBOL_CIND_ = 21,                     /* CIND_  */
  YYSYMBOL_IGU_ = 22,                      /* IGU_  */
  YYSYMBOL_DIST_ = 23,                     /* DIST_  */
  YYSYMBOL_AND_ = 24,                      /* AND_  */
  YYSYMBOL_OR_ = 25,                       /* OR_  */
  YYSYMBOL_MAY_ = 26,                      /* MAY_  */
  YYSYMBOL_MEN_ = 27,                      /* MEN_  */
  YYSYMBOL_MAYIGU_ = 28,                   /* MAYIGU_  */
  YYSYMBOL_MENORIGU_ = 29,                 /* MENORIGU_  */
  YYSYMBOL_NOT_ = 30,                      /* NOT_  */
  YYSYMBOL_ASIG_ = 31,                     /* ASIG_  */
  YYSYMBOL_MAS_ = 32,                      /* MAS_  */
  YYSYMBOL_MENOS_ = 33,                    /* MENOS_  */
  YYSYMBOL_POR_ = 34,                      /* POR_  */
  YYSYMBOL_DIV_ = 35,                      /* DIV_  */
  YYSYMBOL_INT_ = 36,                      /* INT_  */
  YYSYMBOL_TRUE_ = 37,                     /* TRUE_  */
  YYSYMBOL_FALSE_ = 38,                    /* FALSE_  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_programa = 40,                  /* programa  */
  YYSYMBOL_listaDeclaraciones = 41,        /* listaDeclaraciones  */
  YYSYMBOL_declaracion = 42,               /* declaracion  */
  YYSYMBOL_declaracionVariable = 43,       /* declaracionVariable  */
  YYSYMBOL_tipoSimple = 44,                /* tipoSimple  */
  YYSYMBOL_listaCampos = 45,               /* listaCampos  */
  YYSYMBOL_declaracionFuncion = 46,        /* declaracionFuncion  */
  YYSYMBOL_47_1 = 47,                      /* @1  */
  YYSYMBOL_parametrosFormales = 48,        /* parametrosFormales  */
  YYSYMBOL_listaParametrosFormales = 49,   /* listaParametrosFormales  */
  YYSYMBOL_bloque = 50,                    /* bloque  */
  YYSYMBOL_declaracionVariableLocal = 51,  /* declaracionVariableLocal  */
  YYSYMBOL_listaInstrucciones = 52,        /* listaInstrucciones  */
  YYSYMBOL_instruccion = 53,               /* instruccion  */
  YYSYMBOL_instruccionAsignacion = 54,     /* instruccionAsignacion  */
  YYSYMBOL_instruccionEntradaSalida = 55,  /* instruccionEntradaSalida  */
  YYSYMBOL_instruccionSeleccion = 56,      /* instruccionSeleccion  */
  YYSYMBOL_instruccionIteracion = 57,      /* instruccionIteracion  */
  YYSYMBOL_expresion = 58,                 /* expresion  */
  YYSYMBOL_expresionIgualdad = 59,         /* expresionIgualdad  */
  YYSYMBOL_expresionRelacional = 60,       /* expresionRelacional  */
  YYSYMBOL_expresionAditiva = 61,          /* expresionAditiva  */
  YYSYMBOL_expresionMultiplicativa = 62,   /* expresionMultiplicativa  */
  YYSYMBOL_expresionUnaria = 63,           /* expresionUnaria  */
  YYSYMBOL_expresionSufija = 64,           /* expresionSufija  */
  YYSYMBOL_constante = 65,                 /* constante  */
  YYSYMBOL_parametrosActuales = 66,        /* parametrosActuales  */
  YYSYMBOL_listaParametrosActuales = 67,   /* listaParametrosActuales  */
  YYSYMBOL_operadorLogico = 68,            /* operadorLogico  */
  YYSYMBOL_operadorIgualdad = 69,          /* operadorIgualdad  */
  YYSYMBOL_operadorRelacional = 70,        /* operadorRelacional  */
  YYSYMBOL_operadorAditivo = 71,           /* operadorAditivo  */
  YYSYMBOL_operadorMultiplicativo = 72,    /* operadorMultiplicativo  */
  YYSYMBOL_operadorUnario = 73             /* operadorUnario  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   139

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    56,    57,    60,    61,    65,    73,    85,
      94,    95,   100,   110,   122,   122,   134,   135,   139,   146,
     154,   164,   165,   168,   169,   172,   173,   174,   175,   176,
     179,   188,   204,   222,   239,   242,   246,   247,   261,   262,
     274,   275,   288,   289,   301,   302,   315,   316,   328,   329,
     330,   339,   355,   370,   375,   376,   377,   380,   381,   384,
     385,   388,   389,   392,   393,   396,   397,   398,   399,   402,
     403,   406,   407,   410,   411,   412
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
  "\"end of file\"", "error", "\"invalid token\"", "ID_", "CTE_", "PUNT_",
  "COMA_", "FINL_", "WHILE_", "BOOL_", "STRUC_", "RETURN_", "READ_",
  "PRINT_", "IF_", "ELSE_", "APAR_", "CPAR_", "ABLOQ_", "CBLOQ_", "AIND_",
  "CIND_", "IGU_", "DIST_", "AND_", "OR_", "MAY_", "MEN_", "MAYIGU_",
  "MENORIGU_", "NOT_", "ASIG_", "MAS_", "MENOS_", "POR_", "DIV_", "INT_",
  "TRUE_", "FALSE_", "$accept", "programa", "listaDeclaraciones",
  "declaracion", "declaracionVariable", "tipoSimple", "listaCampos",
  "declaracionFuncion", "@1", "parametrosFormales",
  "listaParametrosFormales", "bloque", "declaracionVariableLocal",
  "listaInstrucciones", "instruccion", "instruccionAsignacion",
  "instruccionEntradaSalida", "instruccionSeleccion",
  "instruccionIteracion", "expresion", "expresionIgualdad",
  "expresionRelacional", "expresionAditiva", "expresionMultiplicativa",
  "expresionUnaria", "expresionSufija", "constante", "parametrosActuales",
  "listaParametrosActuales", "operadorLogico", "operadorIgualdad",
  "operadorRelacional", "operadorAditivo", "operadorMultiplicativo",
  "operadorUnario", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-85)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -8,   -85,   -12,   -85,    17,    -8,   -85,   -85,    48,   -85,
       5,   -85,   -85,    38,    61,    88,    -1,   -85,    76,    70,
      90,   100,   106,    89,     5,   -85,   104,   105,   107,   110,
      98,   -85,   -85,   -85,   -85,   111,   101,     5,   -85,   -85,
     -85,    -8,   -85,    48,    81,    16,   102,     0,   108,   109,
     -85,   -85,   -85,   -85,   -85,   -85,   113,     0,     0,     0,
       4,   -85,     0,   -85,   -85,   -85,   -85,   -85,    35,    39,
      47,   -10,    71,   -85,   -85,   -85,     0,   117,     0,    69,
      91,    77,    41,    29,   118,     0,     0,    32,   112,   -85,
     -85,     0,   -85,   -85,     0,   -85,   -85,   -85,   -85,     0,
     -85,   -85,     0,   -85,   -85,     0,   -85,   115,    54,   -85,
       0,    92,   -85,    82,   -85,     1,   116,   -85,    83,   -85,
     -85,    39,    47,   -10,    71,   -85,   119,    82,    43,     0,
     -85,     0,   -85,   -85,   -85,   114,   -85,    45,   -85,    82,
     -85,   -85
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,     0,    10,     0,     2,     3,     5,     0,     6,
       0,     1,     4,     0,     0,     0,     0,     7,     0,     0,
       0,     0,     0,     0,    16,    12,     0,     0,     0,     0,
       0,    17,     9,    13,     8,    18,     0,     0,    21,    15,
      19,    23,    22,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    26,    28,    27,    29,     0,     0,     0,     0,
      50,    54,     0,    75,    73,    74,    55,    56,     0,    36,
      38,    40,    42,    44,    46,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,    61,
      62,     0,    63,    64,     0,    65,    66,    67,    68,     0,
      69,    70,     0,    71,    72,     0,    47,     0,     0,    25,
       0,     0,    30,     0,    51,    59,     0,    58,     0,    49,
      20,    37,    39,    41,    43,    45,     0,     0,     0,     0,
      35,     0,    53,    52,    33,     0,    32,     0,    60,     0,
      31,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -85,   -85,   -85,   122,    87,     3,   -85,   -85,   -85,   -85,
      93,   -85,   -85,    84,   -84,   -85,   -85,   -85,   -85,   -47,
      44,    42,    40,    36,   -71,   -85,   -85,   -85,     6,   -85,
     -85,   -85,   -85,   -85,   -85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    16,     9,    14,    30,
      31,    39,    41,    44,    51,    52,    53,    54,    55,   115,
      69,    70,    71,    72,    73,    74,    75,   116,   117,    91,
      94,    99,   102,   105,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      68,     1,     2,    60,    61,   106,    10,   131,     1,    84,
      81,    82,    83,    15,     1,    87,    62,    11,    21,    22,
      85,    56,   100,   101,    86,    89,    90,    29,     3,   130,
      63,   108,    64,    65,   125,     3,    57,    66,    67,   118,
      29,     3,    88,   135,    43,    17,   113,    58,   112,   119,
     136,    13,   140,    89,    90,   141,    89,    90,    18,    89,
      90,    92,    93,   128,    19,    89,    90,    89,    90,    89,
      90,   127,    45,    95,    96,    97,    98,    46,    89,    90,
      23,    48,   137,    49,    45,    45,    24,    50,   109,    46,
      46,    20,    47,    48,    48,    49,    49,    25,   111,    50,
      50,    89,    90,    26,   133,   103,   104,    89,    90,    27,
      28,    32,    33,    35,    34,    36,    80,    37,    59,    38,
     107,   114,   110,   129,    77,    78,   134,    12,    42,   139,
      40,   120,   126,   132,    79,   121,   122,   138,   124,   123
};

static const yytype_uint8 yycheck[] =
{
      47,     9,    10,     3,     4,    76,    18,     6,     9,     5,
      57,    58,    59,    10,     9,    62,    16,     0,    19,    16,
      16,     5,    32,    33,    20,    24,    25,    24,    36,   113,
      30,    78,    32,    33,   105,    36,    20,    37,    38,    86,
      37,    36,     7,   127,    41,     7,    17,    31,     7,    17,
       7,     3,     7,    24,    25,   139,    24,    25,    20,    24,
      25,    22,    23,   110,     3,    24,    25,    24,    25,    24,
      25,    17,     3,    26,    27,    28,    29,     8,    24,    25,
       4,    12,   129,    14,     3,     3,    16,    18,    19,     8,
       8,     3,    11,    12,    12,    14,    14,     7,    21,    18,
      18,    24,    25,     3,    21,    34,    35,    24,    25,     3,
      21,     7,     7,     3,     7,    17,     3,     6,    16,    18,
       3,     3,    31,    31,    16,    16,     7,     5,    41,    15,
      37,    19,    17,    17,    50,    91,    94,   131,   102,    99
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    36,    40,    41,    42,    43,    44,    46,
      18,     0,    42,     3,    47,    44,    45,     7,    20,     3,
       3,    19,    44,     4,    16,     7,     3,     3,    21,    44,
      48,    49,     7,     7,     7,     3,    17,     6,    18,    50,
      49,    51,    43,    44,    52,     3,     8,    11,    12,    14,
      18,    53,    54,    55,    56,    57,     5,    20,    31,    16,
       3,     4,    16,    30,    32,    33,    37,    38,    58,    59,
      60,    61,    62,    63,    64,    65,    73,    16,    16,    52,
       3,    58,    58,    58,     5,    16,    20,    58,     7,    24,
      25,    68,    22,    23,    69,    26,    27,    28,    29,    70,
      32,    33,    71,    34,    35,    72,    63,     3,    58,    19,
      31,    21,     7,    17,     3,    58,    66,    67,    58,    17,
      19,    59,    60,    61,    62,    63,    17,    17,    58,    31,
      53,     6,    17,    21,     7,    53,     7,    58,    67,    15,
       7,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    43,    43,
      44,    44,    45,    45,    47,    46,    48,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      54,    54,    54,    55,    56,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      64,    64,    64,    64,    65,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    71,
      71,    72,    72,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     6,     6,
       1,     1,     3,     4,     0,     7,     0,     1,     2,     4,
       7,     0,     2,     0,     2,     3,     1,     1,     1,     1,
       4,     7,     6,     5,     7,     5,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     1,     3,
       1,     3,     4,     4,     1,     1,     1,     0,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
  case 2: /* programa: listaDeclaraciones  */
#line 53 "src/asin.y"
                              {niv=0;dvar=0;}
#line 1240 "asin.c"
    break;

  case 7: /* declaracionVariable: tipoSimple ID_ FINL_  */
#line 66 "src/asin.y"
{
/*Insertar variable con el tipo, si todo OK incrementar dvar */
if (!insTdS((yyvsp[-1].ident), VARIABLE, (yyvsp[-2].cent), niv,dvar,-1))
   yyerror("Identificador repetido"); 
else dvar += TALLA_TIPO_SIMPLE; 
}
#line 1251 "asin.c"
    break;

  case 8: /* declaracionVariable: tipoSimple ID_ AIND_ CTE_ CIND_ FINL_  */
#line 73 "src/asin.y"
                                        {
   int numelem = (yyvsp[-2].cent); /*Array length */
   if(numelem <= 0) {
      yyerror("Talla inapropiada del array");
      numelem = 0;
   }
   int refe = insTdA((yyvsp[-5].cent), numelem); /*Referencia en tabla de arrays */
   /*Insertar en tabla de simbolos e incrementar desplazamiento relativo si OK */
   if(!insTdS((yyvsp[-4].ident), VARIABLE, T_ARRAY, niv, dvar, refe))
      yyerror("Identificador repetido");
   else dvar += numelem * TALLA_TIPO_SIMPLE; 
}
#line 1268 "asin.c"
    break;

  case 9: /* declaracionVariable: STRUC_ ABLOQ_ listaCampos CBLOQ_ ID_ FINL_  */
#line 85 "src/asin.y"
                                             {
   if(!insTdS((yyvsp[-1].ident), VARIABLE, T_RECORD, niv, dvar, (yyvsp[-3].CampoRegistro.refe))) {
      yyerror("Identificador repetido");
   } else {
      dvar += (yyvsp[-3].CampoRegistro.desp_r);
   }/* Meter un else donde se incrementa el dvar en función de la listaCampos */
}
#line 1280 "asin.c"
    break;

  case 10: /* tipoSimple: INT_  */
#line 94 "src/asin.y"
                  {(yyval.cent) = T_ENTERO;}
#line 1286 "asin.c"
    break;

  case 11: /* tipoSimple: BOOL_  */
#line 95 "src/asin.y"
                   {(yyval.cent) = T_LOGICO;}
#line 1292 "asin.c"
    break;

  case 12: /* listaCampos: tipoSimple ID_ FINL_  */
#line 100 "src/asin.y"
                     {
   int refe = insTdR(-1, (yyvsp[-1].ident), (yyvsp[-2].cent), 0);
   if(refe == -1)
      yyerror("Campo ya existente en el registro");
   else {
      (yyval.CampoRegistro.refe) = refe;
      (yyval.CampoRegistro.desp_r) = TALLA_TIPO_SIMPLE; /*TALLA_TIPO_SIMPLE */
   };
}
#line 1306 "asin.c"
    break;

  case 13: /* listaCampos: listaCampos tipoSimple ID_ FINL_  */
#line 110 "src/asin.y"
                                 {
   int desp = (yyvsp[-3].CampoRegistro.desp_r);
   (yyval.CampoRegistro.refe) = (yyvsp[-3].CampoRegistro.refe);
   if (insTdR((yyvsp[-3].CampoRegistro.refe),(yyvsp[-1].ident), (yyvsp[-2].cent), desp) == -1)
      yyerror("Campo ya existente en el registro");
   else {
      (yyval.CampoRegistro.desp_r) = desp + TALLA_TIPO_SIMPLE; /* TALLA_TIPO_SIMPLE */
   }
}
#line 1320 "asin.c"
    break;

  case 14: /* @1: %empty  */
#line 122 "src/asin.y"
                                 {(yyval.cent) = dvar;dvar = 0;niv++;cargaContexto(niv);}
#line 1326 "asin.c"
    break;

  case 15: /* declaracionFuncion: tipoSimple @1 ID_ APAR_ parametrosFormales CPAR_ bloque  */
#line 122 "src/asin.y"
                                                                                                                                {
                           int aux = (yyval.cent);
                           if(!insTdS((yyvsp[-4].ident), FUNCION, (yyvsp[-6].cent), niv - 1, dvar, (yyvsp[-2].cent)))
                              yyerror("La función ya ha sido declarada de forma previa");
                           
                           if(verTdS)
                              mostrarTdS(); 
                           descargaContexto(niv);niv--;dvar = aux;
                     }
#line 1340 "asin.c"
    break;

  case 16: /* parametrosFormales: %empty  */
#line 134 "src/asin.y"
                     {(yyval.cent) = insTdD(-1, T_VACIO);}
#line 1346 "asin.c"
    break;

  case 17: /* parametrosFormales: listaParametrosFormales  */
#line 135 "src/asin.y"
                                              {(yyval.cent) = (yyvsp[0].ParamForm.refe);}
#line 1352 "asin.c"
    break;

  case 18: /* listaParametrosFormales: tipoSimple ID_  */
#line 139 "src/asin.y"
                                         {
                           (yyval.ParamForm.refe) = insTdD(-1, (yyvsp[-1].cent)); /*insertamos*/
                           (yyval.ParamForm.talla) += TALLA_TIPO_SIMPLE + TALLA_SEGENLACES; /*incrementamos talla */
                           if(!insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, -(yyval.ParamForm.talla), -1)) { /*insertamos parametro en la tabla de simbolos */
                              yyerror("Identificador del parametro repetido");
                           }
                        }
#line 1364 "asin.c"
    break;

  case 19: /* listaParametrosFormales: tipoSimple ID_ COMA_ listaParametrosFormales  */
#line 146 "src/asin.y"
                                                                       {
                           (yyval.ParamForm.talla) = TALLA_TIPO_SIMPLE + (yyvsp[0].ParamForm.talla); /*Nueva parametro, incrementamos talla */
                           (yyval.ParamForm.refe) = insTdD((yyvsp[0].ParamForm.refe),(yyvsp[-3].cent)); /* nos quedamos con la referencia del nuevo parametro */
                           if(!insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv,-(yyval.ParamForm.talla), -1)) /* insertamos TdS */
                              yyerror("Identificador de parametro repetido");
                        }
#line 1375 "asin.c"
    break;

  case 20: /* bloque: ABLOQ_ declaracionVariableLocal listaInstrucciones RETURN_ expresion FINL_ CBLOQ_  */
#line 155 "src/asin.y"
                                        {
            INF func = obtTdD(-1); /* Sacamos la info la de funcion actual */
            /* Los tipos que tienen que devolver coinciden */
            if (func.tipo != (yyvsp[-2].cent)) {
               yyerror("El valor de retorno no coincide con el de la declaración de la funcion");
            }
         }
#line 1387 "asin.c"
    break;

  case 54: /* constante: CTE_  */
#line 375 "src/asin.y"
                 {(yyval.cent) = T_ENTERO;}
#line 1393 "asin.c"
    break;

  case 55: /* constante: TRUE_  */
#line 376 "src/asin.y"
                  {(yyval.cent) = T_LOGICO;}
#line 1399 "asin.c"
    break;

  case 56: /* constante: FALSE_  */
#line 377 "src/asin.y"
                   {(yyval.cent) = T_LOGICO;}
#line 1405 "asin.c"
    break;

  case 73: /* operadorUnario: MAS_  */
#line 410 "src/asin.y"
                      {(yyval.cent) = T_ENTERO;}
#line 1411 "asin.c"
    break;

  case 74: /* operadorUnario: MENOS_  */
#line 411 "src/asin.y"
                        {(yyval.cent) = T_ENTERO;}
#line 1417 "asin.c"
    break;

  case 75: /* operadorUnario: NOT_  */
#line 412 "src/asin.y"
                      {(yyval.cent) = T_LOGICO;}
#line 1423 "asin.c"
    break;


#line 1427 "asin.c"

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

#line 414 "src/asin.y"
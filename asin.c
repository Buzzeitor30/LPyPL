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
#line 9 "src/asin.y"

#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
#include "libgci.h"

extern int yylineno;

#line 81 "asin.c"

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
  YYSYMBOL_PUNT_ = 3,                      /* PUNT_  */
  YYSYMBOL_COMA_ = 4,                      /* COMA_  */
  YYSYMBOL_FINL_ = 5,                      /* FINL_  */
  YYSYMBOL_WHILE_ = 6,                     /* WHILE_  */
  YYSYMBOL_INT_ = 7,                       /* INT_  */
  YYSYMBOL_BOOL_ = 8,                      /* BOOL_  */
  YYSYMBOL_STRUC_ = 9,                     /* STRUC_  */
  YYSYMBOL_RETURN_ = 10,                   /* RETURN_  */
  YYSYMBOL_READ_ = 11,                     /* READ_  */
  YYSYMBOL_PRINT_ = 12,                    /* PRINT_  */
  YYSYMBOL_IF_ = 13,                       /* IF_  */
  YYSYMBOL_ELSE_ = 14,                     /* ELSE_  */
  YYSYMBOL_APAR_ = 15,                     /* APAR_  */
  YYSYMBOL_CPAR_ = 16,                     /* CPAR_  */
  YYSYMBOL_ABLOQ_ = 17,                    /* ABLOQ_  */
  YYSYMBOL_CBLOQ_ = 18,                    /* CBLOQ_  */
  YYSYMBOL_AIND_ = 19,                     /* AIND_  */
  YYSYMBOL_CIND_ = 20,                     /* CIND_  */
  YYSYMBOL_IGU_ = 21,                      /* IGU_  */
  YYSYMBOL_DIST_ = 22,                     /* DIST_  */
  YYSYMBOL_AND_ = 23,                      /* AND_  */
  YYSYMBOL_OR_ = 24,                       /* OR_  */
  YYSYMBOL_MAY_ = 25,                      /* MAY_  */
  YYSYMBOL_MEN_ = 26,                      /* MEN_  */
  YYSYMBOL_MAYIGU_ = 27,                   /* MAYIGU_  */
  YYSYMBOL_MENORIGU_ = 28,                 /* MENORIGU_  */
  YYSYMBOL_NOT_ = 29,                      /* NOT_  */
  YYSYMBOL_ASIG_ = 30,                     /* ASIG_  */
  YYSYMBOL_MAS_ = 31,                      /* MAS_  */
  YYSYMBOL_MENOS_ = 32,                    /* MENOS_  */
  YYSYMBOL_POR_ = 33,                      /* POR_  */
  YYSYMBOL_DIV_ = 34,                      /* DIV_  */
  YYSYMBOL_TRUE_ = 35,                     /* TRUE_  */
  YYSYMBOL_FALSE_ = 36,                    /* FALSE_  */
  YYSYMBOL_ID_ = 37,                       /* ID_  */
  YYSYMBOL_CTE_ = 38,                      /* CTE_  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_programa = 40,                  /* programa  */
  YYSYMBOL_41_1 = 41,                      /* @1  */
  YYSYMBOL_listaDeclaraciones = 42,        /* listaDeclaraciones  */
  YYSYMBOL_declaracion = 43,               /* declaracion  */
  YYSYMBOL_declaracionVariable = 44,       /* declaracionVariable  */
  YYSYMBOL_tipoSimple = 45,                /* tipoSimple  */
  YYSYMBOL_listaCampos = 46,               /* listaCampos  */
  YYSYMBOL_declaracionFuncion = 47,        /* declaracionFuncion  */
  YYSYMBOL_48_2 = 48,                      /* @2  */
  YYSYMBOL_49_3 = 49,                      /* @3  */
  YYSYMBOL_parametrosFormales = 50,        /* parametrosFormales  */
  YYSYMBOL_listaParametrosFormales = 51,   /* listaParametrosFormales  */
  YYSYMBOL_bloque = 52,                    /* bloque  */
  YYSYMBOL_53_4 = 53,                      /* @4  */
  YYSYMBOL_54_5 = 54,                      /* $@5  */
  YYSYMBOL_declaracionVariableLocal = 55,  /* declaracionVariableLocal  */
  YYSYMBOL_listaInstrucciones = 56,        /* listaInstrucciones  */
  YYSYMBOL_instruccion = 57,               /* instruccion  */
  YYSYMBOL_instruccionAsignacion = 58,     /* instruccionAsignacion  */
  YYSYMBOL_instruccionEntradaSalida = 59,  /* instruccionEntradaSalida  */
  YYSYMBOL_instruccionSeleccion = 60,      /* instruccionSeleccion  */
  YYSYMBOL_61_6 = 61,                      /* @6  */
  YYSYMBOL_62_7 = 62,                      /* @7  */
  YYSYMBOL_instruccionIteracion = 63,      /* instruccionIteracion  */
  YYSYMBOL_64_8 = 64,                      /* @8  */
  YYSYMBOL_65_9 = 65,                      /* @9  */
  YYSYMBOL_expresion = 66,                 /* expresion  */
  YYSYMBOL_expresionIgualdad = 67,         /* expresionIgualdad  */
  YYSYMBOL_expresionRelacional = 68,       /* expresionRelacional  */
  YYSYMBOL_expresionAditiva = 69,          /* expresionAditiva  */
  YYSYMBOL_expresionMultiplicativa = 70,   /* expresionMultiplicativa  */
  YYSYMBOL_expresionUnaria = 71,           /* expresionUnaria  */
  YYSYMBOL_expresionSufija = 72,           /* expresionSufija  */
  YYSYMBOL_73_10 = 73,                     /* $@10  */
  YYSYMBOL_constante = 74,                 /* constante  */
  YYSYMBOL_parametrosActuales = 75,        /* parametrosActuales  */
  YYSYMBOL_listaParametrosActuales = 76,   /* listaParametrosActuales  */
  YYSYMBOL_operadorLogico = 77,            /* operadorLogico  */
  YYSYMBOL_operadorIgualdad = 78,          /* operadorIgualdad  */
  YYSYMBOL_operadorRelacional = 79,        /* operadorRelacional  */
  YYSYMBOL_operadorAditivo = 80,           /* operadorAditivo  */
  YYSYMBOL_operadorMultiplicativo = 81,    /* operadorMultiplicativo  */
  YYSYMBOL_operadorUnario = 82             /* operadorUnario  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

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
       0,    72,    72,    72,    98,    99,   104,   105,   110,   117,
     129,   140,   141,   146,   151,   166,   167,   165,   187,   188,
     193,   199,   211,   218,   211,   246,   247,   252,   253,   258,
     259,   260,   261,   262,   267,   277,   297,   319,   328,   338,
     344,   338,   356,   356,   356,   369,   370,   393,   394,   412,
     413,   432,   433,   449,   450,   466,   467,   480,   483,   486,
     496,   519,   538,   538,   569,   570,   571,   576,   577,   582,
     583,   590,   591,   596,   597,   602,   603,   604,   605,   610,
     611,   616,   617,   622,   623,   624
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
  "\"end of file\"", "error", "\"invalid token\"", "PUNT_", "COMA_",
  "FINL_", "WHILE_", "INT_", "BOOL_", "STRUC_", "RETURN_", "READ_",
  "PRINT_", "IF_", "ELSE_", "APAR_", "CPAR_", "ABLOQ_", "CBLOQ_", "AIND_",
  "CIND_", "IGU_", "DIST_", "AND_", "OR_", "MAY_", "MEN_", "MAYIGU_",
  "MENORIGU_", "NOT_", "ASIG_", "MAS_", "MENOS_", "POR_", "DIV_", "TRUE_",
  "FALSE_", "ID_", "CTE_", "$accept", "programa", "@1",
  "listaDeclaraciones", "declaracion", "declaracionVariable", "tipoSimple",
  "listaCampos", "declaracionFuncion", "@2", "@3", "parametrosFormales",
  "listaParametrosFormales", "bloque", "@4", "$@5",
  "declaracionVariableLocal", "listaInstrucciones", "instruccion",
  "instruccionAsignacion", "instruccionEntradaSalida",
  "instruccionSeleccion", "@6", "@7", "instruccionIteracion", "@8", "@9",
  "expresion", "expresionIgualdad", "expresionRelacional",
  "expresionAditiva", "expresionMultiplicativa", "expresionUnaria",
  "expresionSufija", "$@10", "constante", "parametrosActuales",
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

#define YYPACT_NINF (-100)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-63)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -100,     1,    98,  -100,  -100,  -100,     3,    98,  -100,  -100,
     -11,  -100,    40,  -100,     0,     6,    43,  -100,    26,    50,
      80,    52,    63,    90,    40,  -100,   108,   109,   110,    79,
     101,  -100,  -100,  -100,  -100,   114,  -100,    40,  -100,  -100,
    -100,   102,  -100,    98,  -100,    83,    -4,     0,  -100,    31,
     106,   107,   111,  -100,     8,  -100,  -100,  -100,  -100,  -100,
     112,    31,  -100,  -100,  -100,  -100,  -100,    71,  -100,   -20,
      57,    76,    77,    78,  -100,  -100,  -100,    31,    86,    31,
      31,     4,    87,    31,    31,    31,    59,    88,    31,   113,
    -100,  -100,   124,    31,  -100,  -100,    31,  -100,  -100,  -100,
    -100,    31,  -100,  -100,    31,  -100,  -100,    31,  -100,   115,
      64,    68,  -100,   100,    73,    47,   -20,  -100,  -100,    75,
      31,   116,    57,    76,    77,    78,  -100,   127,   128,  -100,
      31,   105,  -100,   120,  -100,    33,   121,  -100,  -100,  -100,
    -100,    12,    49,    31,    12,    31,  -100,  -100,  -100,    53,
    -100,  -100,   125,  -100,    12,  -100
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    11,    12,     0,     3,     4,     6,
       0,     7,     0,     5,    15,     0,     0,     8,     0,     0,
       0,     0,     0,     0,    18,    13,     0,     0,     0,     0,
       0,    19,    10,    14,     9,    20,    16,     0,    22,    21,
      17,     0,    25,    27,    26,     0,     0,     0,    42,     0,
       0,     0,     0,    27,     0,    28,    30,    32,    31,    33,
       0,     0,    85,    83,    84,    65,    66,    59,    64,    23,
      45,    47,    49,    51,    53,    55,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    72,     0,     0,    73,    74,     0,    75,    76,    77,
      78,     0,    79,    80,     0,    81,    82,     0,    56,     0,
       0,     0,    29,     0,     0,     0,    43,    58,    60,     0,
      67,     0,    46,    48,    50,    52,    54,     0,     0,    39,
       0,     0,    34,     0,    61,    69,     0,    68,    24,    37,
      38,     0,     0,     0,     0,     0,    63,    40,    36,     0,
      44,    70,     0,    35,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,  -100,  -100,   131,    97,    16,  -100,  -100,  -100,
    -100,  -100,   104,  -100,  -100,  -100,  -100,    89,   -99,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,   -49,    51,    54,
      42,    41,   -63,  -100,  -100,  -100,  -100,     2,  -100,  -100,
    -100,  -100,  -100,  -100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,     8,     9,    10,    16,    11,    19,
      38,    30,    31,    40,    41,    92,    43,    46,    55,    56,
      57,    58,   141,   152,    59,    60,   133,   135,    70,    71,
      72,    73,    74,    75,    89,    76,   136,   137,    93,    96,
     101,   104,   107,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,     3,    48,    90,    91,    17,    49,    50,    51,    52,
      48,    82,    86,    53,   108,    50,    51,    52,    48,    18,
      12,    53,   112,    50,    51,    52,    14,    83,    15,    53,
     110,   111,    22,    54,   114,   115,   116,   145,    84,   119,
      29,    54,   147,    20,   126,   150,    61,     4,     5,    54,
       4,     5,   132,    29,   148,   155,    90,    91,   153,    45,
      62,    21,    63,    64,    23,    24,    65,    66,    67,    68,
      90,    91,    90,    91,    87,   117,    90,    91,    94,    95,
     128,   142,    90,    91,   129,    25,   -62,    90,    91,    26,
      88,    90,    91,   131,   149,   134,    90,    91,    90,    91,
      27,    97,    98,    99,   100,     4,     5,     6,   102,   103,
      28,   105,   106,    32,    33,    34,    35,    36,    37,    42,
      47,    78,    79,   109,   113,   118,    80,    85,   120,   121,
     130,   127,   139,   140,   138,   143,   144,   146,    13,   154,
      44,    39,    81,   124,   122,   125,     0,   151,     0,     0,
     123
};

static const yytype_int16 yycheck[] =
{
      49,     0,     6,    23,    24,     5,    10,    11,    12,    13,
       6,     3,    61,    17,    77,    11,    12,    13,     6,    19,
      17,    17,    18,    11,    12,    13,    37,    19,    12,    17,
      79,    80,    16,    37,    83,    84,    85,     4,    30,    88,
      24,    37,   141,    37,   107,   144,    15,     7,     8,    37,
       7,     8,     5,    37,     5,   154,    23,    24,     5,    43,
      29,    18,    31,    32,    38,    15,    35,    36,    37,    38,
      23,    24,    23,    24,     3,    16,    23,    24,    21,    22,
      16,   130,    23,    24,    16,     5,    15,    23,    24,    37,
      19,    23,    24,    20,   143,    20,    23,    24,    23,    24,
      37,    25,    26,    27,    28,     7,     8,     9,    31,    32,
      20,    33,    34,     5,     5,     5,    37,    16,     4,    17,
      37,    15,    15,    37,    37,    37,    15,    15,    15,     5,
      30,    16,     5,     5,    18,    30,    16,    16,     7,    14,
      43,    37,    53,   101,    93,   104,    -1,   145,    -1,    -1,
      96
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,    41,     0,     7,     8,     9,    42,    43,    44,
      45,    47,    17,    43,    37,    45,    46,     5,    19,    48,
      37,    18,    45,    38,    15,     5,    37,    37,    20,    45,
      50,    51,     5,     5,     5,    37,    16,     4,    49,    51,
      52,    53,    17,    55,    44,    45,    56,    37,     6,    10,
      11,    12,    13,    17,    37,    57,    58,    59,    60,    63,
      64,    15,    29,    31,    32,    35,    36,    37,    38,    66,
      67,    68,    69,    70,    71,    72,    74,    82,    15,    15,
      15,    56,     3,    19,    30,    15,    66,     3,    19,    73,
      23,    24,    54,    77,    21,    22,    78,    25,    26,    27,
      28,    79,    31,    32,    80,    33,    34,    81,    71,    37,
      66,    66,    18,    37,    66,    66,    66,    16,    37,    66,
      15,     5,    67,    68,    69,    70,    71,    16,    16,    16,
      30,    20,     5,    65,    20,    66,    75,    76,    18,     5,
       5,    61,    66,    30,    16,     4,    16,    57,     5,    66,
      57,    76,    62,     5,    14,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    41,    40,    42,    42,    43,    43,    44,    44,
      44,    45,    45,    46,    46,    48,    49,    47,    50,    50,
      51,    51,    53,    54,    52,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    58,    58,    58,    59,    59,    61,
      62,    60,    64,    65,    63,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    72,    72,    72,
      72,    72,    73,    72,    74,    74,    74,    75,    75,    76,
      76,    77,    77,    78,    78,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     6,
       6,     1,     1,     3,     4,     0,     0,     8,     0,     1,
       2,     4,     0,     0,     9,     0,     2,     0,     2,     3,
       1,     1,     1,     1,     4,     7,     6,     5,     5,     0,
       0,     9,     0,     0,     7,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     2,     1,     3,     1,
       3,     4,     0,     5,     1,     1,     1,     0,     1,     1,
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
  case 2: /* @1: %empty  */
#line 72 "src/asin.y"
            {
        niv=0;
        dvar=0;
        si=0;
        cargaContexto(niv);
        /****Variables globales****/
        (yyval.prog).arg1 = creaLans(si);
        emite(INCTOP,crArgNul(),crArgNul(),crArgEnt(-1)); /*variables globales, pero no sabemos aun cuantas tenemos*/
        /****Salto a main******/
        (yyval.prog).arg2 = creaLans(si);
        emite(GOTOS,crArgNul(),crArgNul(),crArgEtq(-1)); /*hay que saltar al main, pero no sabemos si tendra o donde esta*/
}
#line 1274 "asin.c"
    break;

  case 3: /* programa: @1 listaDeclaraciones  */
#line 83 "src/asin.y"
                     {
                SIMB main = obtTdS("main"); /*sacamos la funcion main*/
                if((yyvsp[0].cent) == 0)
                    yyerror("El programa no tiene \"main\"");
                else if((yyvsp[0].cent) > 1)
                    yyerror("El programa tiene mas de un \"main\"");
                /* else todo ok :) */
                /****Completar variables globales**/
                completaLans((yyvsp[-1].prog).arg1, crArgEnt(dvar));
                /*saltamos al main*/
                completaLans((yyvsp[-1].prog).arg2, crArgEtq(main.d));
            }
#line 1291 "asin.c"
    break;

  case 4: /* listaDeclaraciones: declaracion  */
#line 98 "src/asin.y"
                                 {(yyval.cent) = (yyvsp[0].cent);}
#line 1297 "asin.c"
    break;

  case 5: /* listaDeclaraciones: listaDeclaraciones declaracion  */
#line 99 "src/asin.y"
                                                    {(yyval.cent) = (yyvsp[-1].cent) + (yyvsp[0].cent);}
#line 1303 "asin.c"
    break;

  case 6: /* declaracion: declaracionVariable  */
#line 104 "src/asin.y"
                                  {(yyval.cent) = 0;}
#line 1309 "asin.c"
    break;

  case 7: /* declaracion: declaracionFuncion  */
#line 105 "src/asin.y"
                                 {(yyval.cent) = (yyvsp[0].cent);}
#line 1315 "asin.c"
    break;

  case 8: /* declaracionVariable: tipoSimple ID_ FINL_  */
#line 110 "src/asin.y"
                                           {
                            if(!insTdS((yyvsp[-1].ident), VARIABLE, (yyvsp[-2].cent), niv, dvar, -1)) {
                                yyerror("Identificador variable repetido");
                            }
                            else
                                dvar += TALLA_TIPO_SIMPLE;
                        }
#line 1327 "asin.c"
    break;

  case 9: /* declaracionVariable: tipoSimple ID_ AIND_ CTE_ CIND_ FINL_  */
#line 117 "src/asin.y"
                                                              {
                            int numelem = (yyvsp[-2].cent); /*Array length */
                            if(numelem <= 0) {
                                yyerror("Talla inapropiada del array");
                                numelem = 0;
                            }
                            int refe = insTdA((yyvsp[-5].cent), numelem); /*Referencia en tabla de arrays*/
                            /*Insertar en tabla de simbolos e incrementar desplazamiento relativo si OK */
                            if(!insTdS((yyvsp[-4].ident), VARIABLE, T_ARRAY, niv, dvar, refe))
                                yyerror("Identificador repetido");
                            else dvar += numelem * TALLA_TIPO_SIMPLE;
                        }
#line 1344 "asin.c"
    break;

  case 10: /* declaracionVariable: STRUC_ ABLOQ_ listaCampos CBLOQ_ ID_ FINL_  */
#line 129 "src/asin.y"
                                                                   {
                            if(!insTdS((yyvsp[-1].ident), VARIABLE, T_RECORD, niv, dvar, (yyvsp[-3].CampoRegistro).refe)) {
                                yyerror("Identificador repetido");
                            } else {
                                dvar += (yyvsp[-3].CampoRegistro).desp_r;
                            }
                        }
#line 1356 "asin.c"
    break;

  case 11: /* tipoSimple: INT_  */
#line 140 "src/asin.y"
                     {(yyval.cent)=T_ENTERO;}
#line 1362 "asin.c"
    break;

  case 12: /* tipoSimple: BOOL_  */
#line 141 "src/asin.y"
                      {(yyval.cent)=T_LOGICO;}
#line 1368 "asin.c"
    break;

  case 13: /* listaCampos: tipoSimple ID_ FINL_  */
#line 146 "src/asin.y"
                                    {
                    /* NO PUEDE DAR ERROR, NO HACE FALTA COMPROBAR NADA */
                    (yyval.CampoRegistro).refe = insTdR(-1, (yyvsp[-1].ident), (yyvsp[-2].cent), 0);/*creamos campo de registro*/
                    (yyval.CampoRegistro).desp_r = TALLA_TIPO_SIMPLE; /*incrementar desplazamiento */
                }
#line 1378 "asin.c"
    break;

  case 14: /* listaCampos: listaCampos tipoSimple ID_ FINL_  */
#line 151 "src/asin.y"
                                                 {
                    (yyval.CampoRegistro).refe = (yyvsp[-3].CampoRegistro).refe; /* pillamos valor antes */
                    (yyval.CampoRegistro).desp_r = (yyvsp[-3].CampoRegistro).desp_r; /*desplazamiento (AKA talla diapositivas)*/
                    if (insTdR((yyvsp[-3].CampoRegistro).refe,(yyvsp[-1].ident), (yyvsp[-2].cent), (yyvsp[-3].CampoRegistro).desp_r) == -1)
                        yyerror("Campo ya existente en el registro");
                    else {
                        (yyval.CampoRegistro).refe = (yyvsp[-3].CampoRegistro).refe;
                        (yyval.CampoRegistro).desp_r = (yyvsp[-3].CampoRegistro).desp_r + TALLA_TIPO_SIMPLE; /*incrementamos desplazamiento puesto que hay un campo nuevo*/
                    }   
                }
#line 1393 "asin.c"
    break;

  case 15: /* @2: %empty  */
#line 166 "src/asin.y"
                        {(yyval.cent) = dvar;dvar = 0;niv++;cargaContexto(niv);}
#line 1399 "asin.c"
    break;

  case 16: /* @3: %empty  */
#line 167 "src/asin.y"
                                                      {
                            if(!insTdS((yyvsp[-4].ident), FUNCION, (yyvsp[-5].cent), niv - 1, si, (yyvsp[-1].cent)))
                                yyerror("Identificador de función repetido");
                            if(strcmp((yyvsp[-4].ident), "main") == 0)
                                (yyval.cent) = 1;
                            else 
                                (yyval.cent) = 0;
                        }
#line 1412 "asin.c"
    break;

  case 17: /* declaracionFuncion: tipoSimple ID_ @2 APAR_ parametrosFormales CPAR_ @3 bloque  */
#line 175 "src/asin.y"
                               {
                            if(verTdS)
                                mostrarTdS();
                            descargaContexto(niv);niv--;
                            dvar = (yyvsp[-5].cent);
                            (yyval.cent) =  (yyvsp[-1].cent);

                        }
#line 1425 "asin.c"
    break;

  case 18: /* parametrosFormales: %empty  */
#line 187 "src/asin.y"
                        {(yyval.cent) = insTdD(-1, T_VACIO);}
#line 1431 "asin.c"
    break;

  case 19: /* parametrosFormales: listaParametrosFormales  */
#line 188 "src/asin.y"
                                                {(yyval.cent) = (yyvsp[0].ParamForm).refe;}
#line 1437 "asin.c"
    break;

  case 20: /* listaParametrosFormales: tipoSimple ID_  */
#line 193 "src/asin.y"
                                          {
                                (yyval.ParamForm).refe = insTdD(-1, (yyvsp[-1].cent));
                                (yyval.ParamForm).talla = TALLA_TIPO_SIMPLE + TALLA_SEGENLACES;
                                if(!insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, -(yyval.ParamForm).talla, -1))
                                    yyerror("Identificador del parametro repetido");
                        }
#line 1448 "asin.c"
    break;

  case 21: /* listaParametrosFormales: tipoSimple ID_ COMA_ listaParametrosFormales  */
#line 199 "src/asin.y"
                                                                         {
                                (yyval.ParamForm).talla = (yyvsp[0].ParamForm).talla; /*Nueva parametro, incrementamos talla*/
                                (yyval.ParamForm).refe = insTdD((yyvsp[0].ParamForm).refe,(yyvsp[-3].cent)); /* nos quedamos con la referencia del nuevo parametro*/
                                if(!insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv,-((yyval.ParamForm).talla + TALLA_TIPO_SIMPLE), -1))
                                    yyerror("Identificador del parametro repetido");
                                else
                                    (yyval.ParamForm).talla += TALLA_TIPO_SIMPLE;
                        }
#line 1461 "asin.c"
    break;

  case 22: /* @4: %empty  */
#line 211 "src/asin.y"
           {
            emite(PUSHFP,crArgNul(),crArgNul(),crArgNul()); /* apilamos fp en la pila */
            emite(TOPFP,crArgNul(),crArgNul(),crArgNul()); /* movemos fp arriba del todo de la pila */
            /*variables locales y temporales*/
            (yyval.cent) = creaLans(si); /*cuantas variables temporales y vocales hay */
            emite(INCTOP,crArgNul(),crArgNul(),crArgEnt(-1));
}
#line 1473 "asin.c"
    break;

  case 23: /* $@5: %empty  */
#line 218 "src/asin.y"
                      {
            INF func = obtTdD(-1);
            /* espacio para las variables reservado OK */
            completaLans((yyvsp[-5].cent),crArgEnt(dvar));
            /* valor retorno,mirar el tema 5, basicamente es la funcion que hay en la diapo 5*/
            int accvalret = - (TALLA_SEGENLACES + func.tsp + TALLA_TIPO_SIMPLE);
            emite(EASIG,crArgPos(niv, (yyvsp[0].exp).desp),crArgNul(),crArgPos(niv,accvalret));
            /*liberar segmento de variables locales y temporales */
            emite(TOPFP, crArgNul(),crArgNul(),crArgEnt(dvar)); /*desapilamos variables temporales y locales*/
            /*desapilar enlaces de control*/
            emite(FPPOP,crArgNul(),crArgNul(),crArgNul());

            if(func.tipo == T_ERROR) {
                yyerror("Error en declaracion de funcion");
            }
            else if((yyvsp[0].exp).tipo != T_ERROR && func.tipo != (yyvsp[0].exp).tipo)
                yyerror("Error de tipos del \"return\"");

            if(strcmp(func.nom,"main") == 0)
                emite(FIN,crArgNul(),crArgNul(),crArgNul()); /* fin del programa */
            else
                emite(RET,crArgNul(),crArgNul(),crArgNul()); /*return de una funcion */
            }
#line 1501 "asin.c"
    break;

  case 34: /* instruccionAsignacion: ID_ ASIG_ expresion FINL_  */
#line 267 "src/asin.y"
                                                 {
                        SIMB sym = obtTdS((yyvsp[-3].ident)); /*sacamos la estructura con el nombre de la variable*/
                        if((yyvsp[-1].exp).tipo != T_ERROR) {
                            if(sym.t == T_ERROR) {
                            yyerror("Objeto no declarado");
                            } else if(sym.t != (yyvsp[-1].exp).tipo && (yyvsp[-1].exp).tipo != T_ERROR)
                            yyerror("Error de tipos en la \"asignacion\"");
                            }
                        emite(EASIG,crArgPos(niv,(yyvsp[-1].exp).desp),crArgNul(),crArgPos(sym.n,sym.d)); /*asignacion */
                        }
#line 1516 "asin.c"
    break;

  case 35: /* instruccionAsignacion: ID_ AIND_ expresion CIND_ ASIG_ expresion FINL_  */
#line 277 "src/asin.y"
                                                                       {
                            /* Sacamos simbolo e informacion del array dado el simbolo*/
                            SIMB sym = obtTdS((yyvsp[-6].ident));
                            DIM dim = obtTdA(sym.ref);
                            if ((yyvsp[-4].exp).tipo != T_ERROR && (yyvsp[-1].exp).tipo != T_ERROR) {
                                if(sym.t == T_ERROR) {
                                    yyerror("Objeto no declarado");
                                }else if(sym.t != T_ARRAY) { /* Tenemos que tratar con un array */
                                    yyerror("El identificador debe ser de tipo \"array\"");
                                } else {
                                    if((yyvsp[-4].exp).tipo != T_ENTERO) { /* Se accede a los indicies con enteros */
                                        yyerror("El índice del \"array\" debe ser entero");
                                    } 
                                    else if((yyvsp[-1].exp).tipo != dim.telem) { /* La asignacion no coincide con el tipo del array */
                                        yyerror("Error de tipos en la \"asignacion\"");
                                    } 
                                }
                            }
                            emite(EVA,crArgPos(sym.n,sym.d),crArgPos(niv,(yyvsp[-4].exp).desp),crArgPos(niv,(yyvsp[-1].exp).desp));
                        }
#line 1541 "asin.c"
    break;

  case 36: /* instruccionAsignacion: ID_ PUNT_ ID_ ASIG_ expresion FINL_  */
#line 297 "src/asin.y"
                                                            {
                            SIMB sym = obtTdS((yyvsp[-5].ident));
                            CAMP camp = obtTdR(sym.ref, (yyvsp[-3].ident));
                            if((yyvsp[-1].exp).tipo != T_ERROR) {
                                if(sym.t == T_ERROR)
                                    yyerror("Objeto no declarado");
                                else if(sym.t != T_RECORD)
                                    yyerror("El identificador debe ser de tipo \"struct\"");
                                else {
                                    if(camp.t == T_ERROR)
                                    	yyerror("Campo no declarado");
                                    else if(camp.t != (yyvsp[-1].exp).tipo)
                                        yyerror("Error de tipos en la \"asignacion\"");
                                }
                                int d = sym.d + camp.d; /*sumamos desplazamientos*/
                                emite(EASIG,crArgPos(niv,(yyvsp[-1].exp).desp),crArgNul(),crArgPos(sym.n,d));
                            }
                      }
#line 1564 "asin.c"
    break;

  case 37: /* instruccionEntradaSalida: READ_ APAR_ ID_ CPAR_ FINL_  */
#line 319 "src/asin.y"
                                                      {
                            SIMB sym = obtTdS((yyvsp[-2].ident));
                            if(sym.t == T_ERROR) {
                                yyerror("Objeto no declarado");
                            } else if(sym.t != T_ENTERO) {
                                yyerror("El argumento de \"read\" debe ser \"entero\"");
                            }
                            emite(EREAD,crArgNul(),crArgNul(),crArgPos(sym.n, sym.d));
                        }
#line 1578 "asin.c"
    break;

  case 38: /* instruccionEntradaSalida: PRINT_ APAR_ expresion CPAR_ FINL_  */
#line 328 "src/asin.y"
                                                              {
                           if((yyvsp[-2].exp).tipo != T_ENTERO) {
                              yyerror("La expresion del \"print\" debe ser entera");
                           }
                           emite(EWRITE,crArgNul(),crArgNul(),crArgPos(niv, (yyvsp[-2].exp).desp));
                         }
#line 1589 "asin.c"
    break;

  case 39: /* @6: %empty  */
#line 338 "src/asin.y"
                                                {
                        if((yyvsp[-1].exp).tipo != T_LOGICO && (yyvsp[-1].exp).tipo != T_ERROR)
                            yyerror("La expresion del \"if\" debe ser \"logico\"");
                        (yyval.cent) = creaLans(si); /*creamos la LANS*/
                        emite(EIGUAL,crArgEnt(0), crArgPos(niv,(yyvsp[-1].exp).desp), crArgEtq(-1)); /*-1 para rellenar */
                        }
#line 1600 "asin.c"
    break;

  case 40: /* @7: %empty  */
#line 344 "src/asin.y"
                                    {
                            (yyval.cent) = creaLans(si);
                            emite(GOTOS,crArgNul(),crArgNul(),crArgEtq(-1)); /*-1 para rellenar*/
                            completaLans((yyvsp[-1].cent), crArgEtq(si)); /*saltamos en caso de ELSE */
                        }
#line 1610 "asin.c"
    break;

  case 41: /* instruccionSeleccion: IF_ APAR_ expresion CPAR_ @6 instruccion @7 ELSE_ instruccion  */
#line 349 "src/asin.y"
                                          {
                            completaLans((yyvsp[-2].cent), crArgEtq(si)); /*donde saltamos al final y despues del IF*/
                        }
#line 1618 "asin.c"
    break;

  case 42: /* @8: %empty  */
#line 356 "src/asin.y"
                              { (yyval.cent) = si; /*direccion de expresion*/}
#line 1624 "asin.c"
    break;

  case 43: /* @9: %empty  */
#line 356 "src/asin.y"
                                                                                           {
                        if((yyvsp[0].exp).tipo != T_LOGICO && (yyvsp[0].exp).tipo != T_ERROR)
                            yyerror("La expresion del \"while\" debe ser \"logico\"");
                        (yyval.cent) = creaLans(si); /*nos guardamos la dir. del emite */
                        emite(EIGUAL,crArgEnt(0),crArgPos(niv,(yyvsp[0].exp).desp),crArgEtq(-1)); /*-1 ara rellenar*/
                        }
#line 1635 "asin.c"
    break;

  case 44: /* instruccionIteracion: WHILE_ @8 APAR_ expresion @9 CPAR_ instruccion  */
#line 361 "src/asin.y"
                                            {
                        emite(GOTOS,crArgNul(),crArgNul(),crArgEtq((yyvsp[-5].cent))); /*saltamos al inicio del bucle */
                        completaLans((yyvsp[-2].cent),crArgEtq(si));/*completa la lista, tiene que saltar fuera */
                        }
#line 1644 "asin.c"
    break;

  case 45: /* expresion: expresionIgualdad  */
#line 369 "src/asin.y"
                              {(yyval.exp) = (yyvsp[0].exp);}
#line 1650 "asin.c"
    break;

  case 46: /* expresion: expresion operadorLogico expresionIgualdad  */
#line 370 "src/asin.y"
                                                       {
                if ((yyvsp[-2].exp).tipo == T_ERROR || (yyvsp[0].exp).tipo == T_ERROR) 
                   (yyval.exp).tipo = T_ERROR;
                else if(!((yyvsp[-2].exp).tipo == T_LOGICO && (yyvsp[-2].exp).tipo == (yyvsp[0].exp).tipo)) {
                    (yyval.exp).tipo = T_ERROR;
                    yyerror("Error en \"expresion logica\"");
                }
                else
                    (yyval.exp).tipo = T_LOGICO;
                
                (yyval.exp).desp = creaVarTemp();
                emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].exp).desp), crArgPos(niv, (yyvsp[0].exp).desp), crArgPos(niv, (yyval.exp).desp));
                if((yyvsp[-1].cent) == ESUM) {
                    /* if $$ <= 1 then goto si + 2 (diapositivas) */
                    emite(EMENEQ, crArgPos(niv, (yyval.exp).desp), crArgEnt(1), crArgEtq(si + 2));
                    /*asignacion por si la suma da mayor que uno */
                    emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, (yyval.exp).desp));
                }
          }
#line 1674 "asin.c"
    break;

  case 47: /* expresionIgualdad: expresionRelacional  */
#line 393 "src/asin.y"
                                        {(yyval.exp) = (yyvsp[0].exp);}
#line 1680 "asin.c"
    break;

  case 48: /* expresionIgualdad: expresionIgualdad operadorIgualdad expresionRelacional  */
#line 394 "src/asin.y"
                                                                           {
                        if((yyvsp[-2].exp).tipo == T_ERROR || (yyvsp[0].exp).tipo == T_ERROR)
                            (yyval.exp).tipo = T_ERROR;
                        else if(!(((yyvsp[-2].exp).tipo == T_LOGICO && (yyvsp[-2].exp).tipo == (yyvsp[0].exp).tipo) || ((yyvsp[-2].exp).tipo == T_ENTERO && (yyvsp[-2].exp).tipo == (yyvsp[0].exp).tipo) )) {
                            (yyval.exp).tipo = T_ERROR;
                            yyerror("Error en \"expresion de igualdad\"");
                        } else {
                            (yyval.exp).tipo = T_LOGICO;
                        }
                        (yyval.exp).desp = creaVarTemp();
                        emite(EASIG,crArgEnt(1),crArgNul(), crArgPos(niv, (yyval.exp).desp));
                        emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].exp).desp), crArgPos(niv, (yyvsp[0].exp).desp), crArgEtq(si + 2));
                        emite(EASIG,crArgEnt(0),crArgNul(), crArgPos(niv, (yyval.exp).desp));
                  }
#line 1699 "asin.c"
    break;

  case 49: /* expresionRelacional: expresionAditiva  */
#line 412 "src/asin.y"
                                       {(yyval.exp) = (yyvsp[0].exp);}
#line 1705 "asin.c"
    break;

  case 50: /* expresionRelacional: expresionRelacional operadorRelacional expresionAditiva  */
#line 413 "src/asin.y"
                                                                              {
                        if((yyvsp[-2].exp).tipo == T_ERROR || (yyvsp[0].exp).tipo == T_ERROR)
                           (yyval.exp).tipo = T_ERROR;
                        else if(!((yyvsp[-2].exp).tipo == T_ENTERO && (yyvsp[-2].exp).tipo == (yyvsp[0].exp).tipo)) {
                           (yyval.exp).tipo = T_ERROR;
                           yyerror("Error en \"expresion relacional\"");
                        } else 
                           (yyval.exp).tipo = T_LOGICO;

                        (yyval.exp).desp = creaVarTemp();
                        /*asumimos que es true la expresion, si se cumple saltamos, si no se cumple es false y por tanto 0 */
                        emite(EASIG,crArgEnt(1),crArgNul(), crArgPos(niv, (yyval.exp).desp));
                        emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].exp).desp), crArgPos(niv, (yyvsp[0].exp).desp), crArgEtq(si + 2));
                        emite(EASIG,crArgEnt(0),crArgNul(), crArgPos(niv, (yyval.exp).desp));                        
                    }
#line 1725 "asin.c"
    break;

  case 51: /* expresionAditiva: expresionMultiplicativa  */
#line 432 "src/asin.y"
                                            {(yyval.exp) = (yyvsp[0].exp);}
#line 1731 "asin.c"
    break;

  case 52: /* expresionAditiva: expresionAditiva operadorAditivo expresionMultiplicativa  */
#line 433 "src/asin.y"
                                                                             {
                        if((yyvsp[-2].exp).tipo == T_ERROR || (yyvsp[0].exp).tipo == T_ERROR)
                            (yyval.exp).tipo = T_ERROR;
                        else if((yyvsp[-2].exp).tipo != T_ENTERO || (yyvsp[0].exp).tipo != T_ENTERO) {
                            (yyval.exp).tipo = T_ERROR;
                            yyerror("Error en \"expresion aditiva\"");
                        } else 
                            (yyval.exp).tipo = T_ENTERO;
                        
                        (yyval.exp).desp = creaVarTemp();
                        emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].exp).desp), crArgPos(niv, (yyvsp[0].exp).desp), crArgPos(niv, (yyval.exp).desp));
                 }
#line 1748 "asin.c"
    break;

  case 53: /* expresionMultiplicativa: expresionUnaria  */
#line 449 "src/asin.y"
                                          {(yyval.exp) = (yyvsp[0].exp);}
#line 1754 "asin.c"
    break;

  case 54: /* expresionMultiplicativa: expresionMultiplicativa operadorMultiplicativo expresionUnaria  */
#line 450 "src/asin.y"
                                                                                         {
                            if((yyvsp[-2].exp).tipo == T_ERROR || (yyvsp[0].exp).tipo == T_ERROR)
                              (yyval.exp).tipo = T_ERROR;
                            else if((yyvsp[-2].exp).tipo != T_ENTERO || (yyvsp[0].exp).tipo != T_ENTERO) {
                              (yyval.exp).tipo = T_ERROR;
                              yyerror("Error en \"expresion multiplicativa\"");
                            }
                            else {
                              (yyval.exp).tipo = T_ENTERO;
                            }

                        }
#line 1771 "asin.c"
    break;

  case 55: /* expresionUnaria: expresionSufija  */
#line 466 "src/asin.y"
                                  {(yyval.exp) = (yyvsp[0].exp);}
#line 1777 "asin.c"
    break;

  case 56: /* expresionUnaria: operadorUnario expresionUnaria  */
#line 467 "src/asin.y"
                                                 {
                    if((yyvsp[0].exp).tipo == T_ERROR)
                        (yyval.exp).tipo = (yyvsp[0].exp).tipo;
                    else if((yyvsp[-1].cent) != (yyvsp[0].exp).tipo) {
                        yyerror("Error en \"expresion unaria\"");
                        (yyval.exp).tipo = T_ERROR;
                    }else
                        (yyval.exp).tipo = (yyvsp[0].exp).tipo;
                }
#line 1791 "asin.c"
    break;

  case 57: /* expresionSufija: constante  */
#line 480 "src/asin.y"
                            {
                    (yyval.exp) = (yyvsp[0].exp);
                }
#line 1799 "asin.c"
    break;

  case 58: /* expresionSufija: APAR_ expresion CPAR_  */
#line 483 "src/asin.y"
                                        {
                    (yyval.exp) = (yyvsp[-1].exp);
                }
#line 1807 "asin.c"
    break;

  case 59: /* expresionSufija: ID_  */
#line 486 "src/asin.y"
                      {
                    SIMB sym = obtTdS((yyvsp[0].ident));
                    if(sym.t == T_ERROR) {
                        (yyval.exp).tipo = T_ERROR;
                    }else
                        (yyval.exp).tipo = sym.t;

                    (yyval.exp).desp = creaVarTemp();
                    emite(EASIG, crArgPos(sym.n, sym.d), crArgNul(), crArgPos(niv, (yyval.exp).desp));
                  }
#line 1822 "asin.c"
    break;

  case 60: /* expresionSufija: ID_ PUNT_ ID_  */
#line 496 "src/asin.y"
                                {
                    SIMB sym = obtTdS((yyvsp[-2].ident));
                    CAMP camp = obtTdR(sym.ref, (yyvsp[0].ident));
                    /*¿ERROR?*/
                    if(sym.t == T_ERROR) {
                        yyerror("Objeto no declarado");
                        (yyval.exp).tipo = T_ERROR;
                    } else if(sym.t != T_RECORD) { /*¿Estructura*/
                        yyerror("El identificador debe ser de tipo \"struct\"");
                        (yyval.exp).tipo = T_ERROR;
                    } else {
                        if (camp.t == T_ERROR) { /*¿Campo declarado?*/
                            yyerror("Campo no declarado");
                            (yyval.exp).tipo = T_ERROR;
                        } else {
                            (yyval.exp).tipo = camp.t;
                        }
                    }
                    int d = sym.d + camp.d;
                    (yyval.exp).desp = creaVarTemp();
                    emite(EASIG,crArgEnt(d), crArgNul(), crArgPos(niv, (yyval.exp).desp));
                    
                }
#line 1850 "asin.c"
    break;

  case 61: /* expresionSufija: ID_ AIND_ expresion CIND_  */
#line 519 "src/asin.y"
                                            {
                    SIMB sym = obtTdS((yyvsp[-3].ident));
                    DIM dim = obtTdA(sym.ref);
                    if(sym.t == T_ERROR) { /*¿Error? */
                        yyerror("Objeto no declarado");
                        (yyval.exp).tipo = T_ERROR;
                    } else if(sym.t != T_ARRAY) { /* ¿Array */
                        yyerror("El identificador debe ser de tipo \"array\"");
                        (yyval.exp).tipo = T_ERROR;
                    } else if((yyvsp[-1].exp).tipo != T_ENTERO) { /* Indice entero */
                        yyerror("El indice del \"array\" debe ser entero");
                        (yyval.exp).tipo = T_ERROR;
                    }  else {
                        (yyval.exp).tipo = dim.telem;
                    }
                    /* no hace falta la primera instruccion del temario, la talla de todos los tipos es 1 */
                    (yyval.exp).desp = creaVarTemp();
                    emite(EAV, crArgPos(sym.n,sym.d), crArgPos(niv, (yyvsp[-1].exp).desp), crArgPos(niv, (yyval.exp).desp));
                }
#line 1874 "asin.c"
    break;

  case 62: /* $@10: %empty  */
#line 538 "src/asin.y"
                      { 
                    /***reservar espacio para el valor de retorno**/
                    emite(INCTOP,crArgNul(),crArgNul(),crArgEnt(TALLA_TIPO_SIMPLE));
                    }
#line 1883 "asin.c"
    break;

  case 63: /* expresionSufija: ID_ $@10 APAR_ parametrosActuales CPAR_  */
#line 542 "src/asin.y"
                                               {
                    SIMB sym = obtTdS((yyvsp[-4].ident));
                    INF inf = obtTdD(sym.ref);
                    (yyval.exp).tipo = T_ERROR; /* si no llega hasta el ultimo else se queda esto */
                    if(sym.t == T_ERROR)
                        yyerror("Objeto no declarado");
                    else {   
                        if (inf.tipo == T_ERROR) 
                            yyerror("El identificador no es una funcion");
                        else if (cmpDom(sym.ref, (yyvsp[-1].cent)) == 0)
                            yyerror("El dominio de los parametros actuales no coincide con el de la funcion");
                        else
                            (yyval.exp).tipo = inf.tipo;
                    }
                    (yyval.exp).desp = creaVarTemp();
                    /**llamada a la funcion**/
                    emite(CALL, crArgNul(), crArgNul(), crArgEtq(sym.d));
                    /** desapilar segmento de parametros**/
                    emite(DECTOP,crArgNul(),crArgNul(),crArgEnt(inf.tsp));
                    /**desapilar y asignar valor de retorno*/
                    emite(EPOP,crArgNul(),crArgNul(),crArgPos(niv, (yyval.exp).desp));

                }
#line 1911 "asin.c"
    break;

  case 64: /* constante: CTE_  */
#line 569 "src/asin.y"
                 {(yyval.exp).tipo = T_ENTERO; (yyval.exp).desp=creaVarTemp();emite(EASIG,crArgEnt((yyvsp[0].cent)),crArgNul(),crArgPos(niv,(yyval.exp).desp));}
#line 1917 "asin.c"
    break;

  case 65: /* constante: TRUE_  */
#line 570 "src/asin.y"
                  {(yyval.exp).tipo = T_LOGICO; (yyval.exp).desp=creaVarTemp();emite(EASIG,crArgEnt(1),crArgNul(),crArgPos(niv,(yyval.exp).desp));}
#line 1923 "asin.c"
    break;

  case 66: /* constante: FALSE_  */
#line 571 "src/asin.y"
                   {(yyval.exp).tipo = T_LOGICO; (yyval.exp).desp=creaVarTemp();emite(EASIG,crArgEnt(0),crArgNul(),crArgPos(niv,(yyval.exp).desp));}
#line 1929 "asin.c"
    break;

  case 67: /* parametrosActuales: %empty  */
#line 576 "src/asin.y"
                     {(yyval.cent) = insTdD(-1, T_VACIO);}
#line 1935 "asin.c"
    break;

  case 68: /* parametrosActuales: listaParametrosActuales  */
#line 577 "src/asin.y"
                                             {(yyval.cent) = (yyvsp[0].cent);}
#line 1941 "asin.c"
    break;

  case 69: /* listaParametrosActuales: expresion  */
#line 582 "src/asin.y"
                                    {(yyval.cent) = insTdD(-1, (yyvsp[0].exp).tipo);}
#line 1947 "asin.c"
    break;

  case 70: /* listaParametrosActuales: expresion COMA_ listaParametrosActuales  */
#line 583 "src/asin.y"
                                                                  {
                            (yyval.cent) = insTdD((yyvsp[0].cent), (yyvsp[-2].exp).tipo); 
                        }
#line 1955 "asin.c"
    break;

  case 71: /* operadorLogico: AND_  */
#line 590 "src/asin.y"
                      {(yyval.cent) = EMULT;}
#line 1961 "asin.c"
    break;

  case 72: /* operadorLogico: OR_  */
#line 591 "src/asin.y"
                     {(yyval.cent) = ESUM;}
#line 1967 "asin.c"
    break;

  case 73: /* operadorIgualdad: IGU_  */
#line 596 "src/asin.y"
                        {(yyval.cent) = EIGUAL;}
#line 1973 "asin.c"
    break;

  case 74: /* operadorIgualdad: DIST_  */
#line 597 "src/asin.y"
                         {(yyval.cent) = EDIST;}
#line 1979 "asin.c"
    break;

  case 75: /* operadorRelacional: MAY_  */
#line 602 "src/asin.y"
                          {(yyval.cent) = EMAY;}
#line 1985 "asin.c"
    break;

  case 76: /* operadorRelacional: MEN_  */
#line 603 "src/asin.y"
                          {(yyval.cent) = EMEN;}
#line 1991 "asin.c"
    break;

  case 77: /* operadorRelacional: MAYIGU_  */
#line 604 "src/asin.y"
                             {(yyval.cent) = EMAYEQ;}
#line 1997 "asin.c"
    break;

  case 78: /* operadorRelacional: MENORIGU_  */
#line 605 "src/asin.y"
                               {(yyval.cent) = EMENEQ;}
#line 2003 "asin.c"
    break;

  case 79: /* operadorAditivo: MAS_  */
#line 610 "src/asin.y"
                       {(yyval.cent) = ESUM;}
#line 2009 "asin.c"
    break;

  case 80: /* operadorAditivo: MENOS_  */
#line 611 "src/asin.y"
                         {(yyval.cent) = EDIF;}
#line 2015 "asin.c"
    break;

  case 81: /* operadorMultiplicativo: POR_  */
#line 616 "src/asin.y"
                              {(yyval.cent) = EMULT;}
#line 2021 "asin.c"
    break;

  case 82: /* operadorMultiplicativo: DIV_  */
#line 617 "src/asin.y"
                              {(yyval.cent) = EDIVI;}
#line 2027 "asin.c"
    break;

  case 83: /* operadorUnario: MAS_  */
#line 622 "src/asin.y"
                      {(yyval.cent) = T_ENTERO;}
#line 2033 "asin.c"
    break;

  case 84: /* operadorUnario: MENOS_  */
#line 623 "src/asin.y"
                        {(yyval.cent) = T_ENTERO;}
#line 2039 "asin.c"
    break;

  case 85: /* operadorUnario: NOT_  */
#line 624 "src/asin.y"
                      {(yyval.cent) = T_LOGICO;}
#line 2045 "asin.c"
    break;


#line 2049 "asin.c"

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

#line 626 "src/asin.y"


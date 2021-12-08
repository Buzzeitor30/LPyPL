/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PUNT_ = 258,                   /* PUNT_  */
    COMA_ = 259,                   /* COMA_  */
    FINL_ = 260,                   /* FINL_  */
    WHILE_ = 261,                  /* WHILE_  */
    INT_ = 262,                    /* INT_  */
    BOOL_ = 263,                   /* BOOL_  */
    STRUC_ = 264,                  /* STRUC_  */
    RETURN_ = 265,                 /* RETURN_  */
    READ_ = 266,                   /* READ_  */
    PRINT_ = 267,                  /* PRINT_  */
    IF_ = 268,                     /* IF_  */
    ELSE_ = 269,                   /* ELSE_  */
    APAR_ = 270,                   /* APAR_  */
    CPAR_ = 271,                   /* CPAR_  */
    ABLOQ_ = 272,                  /* ABLOQ_  */
    CBLOQ_ = 273,                  /* CBLOQ_  */
    AIND_ = 274,                   /* AIND_  */
    CIND_ = 275,                   /* CIND_  */
    IGU_ = 276,                    /* IGU_  */
    DIST_ = 277,                   /* DIST_  */
    AND_ = 278,                    /* AND_  */
    OR_ = 279,                     /* OR_  */
    MAY_ = 280,                    /* MAY_  */
    MEN_ = 281,                    /* MEN_  */
    MAYIGU_ = 282,                 /* MAYIGU_  */
    MENORIGU_ = 283,               /* MENORIGU_  */
    NOT_ = 284,                    /* NOT_  */
    ASIG_ = 285,                   /* ASIG_  */
    MAS_ = 286,                    /* MAS_  */
    MENOS_ = 287,                  /* MENOS_  */
    POR_ = 288,                    /* POR_  */
    DIV_ = 289,                    /* DIV_  */
    TRUE_ = 290,                   /* TRUE_  */
    FALSE_ = 291,                  /* FALSE_  */
    ID_ = 292,                     /* ID_  */
    CTE_ = 293                     /* CTE_  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "src/asin.y"

   char *ident; /* Nombre del id. */
   int cent; /* Valor de la cte. numérica */
   struct {
      int refe; /*referencia en la TdR */
      int desp_r; /* desplazamiento relativo en la TdR */
   } CampoRegistro; /* estructura para insertar un campo en la TdR */
   struct {
      int refe; /*referencia*/
      int talla; /*talla parametros */
   } ParamForm; /*estructura como ayuda para los parametros */

#line 115 "asin.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ASIN_H_INCLUDED  */

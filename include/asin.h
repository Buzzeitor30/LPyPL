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
    ID_ = 258,                     /* ID_  */
    CTE_ = 259,                    /* CTE_  */
    PUNT_ = 260,                   /* PUNT_  */
    COMA_ = 261,                   /* COMA_  */
    FINL_ = 262,                   /* FINL_  */
    WHILE_ = 263,                  /* WHILE_  */
    BOOL_ = 264,                   /* BOOL_  */
    STRUC_ = 265,                  /* STRUC_  */
    RETURN_ = 266,                 /* RETURN_  */
    READ_ = 267,                   /* READ_  */
    PRINT_ = 268,                  /* PRINT_  */
    IF_ = 269,                     /* IF_  */
    ELSE_ = 270,                   /* ELSE_  */
    APAR_ = 271,                   /* APAR_  */
    CPAR_ = 272,                   /* CPAR_  */
    ABLOQ_ = 273,                  /* ABLOQ_  */
    CBLOQ_ = 274,                  /* CBLOQ_  */
    AIND_ = 275,                   /* AIND_  */
    CIND_ = 276,                   /* CIND_  */
    IGU_ = 277,                    /* IGU_  */
    DIST_ = 278,                   /* DIST_  */
    AND_ = 279,                    /* AND_  */
    OR_ = 280,                     /* OR_  */
    MAY_ = 281,                    /* MAY_  */
    MEN_ = 282,                    /* MEN_  */
    MAYIGU_ = 283,                 /* MAYIGU_  */
    MENORIGU_ = 284,               /* MENORIGU_  */
    NOT_ = 285,                    /* NOT_  */
    ASIG_ = 286,                   /* ASIG_  */
    MAS_ = 287,                    /* MAS_  */
    MENOS_ = 288,                  /* MENOS_  */
    POR_ = 289,                    /* POR_  */
    DIV_ = 290,                    /* DIV_  */
    INT_ = 291,                    /* INT_  */
    TRUE_ = 292,                   /* TRUE_  */
    FALSE_ = 293                   /* FALSE_  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "src/asin.y"

   char *ident; /* Nombre del id. */
   int cent; /* Valor de la cte. numérica */

#line 107 "asin.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ASIN_H_INCLUDED  */

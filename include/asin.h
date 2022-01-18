/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
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
    PUNT_ = 258,
    COMA_ = 259,
    FINL_ = 260,
    WHILE_ = 261,
    INT_ = 262,
    BOOL_ = 263,
    STRUC_ = 264,
    RETURN_ = 265,
    READ_ = 266,
    PRINT_ = 267,
    IF_ = 268,
    ELSE_ = 269,
    APAR_ = 270,
    CPAR_ = 271,
    ABLOQ_ = 272,
    CBLOQ_ = 273,
    AIND_ = 274,
    CIND_ = 275,
    IGU_ = 276,
    DIST_ = 277,
    AND_ = 278,
    OR_ = 279,
    MAY_ = 280,
    MEN_ = 281,
    MAYIGU_ = 282,
    MENORIGU_ = 283,
    NOT_ = 284,
    ASIG_ = 285,
    MAS_ = 286,
    MENOS_ = 287,
    POR_ = 288,
    DIV_ = 289,
    TRUE_ = 290,
    FALSE_ = 291,
    ID_ = 292,
    CTE_ = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "src/asin.y"

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
   struct {
      int tipo; /*tipo de la expresion*/
      int desp; /* desplazamiento en memoria */
   } exp; /*expresiones */
   struct {
       int arg1; /*argumento de LANS*/
       int arg2; /*argumento de LANS*/
   } prog;

#line 117 "asin.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */

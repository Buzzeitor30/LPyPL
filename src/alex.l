/* ********************************************** 
   *************ANÁLISIS LÉXICO *****************
   ***********ELIAS URIOS ALACREU****************
   ********************************************** */

%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "asin.h"

#define  retornar(x) {if (verbosidad) ECHO; return x;}
%}
/* Evitar "warnings" innecesarios */
%option noinput
%option nounput
/* Guardar numero de linea */
%option yylineno

delimitador     [ \t\n]+
digito          [0-9]
/*Los comentarios comienzan con //, tienen lo que sea y acaban con salto de línea */
comentario      "//".*\n
/*Varios digitos constituye un entero*/
entero          {digito}+
id              [a-z][A-Za-z0-9\-]*


%%
"true"          {retornar(TRUE_)}
"false"         {retornar(FALSE_)}
"while"         {retornar(WHILE_)}
"int"           {retornar(INT_)}
"bool"          {retornar(BOOL_)}
"struct"        {retornar(STRUC_)}
"return"        {retornar(RETURN_)}
"read"          {retornar(READ_)}
"print"         {retornar(PRINT_)}
"if"            {retornar(IF_)}
"else"          {retornar(ELSE_)}
{id}            {retornar(ID_)}
{entero}        {retornar(CTE_)}
{delimitador}   {if(verbosidad) ECHO;}
{comentario}    {if(verbosidad) ECHO;}
"."             {retornar(PUNT_)}
","             {retornar(COMA_)}
";"             {retornar(FINL_)}
"["             {retornar(AIND_)}
"]"             {retornar(CIND_)}
"("             {retornar(APAR_)}
")"             {retornar(CPAR_)}
"{"             {retornar(ABLOQ_)}
"}"             {retornar(CBLOQ_)}
"=="            {retornar(IGU_)}
"!="            {retornar(DIST_)}
"&&"            {retornar(AND_)}
"||"            {retornar(OR_)}
">"             {retornar(MAY_)}
"<"             {retornar(MEN_)}
">="            {retornar(MAYIGU_)}
"<="            {retornar(MENORIGU_)}
"="             {retornar(ASIG_)}
"+"             {retornar(MAS_)}
"-"             {retornar(MENOS_)}
"*"             {retornar(POR_)}
"/"             {retornar(DIV_)}
"!"             {retornar(NOT_)}
.               {yyerror("Caracter desconocido");}
%%

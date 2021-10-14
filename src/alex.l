/* ********************************************** 
   *************ANÁLISIS LÉXICO *****************
   ***********ELIAS URIOS ALACREU****************
   ********************************************** */

%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "asin.h"

#define  retornar(x) {if (verbosidad)  ECHO; return x;}
%}
/* Evitar "warnings" innecesarios */
%option noinput
%option nounput
/* Guardar numero de linea */
%option yylineno

delimitador     [ \t]+
digito          [0-9]
/*Los comentarios comienzan con //, tienen lo que sea y acaban con salto de línea */
comentario      "//".*\n
/*Un entero son 1 o más digitos, y un real tiene 0..* digitos a la izquierda del
"." y luego tiene 1 o más dígitos */
entero          {digito}+
real            {digito}*"."{digito}+
/*Una constante es o un entero o un real */
constante       {entero}|{real}
/*Los identificadores pueden empezar por mayusucula o minuscula, y luego pueden venir digitos, letras
y el símbolo "-"" */
id              [A-Za-z][A-Za-z0-9\-]*


%%
"true"          {retornar(TRUE_)}
"false"         {retornar(FALSE_)}
"int"           {retornar(INT_)}
"bool"          {retornar(BOOL_)}
"while"         {retornar(WHILE_)}
"struct"        {retornar(STRUC_)}
"return"        {retornar(RETURN_)}
"read"          {retornar(READ_)}
"print"         {retornar(PRINT_)}
"if"            {retornar(IF_)}
"else"          {retornar(ELSE_)}
"\n"            {if(verbosidad) {ECHO;fprintf(stdout,"%3d.- ", yylineno);}}

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

{id}            {retornar(ID_)}
{constante}     {retornar(CTE_)}

{delimitador}   {if(verbosidad) ECHO;}
{comentario}    {if(verbosidad) {ECHO;fprintf(stdout,"%3d.- ", yylineno);}}
.               {yyerror("Caracter desconocido");}
<<EOF>>         if(verbosidad) {fprintf(stdout,"\n"); return 0;}
%%

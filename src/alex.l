/* ********************************************** 
   *************ANÁLISIS LÉXICO *****************
   ***********ELIAS URIOS ALACREU****************
   ********************************************** */

%{
#include <stdio.h>
#include <string.h>
#include "header.h"

#define  retornar(x) {if (verbosidad) ECHO; }
%}
/* ********************************************** 
   *************ANÁLISIS LÉXICO *****************
   ***********ELIAS URIOS ALACREU****************
   ********************************************** */
%option noinput
%option nounput
%option yylineno

delimitador     [ \t\n]+
digito          [0-9]
entero          {digito}+
mayus           [A-Z]
minus           [a-z]
id              [a-z][A-Za-z0-9\-]*
%%
{entero}        {retornar(CTE_)}
{delimitador}   {if(verbosidad) ECHO;}
";"             {retornar(FINL_)}
"while"         {retornar(IGU_)}
"int"           {retornar(INT_)}
"bool"          {retornar(BOOL_)}
"struct"        {retornar(STRUC_)}
"return"        {retornar(RETURN_)}
"read"          {retornar(READ_)}
"print"         {retornar(PRINT_)}
"if"            {retornar(IF_)}
"else"          {retornar(ELSE_)}
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
.               {yyerror("Caracter desconocido");}
%%

int verbosidad = FALSE;

void yyerror(const char *msg) {
    fprintf(stderr, "Error en la linea %d: %s\n", yylineno, msg);
}

int main(int argc, char **argv)
/* Gestiona la linea de comandos e invoca al analizador sintactico-semantico.*/
{ int i, n=1 ;

  for (i=1; i<argc; ++i)
    if (strcmp(argv[i], "-v")==0) { verbosidad = TRUE; n++; }
  if (argc == n+1)
    if ((yyin = fopen (argv[n], "r")) == NULL) {
      fprintf (stderr, "El fichero '%s' no es valido\n", argv[n]) ;
      fprintf (stderr, "Uso: cmc [-v] fichero\n");
    }
    else yylex ();
  else fprintf (stderr, "Uso: cmc [-v] fichero\n");

  return (0);
}

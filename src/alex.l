%{
#include <stdio.h>
#include <string.h>
#include "header.h"

#define  retornar(x) {if (verbosidad) ECHO; }
%}

%option noinput
%option nounput
%option yylineno

delimitador     [ \t\n]+
digito          [0-9]
entero          {digito}+
mayus           [A-Z]
minus           [a-z]
id              {minus}[{mayus}a-z0-9\-]*
%%
{entero}        {retornar(CTE_)}
{id}            {retornar(ID_)}
{delimitador}   {if(verbosidad) ECHO;}
"+"             {retornar(MAS_)}
"-"             {retornar(MENOS_)}
"*"             {retornar(POR_)}
"/"             {retornar(DIV_)}
"("             {retornar(APAR_)}
")"             {retornar(CPAR_)}
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

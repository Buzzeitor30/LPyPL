/* ********************************************** 
   ***********ANÁLISIS SINTÁCTICO****************
   ***********ELIAS URIOS ALACREU****************
   ********************************************** */

%{
#include <stdio.h>
#include <string.h>
#include "header.h"

extern int yylineno;
%}
%define parse.error verbose
%token CTE_ PUNT_ COMA_ FINL_
%token WHILE_ INT_ BOOL_ STRUC_ RETURN_
%token READ_ PRINT_ IF_ ELSE_ AIND_ CIND_
%token APAR_ CPAR_ ABLOQ_ CBLOQ_ IGU_ DIST_
%token AND_ OR_ MAY_ MEN_ MAYIGU_ MENORIGU_
%token ASIG_ MAS_ MENOS_ POR_ DIV_ NOT_ ID_
%token TRUE_ FALSE_


%%

programa : listaDeclaraciones
         ;

listaDeclaraciones : declaracion
                   | listaDeclaraciones declaracion 
                   ;

declaracion : declaracionVariable 
            | declaracionFuncion
            ;

declaracionVariable : tipoSimple ID_ FINL_ 
                    | tipoSimple ID_ AIND_ CTE_ CIND_ FINL_
                    | STRUC_ ABLOQ_ listaCampos CBLOQ_ ID_ FINL_
                    ;

tipoSimple : INT_ 
           | BOOL_
           ;

listaCampos : tipoSimple ID_ FINL_
            | listaCampos tipoSimple ID_ FINL_
            ;

declaracionFuncion : tipoSimple ID_ APAR_ parametrosFormales CPAR_ bloque
                   ;

parametrosFormales :  | listaParametrosFormales
                   ;

listaParametrosFormales : tipoSimple ID_ 
                        | tipoSimple ID_ COMA_ listaParametrosFormales
                        ;

bloque : ABLOQ_ declaracionVariableLocal listaInstrucciones 
         RETURN_ expresion FINL_ CBLOQ_

declaracionVariableLocal :  
                         | declaracionVariableLocal declaracionVariable
                         ;

listaInstrucciones :  | listaInstrucciones instruccion 
                   ;

instruccion : ABLOQ_ listaInstrucciones CBLOQ_ 
            | instruccionAsignacion
            | instruccionSeleccion
            | instruccionEntradaSalida
            | instruccionIteracion
            ;

instruccionAsignacion : ID_ ASIG_ expresion FINL_
                      | ID_ AIND_ expresion CIND_ ASIG_ expresion FINL_
                      | ID_ PUNT_ ID_ ASIG_ expresion FINL_
                      ;

instruccionEntradaSalida : READ_ APAR_ ID_ CPAR_ FINL_ 
                         | PRINT_ APAR_ expresion CPAR_ FINL_
                         ;

instruccionSeleccion : IF_ APAR_ expresion CPAR_ instruccion ELSE_ instruccion
                     ;

instruccionIteracion : WHILE_ APAR_ expresion CPAR_ instruccion
                     ;

expresion : expresionIgualdad 
          | expresion operadorLogico expresionIgualdad
          ;

expresionIgualdad : expresionRelacional
                  | expresionIgualdad operadorIgualdad expresionRelacional
                  ;

expresionRelacional : expresionAditiva
                    | expresionRelacional operadorRelacional expresionAditiva
                    ;

expresionAditiva : expresionMultiplicativa 
                 | expresionAditiva operadorAditivo expresionMultiplicativa
                 ;

expresionMultiplicativa : expresionUnaria 
                        | expresionMultiplicativa operadorMultiplicativo expresionUnaria
                        ;

expresionUnaria : expresionSufija 
                | operadorUnario expresionUnaria
                ;

expresionSufija : constante 
                | APAR_ expresion CPAR_ 
                | ID_
                | ID_ PUNT_ ID_
                | ID_ AIND_ expresion CIND_
                | ID_ APAR_ parametrosActuales CPAR_
                ;

constante : CTE_
          | TRUE_
          | FALSE_
          ;

parametrosActuales :  
                   | listaParametrosActuales
                   ;

listaParametrosActuales : expresion
                        | expresion COMA_ listaParametrosActuales
                        ;

operadorLogico : AND_
               | OR_
               ;

operadorIgualdad : IGU_
                 | DIST_
                 ;

operadorRelacional : MAY_
                   | MEN_
                   | MAYIGU_
                   | MENORIGU_
                   ;

operadorAditivo : MAS_
                | MENOS_
                ;

operadorMultiplicativo : POR_
                       | DIV_
                       ;

operadorUnario : MAS_
               | MENOS_
               | NOT_

%%

int verbosidad = FALSE;

void yyerror(const char *msg) {
    fprintf(stderr, "Error en la linea %d: %s\n", yylineno, msg);
}

int main(int argc, char **argv) {
    int i, n=1;

    for(i=1; i < argc; ++i) {
        if(strcmp(argv[i], "-v") == 0) {
            verbosidad = TRUE;
            n++;
        }
    }
    if(argc == n+1) {
        if((yyin = fopen(argv[n], "r")) == NULL) {
            fprintf(stderr, "El fichero '%s' no es válido\n", argv[n]);
        }else {
            yyparse();
        }
    } else {
        fprintf(stderr, "Uso: cmc [-v] fichero\n");
    }
    return(0);
}

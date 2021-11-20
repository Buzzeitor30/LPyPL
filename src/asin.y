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

%union{
   char *ident; /* Nombre del id. */
   int cent; /* Valor de la cte. numérica */
}

/*PUNTO, COMA Y PUNTO Y COMA */
%token PUNT_ COMA_ FINL_
/* PALABRAS RESERVADAS */
%token WHILE_ BOOL_ STRUC_ RETURN_ READ_ PRINT_ IF_ ELSE_
/* INDICES, BLOQUES Y PARENTESIS*/
%token APAR_ CPAR_ ABLOQ_ CBLOQ_ AIND_ CIND_
/* OPERADORES LÓGICOS */
%token IGU_ DIST_ AND_ OR_ MAY_ MEN_ MAYIGU_ MENORIGU_ NOT_
/* ASIGNACION Y OPERADORES ARITMÉTICOS */
%token ASIG_ MAS_ MENOS_ POR_ DIV_
/*CONSTANTE E IDENTIFICADOR*/
%token ID_ CTE_
/* TIPOS SIMPLES*/
%token  INT_ TRUE_ FALSE_
%type <cent> tipoSimple

/* GRAMATICA COPIADA DIRECTAMENTE DEL BOLETÍN */
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
{
/*Insertar variable con el tipo, si todo OK incrementar dvar */
if (!insTds($2, VARIABLE, $1, niv,dvar,-1))
   yyerror("Identificador repetido"); 
else dvar += TALLA_TIPO_SIMPLE;
}

| tipoSimple ID_ AIND_ CTE_ CIND_ FINL_ {
   int numelem = $4; /*Array length */
   if(numelem <= 0) {
      yyerror("Talla inapropiada del array");
      numelem = 0;
   }
   int refe = insTdA($1, numelem); /*Referencia en tabla de arrays */
   /*Insertar en tabla de simbolos e incrementar desplazamiento relativo si OK */
   if(!insTds($2, VARIABLE, T_ARRAY, niv, dvar, refe))
      yerrror("Identificador repetido");
   else dvar += numelem * TALLA_TIPO_SIMPLE;
}

| STRUC_ ABLOQ_ listaCampos CBLOQ_ ID_ FINL_ {
   if(!insTds($2, VARIABLE, T_RECORD, niv, dvar, $3)) {
      yyerror("Identificador repetido");
   } /* Meter un else donde se incrementa el dvar en función de la listaCampos */
};

tipoSimple : INT_ {$<cent>$ = TIPO_ENTERO;}
           | BOOL_ {$<cent>$ = T_LOGICO;}
           ;

listaCampos : 
tipoSimple ID_ FINL_ {
   if(! insTdR(-1, $2, $1, ))
}
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
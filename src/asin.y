/* ********************************************** 
   ***********ANÁLISIS SINTÁCTICO****************
   ***********ELIAS URIOS ALACREU****************
   ********************************************** */

%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
extern int yylineno;

%}

%union{
   char *ident; /* Nombre del id. */
   int cent; /* Valor de la cte. numérica */
   struct {
      int refe;
      int desp_r;
   } CampoRegistro;
}

/*CONSTANTE E IDENTIFICADOR*/
%token <ident> ID_
%token <cent> CTE_
/*PUNTO, COMA Y PUNTO Y COMA */
%token PUNT_ COMA_ FINL_
/* PALABRAS RESERVADAS */
%token WHILE_ BOOL_ STRUC_ RETURN_ READ_ PRINT_ IF_ ELSE_
/* INDICES, BLOQUES Y PARENTESIS*/
%token APAR_ CPAR_ ABLOQ_ CBLOQ_ AIND_ CIND_
/* OPERADORES LÓGICOS*/
%token IGU_ DIST_ AND_ OR_ MAY_ MEN_ MAYIGU_ MENORIGU_ NOT_
/* ASIGNACION Y OPERADORES ARITMÉTICOS */
%token ASIG_ MAS_ MENOS_ POR_ DIV_
/* TIPOS SIMPLES*/
%token  INT_ TRUE_ FALSE_
%type <CampoRegistro> listaCampos
%type <cent> tipoSimple parametrosFormales instruccionAsignacion constante expresion expresionIgualdad

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

/** HECHO **/
declaracionVariable : tipoSimple ID_ FINL_ 
{
/*Insertar variable con el tipo, si todo OK incrementar dvar */
if (!insTdS($2, VARIABLE, $1, niv,dvar,-1))
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
   if(!insTdS($2, VARIABLE, T_ARRAY, niv, dvar, refe))
      yyerror("Identificador repetido");
   else dvar += numelem * TALLA_TIPO_SIMPLE; 
}
| STRUC_ ABLOQ_ listaCampos CBLOQ_ ID_ FINL_ {
   if(!insTdS($5, VARIABLE, T_RECORD, niv, dvar, $<CampoRegistro.refe>3)) {
      yyerror("Identificador repetido");
   } /* Meter un else donde se incrementa el dvar en función de la listaCampos */
};

/* HECHO */
tipoSimple : INT_ {$$ = T_ENTERO;}
           | BOOL_ {$$ = T_LOGICO;}
           ;

/* HECHO */
listaCampos : 
tipoSimple ID_ FINL_ {
   int refe = insTdR(-1, $2, $1, 0);
   if(refe == -1)
      yyerror("Campo ya existente en el registro");
   else {
      $<CampoRegistro.refe>$ = refe;
      $<CampoRegistro.desp_r>$ = TALLA_TIPO_SIMPLE; /*TALLA_TIPO_SIMPLE */
   };
}
| 
listaCampos tipoSimple ID_ FINL_ {
   int desp = $<CampoRegistro.desp_r>1;
   $<CampoRegistro.refe>$ = $<CampoRegistro.refe>1;
   if (insTdR($<CampoRegistro.refe>1,$3, $2, desp) == -1)
      yyerror("Campo ya existente en el registro");
   else {
      $<CampoRegistro.desp_r>$ = desp + TALLA_TIPO_SIMPLE; /* TALLA_TIPO_SIMPLE */
   }
}
;
/* TODO */
                     /* nivel para variables locales                                                  descargamos contexto y reestablecemos nivel*/ 
declaracionFuncion :  {niv=1;cargaContexto(1);} tipoSimple ID_ APAR_ parametrosFormales CPAR_ bloque {descargaContexto(niv);niv=0;} {
                           if(!insTdS($3, FUNCION, $2, 0, dvar, $5))
                              yyerror("La función ya ha sido declarada de forma previa");
                     }
                   ;

/* TODO */
parametrosFormales : {$$ = insTdD(-1, T_VACIO);}  
                   | listaParametrosFormales /* {$$ = $1}  TODO AHORITA */
                   ;

/*TODO */
listaParametrosFormales : tipoSimple ID_ {
                           int refe = insTdD(-1, $1);
                        }
                        | tipoSimple ID_ COMA_ listaParametrosFormales
                        ;

bloque : ABLOQ_ declaracionVariableLocal listaInstrucciones 
         RETURN_ expresion FINL_ CBLOQ_ {
            INF func = obtTdD(-1); /* Sacamos la info la de funcion actual */
            /* Los tipos que tienen que devolver coinciden */
            if (func.tipo != $5) {
               yyerror("El valor de retorno no coincide con el de la declaración de la funcion");
            }
         }

/* HECHO, como niv=0 al declarar funcion, no hace falta ponerlo */
declaracionVariableLocal :  /* epsilon */
                         | declaracionVariableLocal declaracionVariable
                         ;

listaInstrucciones :  /* epsilon */
                   | listaInstrucciones instruccion 
                   ;

instruccion : ABLOQ_ listaInstrucciones CBLOQ_ 
            | instruccionAsignacion
            | instruccionSeleccion
            | instruccionEntradaSalida
            | instruccionIteracion
            ;

instruccionAsignacion : ID_ ASIG_ expresion FINL_ {
                        SIMB sym = obtTdS($1); /*sacamos la estructura con el nombre de la variable */
                        if(sym.t == T_ERROR) {
                           yyerror("Objeto no declarado");
                        } else if(sym.t != $3)
                           yyerror("Error en la asignacion");
                     }
                      | ID_ AIND_ expresion CIND_ ASIG_ expresion FINL_ {
                         /* Sacamos simbolo e informacion del array dado el simbolo */
                         SIMB sym = obtTdS($1);
                         DIM dim = obtTdA(sym.ref);
                         if(sym.t == T_ERROR) {
                            yyerror("Objeto no declarado");
                         } else if($6 != dim.telem) { /* La asignacion no coincide con el tipo del array */
                            yyerror("Error de tipos en la \"asignacion\"");
                         } else if(sym.t != T_ARRAY) { /* Tenemos que tratar con un array */
                            yyerror("El identificador debe ser de tipo \"array\"");
                         } else if($3 != T_ENTERO) { /* Se accede a los indicies con enteros */
                            yyerror("El índice del \"array\" debe ser entero");
                         } 
                      }
                      | ID_ PUNT_ ID_ ASIG_ expresion FINL_ {
                        SIMB sym = obtTdS($1); /* Sacamos la variable */
                        CAMP cam = obtTdR(sym.ref, $3);
                        if(sym.t == T_ERROR) { /* ¿Variable declarada?*/
                           yyerror("Objeto no declarado");
                        } else if(sym.t != T_RECORD) { /* ¿Estructura? */
                           yyerror("El identificador debe ser \"struct\"");
                        } else if(cam.t == T_ERROR){
                           yyerror("Campo no declarado");
                        } else if(cam.t != $5){
                           yyerror("Error de tipos en la \"asignacion\"");
                        }
                      }
                        
                      ;

/*HECHO */
instruccionEntradaSalida : READ_ APAR_ ID_ CPAR_ FINL_ {
                           SIMB sym = obtTdS($3);
                           if(sym.t == T_ERROR) {
                              yyerror("Objeto no declarado");
                           } else if(sym.t != T_ENTERO) {
                              yyerror("El argumento de \"read\" debe ser \"entero\"");
                           }
                        }
                         | PRINT_ APAR_ expresion CPAR_ FINL_{
                           if($3 != T_ENTERO) {
                              yyerror("La expresion del \"print\" debe ser entera");
                           }
                         }
                         ;

/* HECHO */
instruccionSeleccion : IF_ APAR_ expresion CPAR_ instruccion ELSE_ instruccion {
                        if($3 != T_LOGICO) {
                           yyerror("La expresion del \"if\" debe ser \"logico\"")
                        }
                     }
                     ;

instruccionIteracion : WHILE_ APAR_ expresion CPAR_ instruccion {
                        if($3 != T_LOGICO)
                           yyerror("La expresion del \"while\" debe ser \"logico\"");
                     }
                     ;

expresion : expresionIgualdad {$$ = $1;}
          | expresion operadorLogico expresionIgualdad{
              if($1 != $3 && $3 )
                yyerror("");
          }
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

constante : CTE_ {$$ = T_ENTERO;}
          | TRUE_ {$$ = T_LOGICO;}
          | FALSE_ {$$ = T_LOGICO;}
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
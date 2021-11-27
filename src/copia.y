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
   struct {
      int refe;
      int talla;
   } ParamForm;
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
%type <cent> tipoSimple
/* GRAMATICA COPIADA DIRECTAMENTE DEL BOLETÍN */
%%

programa : listaDeclaraciones {niv=0;cargaContexto(niv);dvar=0;}
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

| tipoSimple ID_ AIND_ CTE_ CIND_ FINL_ /* {
   int numelem = $4; /*Array length 
   if(numelem <= 0) {
      yyerror("Talla inapropiada del array");
      numelem = 0;
   }
   int refe = insTdA($1, numelem); /*Referencia en tabla de arrays 
   /*Insertar en tabla de simbolos e incrementar desplazamiento relativo si OK 
   if(!insTdS($2, VARIABLE, T_ARRAY, niv, dvar, refe))
      yyerror("Identificador repetido");
   else dvar += numelem * TALLA_TIPO_SIMPLE; 
}*/
| STRUC_ ABLOQ_ listaCampos CBLOQ_ ID_ FINL_ /*{
   if(!insTdS($5, VARIABLE, T_RECORD, niv, dvar, $3.refe)) {
      yyerror("Identificador repetido");
   } else {
      dvar += $3.desp_r;
   }/* Meter un else donde se incrementa el dvar en función de la listaCampos 
}; */

/* HECHO */
tipoSimple : INT_ {$$ = T_ENTERO;}
           | BOOL_ {$$ = T_LOGICO;}
           ;

/* HECHO */
listaCampos : 
tipoSimple ID_ FINL_ /* {
   int refe = insTdR(-1, $2, $1, 0);
   if(refe == -1)
      yyerror("Campo ya existente en el registro");
   else {
      $$.refe = refe;
      $$.desp_r = TALLA_TIPO_SIMPLE; /*TALLA_TIPO_SIMPLE 
   };
} */
| 
listaCampos tipoSimple ID_ FINL_ /* {
   $$.refe = $1.refe;
   $$.desp_r = $1.desp_r;
   if (insTdR($1.refe,$3, $2, $1.desp_r) == -1)
      yyerror("Campo ya existente en el registro");
   else {
      $$.refe = $1.refe;
      $$.desp_r = $1.desp_r + TALLA_TIPO_SIMPLE; /* TALLA_TIPO_SIMPLE 
   }
} */
;
/* TODO */
                     /* nivel para variables locales                                                  descargamos contexto y reestablecemos nivel*/ 
declaracionFuncion : tipoSimple  ID_
          /**/
         APAR_ parametrosFormales CPAR_ 
              /* {if(!insTdS($2, FUNCION, $1, niv - 1, -1, $5)) yyerror("La función ya ha sido declarada de forma previa");} /* TODO: main() 
                     bloque {                           
                           if(verTdS)
                              mostrarTdS(); 
                           descargaContexto(niv);niv--;dvar = $<cent>3;
                     }*/
                   ;

/* TODO */
parametrosFormales : /* {$$ = insTdD(-1, T_VACIO);}  */
                   | listaParametrosFormales /* {$$ = $1.refe;} /* solo necesitamos la referencia */  
                   ;

/*HECHO*/
listaParametrosFormales : tipoSimple ID_ /*{
                           $$.refe = insTdD(-1, $1); /*insertamos
                           $$.talla = TALLA_TIPO_SIMPLE + TALLA_SEGENLACES; /*incrementamos talla 
                           if(!insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1)) { /*insertamos parametro en la tabla de simbolos 
                              yyerror("Identificador del parametro repetido");
                           }
                        }*/
                        | tipoSimple ID_ COMA_ listaParametrosFormales /*{
                           $$.talla = TALLA_TIPO_SIMPLE + $4.talla; /*Nueva parametro, incrementamos talla 
                           $$.refe = insTdD($4.refe,$1); /* nos quedamos con la referencia del nuevo parametro 
                           if(!insTdS($2, PARAMETRO, $1, niv,-$$.talla, -1)) /* insertamos TdS 
                              yyerror("Identificador de parametro repetido");
                        } */
                        ;

bloque : ABLOQ_ declaracionVariableLocal listaInstrucciones 
         RETURN_ expresion FINL_ CBLOQ_ /* {
            INF func = obtTdD(-1); /* Sacamos la info la de funcion actual 
            /* Los tipos que tienen que devolver coinciden 
            if (func.tipo != $5) {

            }
         } */

/* HECHO, como niv=0 al declarar funcion, no hace falta ponerlo */
declaracionVariableLocal :  /* epsilon */
                         | declaracionVariableLocal declaracionVariable
                         ;

listaInstrucciones :  /* epsilon  */
                   | listaInstrucciones instruccion 
                   ;

instruccion : ABLOQ_ listaInstrucciones CBLOQ_ 
            | instruccionAsignacion
            | instruccionSeleccion
            | instruccionEntradaSalida
            | instruccionIteracion
            ;

instruccionAsignacion : ID_ ASIG_ expresion FINL_  /*{
                        SIMB sym = obtTdS($1); /*sacamos la estructura con el nombre de la variable 
                        if(sym.t == T_ERROR) {
                           yyerror("Objeto no declarado");
                        } else if(sym.t != $3)
                           yyerror("Error en la asignacion");
                        }
                        */
                     
                      | ID_ AIND_ expresion CIND_ ASIG_ expresion FINL_  /*{
                         /* Sacamos simbolo e informacion del array dado el simbolo 
                         SIMB sym = obtTdS($1);
                         DIM dim = obtTdA(sym.ref);
                         if(sym.t == T_ERROR) {
                            yyerror("Objeto no declarado");
                         } else if($6 != dim.telem) { /* La asignacion no coincide con el tipo del array 
                            yyerror("Error de tipos en la \"asignacion\"");
                         } else if(sym.t != T_ARRAY) { /* Tenemos que tratar con un array 
                            yyerror("El identificador debe ser de tipo \"array\"");
                         } else if($3 != T_ENTERO) { /* Se accede a los indicies con enteros  
                            yyerror("El índice del \"array\" debe ser entero");
                         }
                         }
                         */
                      
                      | ID_ PUNT_ ID_ ASIG_ expresion FINL_ /* {
                        
                        /* SIMB sym = obtTdS($1); /* Sacamos la variable 
                        CAMP cam = obtTdR(sym.ref, $3);
                        if(sym.t == T_ERROR) { /* ¿Variable declarada? 
                           yyerror("Objeto no declarado");
                        } else if(sym.t != T_RECORD) { /* ¿Estructura? 
                           yyerror("El identificador debe ser \"struct\"");
                        } else if(cam.t == T_ERROR){
                           yyerror("Campo no declarado");
                        } else if(cam.t != $5){
                           yyerror("Error de tipos en la \"asignacion\"");
                        }
                         }
                        */
                      ;

/*HECHO */
instruccionEntradaSalida : READ_ APAR_ ID_ CPAR_ FINL_ /*{
                           /*
                           SIMB sym = obtTdS($3);
                           if(sym.t == T_ERROR) {
                              yyerror("Objeto no declarado");
                           } else if(sym.t != T_ENTERO) {
                              yyerror("El argumento de \"read\" debe ser \"entero\"");
                           }
                        } */
                         | PRINT_ APAR_ expresion CPAR_ FINL_ /*{
                           if($3 != T_ENTERO) {
                              yyerror("La expresion del \"print\" debe ser entera");
                           }
                         } */
                         ;

/* HECHO */
instruccionSeleccion : IF_ APAR_ expresion /*{if($3 != T_LOGICO)yyerror("La expresion del \"if\" debe ser \"logico\"");}*/ CPAR_ instruccion ELSE_ instruccion 
                     ;
/* HECHO */ 
instruccionIteracion : WHILE_ APAR_ expresion /*{if($3 != T_LOGICO)yyerror("La expresion del \"while\" debe ser \"logico\"");}*/CPAR_ instruccion
                     ;


expresion : expresionIgualdad /* {$$ = $1;} */
          | expresion operadorLogico expresionIgualdad/*{ 
              /* Si uno de las dos expresiones no es de tipo logico tenemos un error 
               if ($1 == T_ERROR || $3 == T_ERROR) 
                   $$ = T_ERROR;
               else if(!($1 == T_LOGICO && $1 == $3)) {
                    $$ = T_ERROR;
                    yyerror("Error en \"expresion logica\"");
               }
               else
                    $$ = T_LOGICO;
          }
          */
          ;

expresionIgualdad : expresionRelacional /* {$$ = $1;} */
                  | expresionIgualdad operadorIgualdad expresionRelacional /* {
                     if($1 == T_ERROR || $3 == T_ERROR)
                        $$ = T_ERROR;
                     else if(!(($1 == T_LOGICO && $1 == $3) || ($1 == T_ENTERO && $1 == $3) )) {
                        $$ = T_ERROR;
                        yyerror("Error en \"expresion de igualdad\"");
                     } else {
                        $$ = T_LOGICO;
                     }
                  } */
                  ;

expresionRelacional : expresionAditiva /* {$$ = $1;} */
                    | expresionRelacional operadorRelacional expresionAditiva /* {
                        if($1 == T_ERROR || $3 == T_ERROR)
                           $$ = T_ERROR;
                        else if(!($1 == T_ENTERO || $1 == $3)) {
                           $$ = T_ERROR;
                           yyerror("Error en \"expresion relacional\"");
                        } /*PREGUNTAR SI SE PUEDE HACER TRUE < FALSE 
                        else {
                           $$ = T_LOGICO;
                        }
                    }*/
                    ;

expresionAditiva : expresionMultiplicativa  /*{$$ = $1;} */
                 | expresionAditiva operadorAditivo expresionMultiplicativa /*{
                     if($1 == T_ERROR || $3 == T_ERROR)
                        $$ = T_ERROR;
                     else if(!($1 == T_ENTERO || $1 == $3)) {
                        $$ = T_ERROR;
                        yyerror("Error en \"expresion aditiva\"");
                     } else {
                        $$ = T_LOGICO;
                     }
                 }*/
                 ;

expresionMultiplicativa : expresionUnaria /* {$$ = $1;}*/
                        | expresionMultiplicativa operadorMultiplicativo expresionUnaria /* {
                           if($1 == T_ERROR || $3 == T_ERROR)
                              $$ = T_ERROR;
                           else if(!($1 == T_ENTERO && $1 == $3)) {
                              $$ = T_ERROR;
                              yyerror("Error en \"expresion multiplicativa\"");
                           }
                           else {
                              $$ = T_ENTERO;
                           }
                        } */
                        ;

expresionUnaria : expresionSufija /* {$$ = $1;} */
                | operadorUnario expresionUnaria /* {
                     if($2 == T_ERROR)
                        $$ = $2;
                     else if($1 == $2) {
                        yyerror("Error en \"expresion unaria\"");
                        $$ = T_ERROR;
                     }else
                        $$ = $2;
                  
                } /* PREGUNTAR AL PROFESOR */
                ;

expresionSufija : constante 
                | APAR_ expresion CPAR_ /* {$$ = $2;} */
                | ID_  /* {
                     SIMB sym = obtTdS($1);
                     if(sym.t == T_ERROR) {
                        yyerror("Objeto no declarado");
                        $$ = T_ERROR;
                     }else
                        $$ = sym.t;
                  }
                  */
                | ID_ PUNT_ ID_ /* {
                     SIMB sym = obtTdS($1);
                     CAMP camp = obtTdR(sym.ref, $3);
                     /*¿ERROR?
                     if(sym.t == T_ERROR) {
                        yyerror("Objeto no declarado");
                        $$ = T_ERROR;
                     } else if(sym.t != T_RECORD) { /*¿Estructura
                        yyerror("El identificador debe ser de tipo \"struct\"");
                        $$ = T_ERROR;
                     } else if (camp.t == T_ERROR) { /*¿Campo declarado?
                        yyerror("Campo no declarado");
                        $$ = T_ERROR;
                     } else
                        $$ = camp.t;
                }*/
                | ID_ AIND_ expresion CIND_ /* {
                     SIMB sym = obtTdS($1);
                     DIM dim = obtTdA(sym.ref);
                     if(sym.t == T_ERROR) { /*¿Error? 
                        yyerror("Objeto no declarado");
                        $$ = T_ERROR;
                     } else if(sym.t != T_ARRAY) { /* ¿Array 
                        yyerror("El identificador debe ser de tipo \"array\"");
                        $$ = T_ERROR;
                     } else if($3 != T_ENTERO) { /* Indice entero 
                        yyerror("El indice del \"array\" debe ser entero");
                        $$ = T_ERROR;
                     }  else
                        $$ = dim.telem;
                }*/
                | ID_ APAR_ parametrosActuales CPAR_ /*{
                     /* preguntar la profesor 
                }*/
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
               ;

%%

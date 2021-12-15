/* **********************************************
   ********ANÁLISIS SINTÁCTICO*******************
   ********ELIAS URIOS ALACREU*******************
   ********JUAN ALEJANDRO FURIÓ AGUSTÍ***********
   ********PABLO LLORCA MARCHANTE****************
   ********FRANCISCO FERNANDEZ GARCÍA************
   ********************************************** */

%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
#include "libgci.h"

extern int yylineno;
%}

%union{
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
      int t; 
      int d;
   } Expresion;
}
/*PUNTO, COMA Y PUNTO Y COMA */
%token PUNT_ COMA_ FINL_
/* PALABRAS RESERVADAS */
%token WHILE_ INT_ BOOL_ STRUC_ RETURN_ READ_ PRINT_ IF_ ELSE_
/* INDICES, BLOQUES Y PARENTESIS*/
%token APAR_ CPAR_ ABLOQ_ CBLOQ_ AIND_ CIND_
/* OPERADORES LÓGICOS */
%token IGU_ DIST_ AND_ OR_ MAY_ MEN_ MAYIGU_ MENORIGU_ NOT_
/* ASIGNACION Y OPERADORES ARITMÉTICOS */
%token ASIG_ MAS_ MENOS_ POR_ DIV_
/* TRUE AND FALSE */
%token TRUE_ FALSE_

/*TOKENS CON ATRIBUTOS */
/*CONSTANTE E IDENTIFICADOR*/
%token <ident> ID_ 
%token <cent> CTE_
/*REGISTROS Y  LISTA PARAMETROS */
%type <CampoRegistro> listaCampos
%type <ParamForm> listaParametrosFormales
%type <cent> parametrosFormales listaParametrosActuales parametrosActuales
/*EXPRESIONES Y OPERADOR*/
%type <Expresion> expresion expresionAditiva expresionIgualdad expresionMultiplicativa 
%type <Expresion> expresionRelacional expresionSufija expresionUnaria
/*DECLARACIONES Y TIPOS*/
%type <cent> declaracion declaracionFuncion listaDeclaraciones declaracionVariable
%type <cent> tipoSimple constante 
/*OPERADORES*/
%type <cent> operadorAditivo operadorIgualdad operadorLogico operadorMultiplicativo operadorRelacional operadorUnario
/* GRAMATICA COPIADA DIRECTAMENTE DEL BOLETÍN */
%%

programa :  {niv=0;dvar=0;si=0;cargaContexto(niv);} listaDeclaraciones {
                if($2 == 0)
                    yyerror("El programa no tiene \"main\"");
                else if($2 > 1)
                    yyerror("El programa tiene mas de un \"main\"");
                /* else todo ok :) */
            };

/********************************************************************/

listaDeclaraciones : declaracion {$$ = $1;} /* hay que contar los main */
                   | listaDeclaraciones declaracion {$$ = $1 + $2;} /* hay que contar lo que tenemos y lo que falta por llegar */
                   ;

/********************************************************************/

declaracion : declaracionVariable {$$ = 0;} /* una variable no puede ser una funcion main */
            | declaracionFuncion {$$ = $1;} /*cuantas veces ha aparecido el main*/
            ;

/********************************************************************/

declaracionVariable : tipoSimple ID_ FINL_ {
                            if(!insTdS($2, VARIABLE, $1, niv, dvar, -1)) {
                                yyerror("Identificador variable repetido");
                            }
                            else
                                dvar += TALLA_TIPO_SIMPLE;
                        }
                    |   tipoSimple ID_ AIND_ CTE_ CIND_ FINL_ {
                            int numelem = $4; /*Array length */
                            if(numelem <= 0) {
                                yyerror("Talla inapropiada del array");
                                numelem = 0;
                            }
                            int refe = insTdA($1, numelem); /*Referencia en tabla de arrays*/
                            /*Insertar en tabla de simbolos e incrementar desplazamiento relativo si OK */
                            if(!insTdS($2, VARIABLE, T_ARRAY, niv, dvar, refe))
                                yyerror("Identificador repetido");
                            else dvar += numelem * TALLA_TIPO_SIMPLE;
                        }
                    |   STRUC_ ABLOQ_ listaCampos CBLOQ_ ID_ FINL_ {
                            if(!insTdS($5, VARIABLE, T_RECORD, niv, dvar, $3.refe)) {
                                yyerror("Identificador repetido");
                            } else {
                                dvar += $3.desp_r;
                            }
                        }
                    ;

/********************************************************************/

tipoSimple :    INT_ {$$=T_ENTERO;}
           |    BOOL_ {$$=T_LOGICO;}
           ;

/********************************************************************/

listaCampos :   tipoSimple ID_ FINL_{
                    /* NO PUEDE DAR ERROR, NO HACE FALTA COMPROBAR NADA */
                    $$.refe = insTdR(-1, $2, $1, 0);/*creamos campo de registro*/
                    $$.desp_r = TALLA_TIPO_SIMPLE; /*incrementar desplazamiento */
                }
            |   listaCampos tipoSimple ID_ FINL_ {
                    $$.refe = $1.refe; /* pillamos valor antes */
                    $$.desp_r = $1.desp_r; /*desplazamiento (AKA talla diapositivas)*/
                    if (insTdR($1.refe,$3, $2, $1.desp_r) == -1)
                        yyerror("Campo ya existente en el registro");
                    else {
                        $$.refe = $1.refe;
                        $$.desp_r = $1.desp_r + TALLA_TIPO_SIMPLE; /*incrementamos desplazamiento puesto que hay un campo nuevo*/
                    }   
                }
            ;

/********************************************************************/

declaracionFuncion  :   tipoSimple ID_
                        {$<cent>$ = dvar;dvar = 0;niv++;cargaContexto(niv);} 
                        APAR_ parametrosFormales CPAR_{
                            if(!insTdS($2, FUNCION, $1, niv - 1, -1, $5))
                                yyerror("Identificador de función repetido");
                            if(strcmp($2, "main") == 0)
                                $<cent>$ = 1;
                            else 
                                $<cent>$ = 0;
                        }
                        bloque {
                            if(verTdS)
                                mostrarTdS();
                            descargaContexto(niv);niv--;
                            dvar = $<cent>3;
                            $$ =  $<cent>7;  
                        }
                   ;

/********************************************************************/

parametrosFormales  :   {$$ = insTdD(-1, T_VACIO);}
                    |   listaParametrosFormales {$$ = $1.refe;}
                    ;

/********************************************************************/

listaParametrosFormales :   tipoSimple ID_{
                                $$.refe = insTdD(-1, $1);
                                $$.talla = TALLA_TIPO_SIMPLE + TALLA_SEGENLACES;
                                if(!insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1))
                                    yyerror("Identificador del parametro repetido");
                        }
                        |   tipoSimple ID_ COMA_ listaParametrosFormales {
                                $$.talla = $4.talla; /*Nueva parametro, incrementamos talla*/
                                $$.refe = insTdD($4.refe,$1); /* nos quedamos con la referencia del nuevo parametro*/
                                if(!insTdS($2, PARAMETRO, $1, niv,-($$.talla + TALLA_TIPO_SIMPLE), -1))
                                    yyerror("Identificador del parametro repetido");
                                else
                                    $$.talla += TALLA_TIPO_SIMPLE;
                        }
                        ;

/********************************************************************/

bloque  : ABLOQ_ declaracionVariableLocal listaInstrucciones 
         RETURN_ expresion {
		INF func = obtTdD(-1);
		if(func.tipo == T_ERROR) {
            yyerror("Error en declaracion de funcion");
		}
		else if($5 != T_ERROR && func.tipo != $5)
			yyerror("Error de tipos del \"return\"");}
	 FINL_ CBLOQ_

/********************************************************************/

declaracionVariableLocal: /*epsilon*/
                        | declaracionVariableLocal declaracionVariable
                        ;

/********************************************************************/

listaInstrucciones : /*epsilon*/
                   | listaInstrucciones instruccion
                   ;

/********************************************************************/

instruccion : ABLOQ_ listaInstrucciones CBLOQ_
            | instruccionAsignacion
            | instruccionSeleccion
            | instruccionEntradaSalida
            | instruccionIteracion
            ;

/********************************************************************/

instruccionAsignacion : ID_ ASIG_ expresion FINL_{
                        SIMB sym = obtTdS($1); /*sacamos la estructura con el nombre de la variable*/
                        if($3 != T_ERROR) {
                            if(sym.t == T_ERROR) {
                            yyerror("Objeto no declarado");
                            } else if(sym.t != $3 && $3 != T_ERROR)
                            yyerror("Error de tipos en la \"asignacion\"");
                            }
                        }
                      | ID_ AIND_ expresion CIND_ ASIG_ expresion FINL_{
                            /* Sacamos simbolo e informacion del array dado el simbolo*/
                            SIMB sym = obtTdS($1);
                            if ($3 != T_ERROR && $6 != T_ERROR) {
                                if(sym.t == T_ERROR) {
                                    yyerror("Objeto no declarado");
                                }else if(sym.t != T_ARRAY) { /* Tenemos que tratar con un array */
                                    yyerror("El identificador debe ser de tipo \"array\"");
                                } else {
                                    DIM dim = obtTdA(sym.ref);
                                    if($3 != T_ENTERO) { /* Se accede a los indicies con enteros */
                                        yyerror("El índice del \"array\" debe ser entero");
                                    } 
                                    else if($6 != dim.telem) { /* La asignacion no coincide con el tipo del array */
                                        yyerror("Error de tipos en la \"asignacion\"");
                                    } 
                                }
                            }
                        }
                      | ID_ PUNT_ ID_ ASIG_ expresion FINL_ {
                            SIMB sym = obtTdS($1);
                            if($5 != T_ERROR) {
                                if(sym.t == T_ERROR)
                                    yyerror("Objeto no declarado");
                                else if(sym.t != T_RECORD)
                                    yyerror("El identificador debe ser de tipo \"struct\"");
                                else {
                                    CAMP camp = obtTdR(sym.ref, $3);
                                    if(camp.t == T_ERROR)
                                    	yyerror("Campo no declarado");
                                    else if(camp.t != $5)
                                        yyerror("Error de tipos en la \"asignacion\"");

                                }
                                
                            }
                      }
                      ;

/********************************************************************/

instruccionEntradaSalida : READ_ APAR_ ID_ CPAR_ FINL_{
                            SIMB sym = obtTdS($3);
                            if(sym.t == T_ERROR) {
                                yyerror("Objeto no declarado");
                            } else if(sym.t != T_ENTERO) {
                                yyerror("El argumento de \"read\" debe ser \"entero\"");
                            }
                        }
                         | PRINT_ APAR_ expresion CPAR_ FINL_ {
                           if($3 != T_ENTERO) {
                              yyerror("La expresion del \"print\" debe ser entera");
                           }
                         }
                         ;

/********************************************************************/

instruccionSeleccion : IF_ APAR_ expresion {if($3 != T_LOGICO && $3 != T_ERROR)yyerror("La expresion del \"if\" debe ser \"logico\"");} CPAR_ instruccion ELSE_ instruccion
                     ;

/********************************************************************/

instruccionIteracion : WHILE_ APAR_ expresion{if($3 != T_LOGICO && $3 != T_ERROR)yyerror("La expresion del \"while\" debe ser \"logico\"");} CPAR_ instruccion
                     ;

/********************************************************************/

expresion : expresionIgualdad {$$ = $1;}
          | expresion operadorLogico expresionIgualdad {
                if ($1 == T_ERROR || $3 == T_ERROR) 
                   $$ = T_ERROR;
                else if(!($1 == T_LOGICO && $1 == $3)) {
                    $$ = T_ERROR;
                    yyerror("Error en \"expresion logica\"");
                }
                else
                    $$ = T_LOGICO;
          }
          ;

/********************************************************************/

expresionIgualdad : expresionRelacional {$$ = $1;}
                  | expresionIgualdad operadorIgualdad expresionRelacional {
                        if($1 == T_ERROR || $3 == T_ERROR)
                            $$ = T_ERROR;
                        else if(!(($1 == T_LOGICO && $1 == $3) || ($1 == T_ENTERO && $1 == $3) )) {
                            $$ = T_ERROR;
                            yyerror("Error en \"expresion de igualdad\"");
                        } else {
                            $$ = T_LOGICO;
                        }
                  }
                  ;

/********************************************************************/

expresionRelacional : expresionAditiva {$$ = $1;}
                    | expresionRelacional operadorRelacional expresionAditiva {
                        if($1 == T_ERROR || $3 == T_ERROR)
                           $$.t = T_ERROR;
                        else if(!($1 == T_ENTERO && $1 == $3)) {
                           $$ = T_ERROR;
                           yyerror("Error en \"expresion relacional\"");
                        } else 
                           $$ = T_LOGICO;
                    }
                    ;

/********************************************************************/

expresionAditiva : expresionMultiplicativa  {$$ = $1;} 
                 | expresionAditiva operadorAditivo expresionMultiplicativa {
                        if($1.tipo == T_ERROR || $3.tipo == T_ERROR)
                            $$.tipo = T_ERROR;
                        else if($1.tipo != T_ENTERO || $3.tipo != T_ENTERO) {
                            $$.tipo = T_ERROR;
                            yyerror("Error en \"expresion aditiva\"");
                        } else 
                            $$.tipo = T_ENTERO;
                        
                        $$.d = creaVarTemp();
                        emite($2, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgPos(niv, $$.d));
                 }
                 ;

/********************************************************************/

expresionMultiplicativa : expresionUnaria {$$ = $1;}
                        | expresionMultiplicativa operadorMultiplicativo expresionUnaria {
                            if($1 == T_ERROR || $3 == T_ERROR)
                              $$ = T_ERROR;
                            else if($1 != T_ENTERO || $3 != T_ENTERO) {
                              $$ = T_ERROR;
                              yyerror("Error en \"expresion multiplicativa\"");
                            }
                            else {
                              $$ = T_ENTERO;
                            }
                        }
                        ;

/********************************************************************/

expresionUnaria : expresionSufija {$$ = $1;}
                | operadorUnario expresionUnaria {
                    if($2 == T_ERROR)
                        $$ = $2;
                    else if($1 != $2) {
                        yyerror("Error en \"expresion unaria\"");
                        $$ = T_ERROR;
                    }else
                        $$ = $2;
                }
                ;

/********************************************************************/

expresionSufija : constante {$$ = $1;}
                | APAR_ expresion CPAR_ {$$ = $2;}
                | ID_ {
                    SIMB sym = obtTdS($1);
                    if(sym.t == T_ERROR) {
                        $$ = T_ERROR;
                    }else
                        $$ = sym.t;
                  }
                | ID_ PUNT_ ID_ {
                    SIMB sym = obtTdS($1);
                    
                    /*¿ERROR?*/
                    if(sym.t == T_ERROR) {
                        yyerror("Objeto no declarado");
                        $$ = T_ERROR;
                    } else if(sym.t != T_RECORD) { /*¿Estructura*/
                        yyerror("El identificador debe ser de tipo \"struct\"");
                        $$ = T_ERROR;
                    } else {
                        CAMP camp = obtTdR(sym.ref, $3);
                        if (camp.t == T_ERROR) { /*¿Campo declarado?*/
                            yyerror("Campo no declarado");
                            $$ = T_ERROR;
                        } else
                            $$ = camp.t;
                    }
                }
                | ID_ AIND_ expresion CIND_ {
                    SIMB sym = obtTdS($1);
                    DIM dim = obtTdA(sym.ref);
                    if(sym.t == T_ERROR) { /*¿Error? */
                        yyerror("Objeto no declarado");
                        $$ = T_ERROR;
                    } else if(sym.t != T_ARRAY) { /* ¿Array */
                        yyerror("El identificador debe ser de tipo \"array\"");
                        $$ = T_ERROR;
                    } else if($3 != T_ENTERO) { /* Indice entero */
                        yyerror("El indice del \"array\" debe ser entero");
                        $$ = T_ERROR;
                    }  else
                        $$ = dim.telem;
                }
                | ID_ APAR_ parametrosActuales CPAR_ {
                    SIMB sym = obtTdS($1);
                    $$ = T_ERROR; /* si no llega hasta el ultimo else se queda esto */
                    if(sym.t == T_ERROR)
                        yyerror("Objeto no declarado");
                    else {
                        INF inf = obtTdD(sym.ref);
                        if (inf.tipo == T_ERROR) 
                            yyerror("El identificador no es una funcion");
                        else if (cmpDom(sym.ref, $3) == 0 )
                            yyerror("El dominio de los parametros actuales no coincide con el de la funcion");
                        else
                            $$ = inf.tipo;
                    }
                    

                }
                ;

/********************************************************************/

constante : CTE_ {$$ = T_ENTERO;}
          | TRUE_ {$$ = T_LOGICO;}
          | FALSE_ {$$ = T_LOGICO;}
          ;

/********************************************************************/

parametrosActuales : {$$ = insTdD(-1, T_VACIO);} /* funcion sin parametros */
                   | listaParametrosActuales {$$ = $1;}
                   ;

/********************************************************************/

listaParametrosActuales : expresion {$$ = insTdD(-1, $1);}
                        | expresion COMA_ listaParametrosActuales {
                            $$ = insTdD($3, $1); 
                        }
                        ;

/********************************************************************/

operadorLogico : AND_ {}
               | OR_
               ;

/********************************************************************/

operadorIgualdad : IGU_ {$$ = EIGUAL;}
                 | DIST_ {$$ = EDIST;}
                 ;

/********************************************************************/

operadorRelacional : MAY_ {$$ = EMAY;}
                   | MEN_ {$$ = EMEN;}
                   | MAYIGU_ {$$ = EMAYEQ;}
                   | MENORIGU_ {$$ = EMENEQ;}
                   ;

/********************************************************************/

operadorAditivo : MAS_ {$$ = ESUM;}
                | MENOS_ {$$ = EDIF;}
                ;

/********************************************************************/

operadorMultiplicativo : POR_ {$$ = EMULT;}
                       | DIV_ {$$ = EDIVI;}
                       ;

/********************************************************************/

operadorUnario : MAS_ {$$ = T_ENTERO;}
               | MENOS_ {$$ = T_ENTERO;}
               | NOT_ {$$ = T_LOGICO;}

%%

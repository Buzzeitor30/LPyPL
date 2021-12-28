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
      int tipo; /*tipo de la expresion*/
      int desp; /* desplazamiento en memoria */
   } exp; /*expresiones */
   struct {
       int arg1; /*argumento de LANS*/
       int arg2; /*argumento de LANS*/
   } prog;
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
/*PROGRAMA*/
/*CONSTANTE E IDENTIFICADOR*/
%token <ident> ID_ 
%token <cent> CTE_
/*REGISTROS Y  LISTA PARAMETROS */
%type <CampoRegistro> listaCampos
%type <ParamForm> listaParametrosFormales
%type <cent> parametrosFormales listaParametrosActuales parametrosActuales
/*EXPRESIONES Y OPERADOR*/
%type <exp> expresion expresionAditiva expresionIgualdad expresionMultiplicativa constante
%type <exp> expresionRelacional expresionSufija expresionUnaria
/*DECLARACIONES Y TIPOS*/
%type <cent> declaracion declaracionFuncion listaDeclaraciones declaracionVariable
%type <cent> tipoSimple  
/*OPERADORES*/
%type <cent> operadorAditivo operadorIgualdad operadorLogico operadorMultiplicativo operadorRelacional operadorUnario
/* GRAMATICA COPIADA DIRECTAMENTE DEL BOLETÍN */
%%

programa :  {
        niv=0;
        dvar=0;
        si=0;
        cargaContexto(niv);
        /****Variables globales****/
        $<prog>$.arg1 = creaLans(si);
        emite(INCTOP,crArgNul(),crArgNul(),crArgEnt(-1)); /*variables globales, pero no sabemos aun cuantas tenemos*/
        /****Salto a main******/
        $<prog>$.arg2 = creaLans(si);
        emite(GOTOS,crArgNul(),crArgNul(),crArgEtq(-1)); /*hay que saltar al main, pero no sabemos si tendra o donde esta*/
} listaDeclaraciones {
                SIMB main = obtTdS("main"); /*sacamos la funcion main*/
                if($2 == 0)
                    yyerror("El programa no tiene \"main\"");
                else if($2 > 1)
                    yyerror("El programa tiene mas de un \"main\"");
                /* else todo ok :) */
                /****Completar variables globales**/
                completaLans($<prog>1.arg1, crArgEnt(dvar));
                /*saltamos al main*/
                completaLans($<prog>1.arg2, crArgEtq(main.d));
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
                            if(!insTdS($2, FUNCION, $1, niv - 1, si, $5))
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

bloque  :  {
            emite(PUSHFP,crArgNul(),crArgNul(),crArgNul()); /* apilamos fp en la pila */
            emite(TOPFP,crArgNul(),crArgNul(),crArgNul()); /* movemos fp arriba del todo de la pila */
            /*variables locales y temporales*/
            $<cent>$ = creaLans(si); /*cuantas variables temporales y vocales hay */
            emite(INCTOP,crArgNul(),crArgNul(),crArgEnt(-1));
}   ABLOQ_ declaracionVariableLocal listaInstrucciones 
    RETURN_ expresion {
            INF func = obtTdD(-1);
            /* espacio para las variables reservado OK */
            completaLans($<cent>1,crArgEnt(dvar));
            /* valor retorno,mirar el tema 5, basicamente es la funcion que hay en la diapo 5*/
            int accvalret = - (TALLA_SEGENLACES + func.tsp + TALLA_TIPO_SIMPLE);
            emite(EASIG,crArgPos(niv, $6.desp),crArgNul(),crArgPos(niv,accvalret));
            /*liberar segmento de variables locales y temporales */
            emite(TOPFP, crArgNul(),crArgNul(),crArgEnt(dvar)); /*desapilamos variables temporales y locales*/
            /*desapilar enlaces de control*/
            emite(FPPOP,crArgNul(),crArgNul(),crArgNul());

            if(func.tipo == T_ERROR) {
                yyerror("Error en declaracion de funcion");
            }
            else if($6.tipo != T_ERROR && func.tipo != $6.tipo)
                yyerror("Error de tipos del \"return\"");

            if(strcmp(func.nom,"main") == 0)
                emite(FIN,crArgNul(),crArgNul(),crArgNul()); /* fin del programa */
            else
                emite(RET,crArgNul(),crArgNul(),crArgNul()); /*return de una funcion */
            }
            
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
                        if($3.tipo != T_ERROR) {
                            if(sym.t == T_ERROR) {
                            yyerror("Objeto no declarado");
                            } else if(sym.t != $3.tipo && $3.tipo != T_ERROR)
                            yyerror("Error de tipos en la \"asignacion\"");
                            }
                        emite(EASIG,crArgPos(niv,$3.desp),crArgNul(),crArgPos(sym.n,sym.d)); /*asignacion */
                        }
                      | ID_ AIND_ expresion CIND_ ASIG_ expresion FINL_{
                            /* Sacamos simbolo e informacion del array dado el simbolo*/
                            SIMB sym = obtTdS($1);
                            DIM dim = obtTdA(sym.ref);
                            if ($3.tipo != T_ERROR && $6.tipo != T_ERROR) {
                                if(sym.t == T_ERROR) {
                                    yyerror("Objeto no declarado");
                                }else if(sym.t != T_ARRAY) { /* Tenemos que tratar con un array */
                                    yyerror("El identificador debe ser de tipo \"array\"");
                                } else {
                                    if($3.tipo != T_ENTERO) { /* Se accede a los indicies con enteros */
                                        yyerror("El índice del \"array\" debe ser entero");
                                    } 
                                    else if($6.tipo != dim.telem) { /* La asignacion no coincide con el tipo del array */
                                        yyerror("Error de tipos en la \"asignacion\"");
                                    } 
                                }
                            }
                            emite(EVA,crArgPos(sym.n,sym.d),crArgPos(niv,$3.desp),crArgPos(niv,$6.desp));
                        }
                      | ID_ PUNT_ ID_ ASIG_ expresion FINL_ {
                            SIMB sym = obtTdS($1);
                            CAMP camp = obtTdR(sym.ref, $3);
                            if($5.tipo != T_ERROR) {
                                if(sym.t == T_ERROR)
                                    yyerror("Objeto no declarado");
                                else if(sym.t != T_RECORD)
                                    yyerror("El identificador debe ser de tipo \"struct\"");
                                else {
                                    if(camp.t == T_ERROR)
                                    	yyerror("Campo no declarado");
                                    else if(camp.t != $5.tipo)
                                        yyerror("Error de tipos en la \"asignacion\"");
                                }
                                int d = sym.d + camp.d; /*sumamos desplazamientos*/
                                emite(EASIG,crArgPos(niv,$5.desp),crArgNul(),crArgPos(sym.n,d));
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
                            emite(EREAD,crArgNul(),crArgNul(),crArgPos(sym.n, sym.d));
                        }
                         | PRINT_ APAR_ expresion CPAR_ FINL_ {
                           if($3.tipo != T_ENTERO) {
                              yyerror("La expresion del \"print\" debe ser entera");
                           }
                           emite(EWRITE,crArgNul(),crArgNul(),crArgPos(niv, $3.desp));
                         }
                         ;

/********************************************************************/

instruccionSeleccion : IF_ APAR_ expresion CPAR_{
                        if($3.tipo != T_LOGICO && $3.tipo != T_ERROR)
                            yyerror("La expresion del \"if\" debe ser \"logico\"");
                        $<cent>$ = creaLans(si); /*creamos la LANS*/
                        emite(EIGUAL,crArgEnt(0), crArgPos(niv,$3.desp), crArgEtq(-1)); /*-1 para rellenar */
                        }
                        instruccion {
                            $<cent>$ = creaLans(si);
                            emite(GOTOS,crArgNul(),crArgNul(),crArgEtq(-1)); /*-1 para rellenar*/
                            completaLans($<cent>5, crArgEtq(si)); /*saltamos en caso de ELSE */
                        }
                        ELSE_ instruccion {
                            completaLans($<cent>7, crArgEtq(si)); /*donde saltamos al final y despues del IF*/
                        }
                     ;

/********************************************************************/

instruccionIteracion : WHILE_ { $<cent>$ = si; /*direccion de expresion*/} APAR_ expresion {
                        if($4.tipo != T_LOGICO && $4.tipo != T_ERROR)
                            yyerror("La expresion del \"while\" debe ser \"logico\"");
                        $<cent>$ = creaLans(si); /*nos guardamos la dir. del emite */
                        emite(EIGUAL,crArgEnt(0),crArgPos(niv,$4.desp),crArgEtq(-1)); /*-1 ara rellenar*/
                        } CPAR_ instruccion {
                        emite(GOTOS,crArgNul(),crArgNul(),crArgEtq($<cent>2)); /*saltamos al inicio del bucle */
                        completaLans($<cent>5,crArgEtq(si));/*completa la lista, tiene que saltar fuera */
                        }
                     ;

/********************************************************************/

expresion : expresionIgualdad {$$ = $1;}
          | expresion operadorLogico expresionIgualdad {
                if ($1.tipo == T_ERROR || $3.tipo == T_ERROR) 
                   $$.tipo = T_ERROR;
                else if(!($1.tipo == T_LOGICO && $1.tipo == $3.tipo)) {
                    $$.tipo = T_ERROR;
                    yyerror("Error en \"expresion logica\"");
                }
                else
                    $$.tipo = T_LOGICO;
                
                $$.desp = creaVarTemp();
                emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp));
                if($2 == ESUM) {
                    /* if $$ <= 1 then goto si + 2 (diapositivas) */
                    emite(EMENEQ, crArgPos(niv, $$.desp), crArgEnt(1), crArgEtq(si + 2));
                    /*asignacion por si la suma da mayor que uno */
                    emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.desp));
                }
          }
          ;

/********************************************************************/

expresionIgualdad : expresionRelacional {$$ = $1;}
                  | expresionIgualdad operadorIgualdad expresionRelacional {
                        if($1.tipo == T_ERROR || $3.tipo == T_ERROR)
                            $$.tipo = T_ERROR;
                        else if(!(($1.tipo == T_LOGICO && $1.tipo == $3.tipo) || ($1.tipo == T_ENTERO && $1.tipo == $3.tipo) )) {
                            $$.tipo = T_ERROR;
                            yyerror("Error en \"expresion de igualdad\"");
                        } else {
                            $$.tipo = T_LOGICO;
                        }
                        $$.desp = creaVarTemp();
                        emite(EASIG,crArgEnt(1),crArgNul(), crArgPos(niv, $$.desp));
                        emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgEtq(si + 2));
                        emite(EASIG,crArgEnt(0),crArgNul(), crArgPos(niv, $$.desp));
                  }
                  ;

/********************************************************************/

expresionRelacional : expresionAditiva {$$ = $1;}
                    | expresionRelacional operadorRelacional expresionAditiva {
                        if($1.tipo == T_ERROR || $3.tipo == T_ERROR)
                           $$.tipo = T_ERROR;
                        else if(!($1.tipo == T_ENTERO && $1.tipo == $3.tipo)) {
                           $$.tipo = T_ERROR;
                           yyerror("Error en \"expresion relacional\"");
                        } else 
                           $$.tipo = T_LOGICO;

                        $$.desp = creaVarTemp();
                        /*asumimos que es true la expresion, si se cumple saltamos, si no se cumple es false y por tanto 0 */
                        emite(EASIG,crArgEnt(1),crArgNul(), crArgPos(niv, $$.desp));
                        emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgEtq(si + 2));
                        emite(EASIG,crArgEnt(0),crArgNul(), crArgPos(niv, $$.desp));                        
                    }
                    ;

/********************************************************************/

expresionAditiva : expresionMultiplicativa  {$$ = $1;} 
                 | expresionAditiva operadorAditivo  expresionMultiplicativa {
                        if($1.tipo == T_ERROR || $3.tipo == T_ERROR)
                            $$.tipo = T_ERROR;
                        else if($1.tipo != T_ENTERO || $3.tipo != T_ENTERO) {
                            $$.tipo = T_ERROR;
                            yyerror("Error en \"expresion aditiva\"");
                        } else 
                            $$.tipo = T_ENTERO;
                        
                        $$.desp = creaVarTemp();
                        emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp));
                 }
                 ;

/********************************************************************/

expresionMultiplicativa : expresionUnaria {$$ = $1;}
                        | expresionMultiplicativa operadorMultiplicativo expresionUnaria {
                            if($1.tipo == T_ERROR || $3.tipo == T_ERROR)
                              $$.tipo = T_ERROR;
                            else if($1.tipo != T_ENTERO || $3.tipo != T_ENTERO) {
                              $$.tipo = T_ERROR;
                              yyerror("Error en \"expresion multiplicativa\"");
                            }
                            else {
                              $$.tipo = T_ENTERO;
                            }
                        
                            $$.desp = creaVarTemp();
                            emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp));
                        }
                        ;

/********************************************************************/

expresionUnaria : expresionSufija {$$ = $1;}
                | operadorUnario expresionUnaria {
                    if($2.tipo == T_ERROR)
                        $$.tipo = $2.tipo;

                    // Revisar este tratamiento del error
                    else if($1 != $2.tipo) {
                        yyerror("Error en \"expresion unaria\"");
                        $$.tipo = T_ERROR;
                    }else {
                        $$.tipo = $2.tipo;
                    }

                    $$.desp = creaVarTemp();
                    switch($1)
                    {
                        case T_ENTERO:
                            // Cambio de signo MENOS
                            emite($1, crArgPos(niv, $2.desp), crArgNul(), crArgPos(niv, $$.desp));
                            break;
                        
                        case T_LOGICO:
                            // Negación logica x=1-x
                            emite($1, crArgEnt(1), crArgPos(niv, $2.desp), crArgPos(niv, $$.desp))
                            break:

                    }

                }
                ;

/********************************************************************/

expresionSufija : constante {
                    $$ = $1;
                }
                | APAR_ expresion CPAR_ {
                    $$ = $2;
                }
                | ID_ {
                    SIMB sym = obtTdS($1);
                    if(sym.t == T_ERROR) {
                        $$.tipo = T_ERROR;
                    }else
                        $$.tipo = sym.t;

                    $$.desp = creaVarTemp();
                    emite(EASIG, crArgPos(sym.n, sym.d), crArgNul(), crArgPos(niv, $$.desp));
                  }
                | ID_ PUNT_ ID_ {
                    SIMB sym = obtTdS($1);
                    CAMP camp = obtTdR(sym.ref, $3);
                    /*¿ERROR?*/
                    if(sym.t == T_ERROR) {
                        yyerror("Objeto no declarado");
                        $$.tipo = T_ERROR;
                    } else if(sym.t != T_RECORD) { /*¿Estructura*/
                        yyerror("El identificador debe ser de tipo \"struct\"");
                        $$.tipo = T_ERROR;
                    } else {
                        if (camp.t == T_ERROR) { /*¿Campo declarado?*/
                            yyerror("Campo no declarado");
                            $$.tipo = T_ERROR;
                        } else {
                            $$.tipo = camp.t;
                        }
                    }
                    int d = sym.d + camp.d;
                    $$.desp = creaVarTemp();
                    emite(EASIG,crArgEnt(d), crArgNul(), crArgPos(niv, $$.desp));
                    
                }
                | ID_ AIND_ expresion CIND_ {
                    SIMB sym = obtTdS($1);
                    DIM dim = obtTdA(sym.ref);
                    if(sym.t == T_ERROR) { /*¿Error? */
                        yyerror("Objeto no declarado");
                        $$.tipo = T_ERROR;
                    } else if(sym.t != T_ARRAY) { /* ¿Array */
                        yyerror("El identificador debe ser de tipo \"array\"");
                        $$.tipo = T_ERROR;
                    } else if($3.tipo != T_ENTERO) { /* Indice entero */
                        yyerror("El indice del \"array\" debe ser entero");
                        $$.tipo = T_ERROR;
                    }  else {
                        $$.tipo = dim.telem;
                    }
                    /* no hace falta la primera instruccion del temario, la talla de todos los tipos es 1 */
                    $$.desp = creaVarTemp();
                    emite(EAV, crArgPos(sym.n,sym.d), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp));
                }
                | ID_ { 
                    /***reservar espacio para el valor de retorno**/
                    emite(INCTOP,crArgNul(),crArgNul(),crArgEnt(TALLA_TIPO_SIMPLE));
                    }
                APAR_ parametrosActuales CPAR_ {
                    SIMB sym = obtTdS($1);
                    INF inf = obtTdD(sym.ref);
                    $$.tipo = T_ERROR; /* si no llega hasta el ultimo else se queda esto */
                    if(sym.t == T_ERROR)
                        yyerror("Objeto no declarado");
                    else {   
                        if (inf.tipo == T_ERROR) 
                            yyerror("El identificador no es una funcion");
                        else if (cmpDom(sym.ref, $4) == 0)
                            yyerror("El dominio de los parametros actuales no coincide con el de la funcion");
                        else
                            $$.tipo = inf.tipo;
                    }
                    $$.desp = creaVarTemp();
                    /**llamada a la funcion**/
                    emite(CALL, crArgNul(), crArgNul(), crArgEtq(sym.d));
                    /** desapilar segmento de parametros**/
                    emite(DECTOP,crArgNul(),crArgNul(),crArgEnt(inf.tsp));
                    /**desapilar y asignar valor de retorno*/
                    emite(EPOP,crArgNul(),crArgNul(),crArgPos(niv, $$.desp));

                }
                ;

/********************************************************************/

constante : CTE_ {$$.tipo = T_ENTERO; $$.desp=creaVarTemp();emite(EASIG,crArgEnt($1),crArgNul(),crArgPos(niv,$$.desp));}
          | TRUE_ {$$.tipo = T_LOGICO; $$.desp=creaVarTemp();emite(EASIG,crArgEnt(1),crArgNul(),crArgPos(niv,$$.desp));}
          | FALSE_ {$$.tipo = T_LOGICO; $$.desp=creaVarTemp();emite(EASIG,crArgEnt(0),crArgNul(),crArgPos(niv,$$.desp));}
          ;

/********************************************************************/

parametrosActuales : {$$ = insTdD(-1, T_VACIO);} /* funcion sin parametros */
                   | listaParametrosActuales {$$ = $1;}
                   ;

/********************************************************************/

listaParametrosActuales : expresion {$$ = insTdD(-1, $1.tipo);}
                        | expresion COMA_ listaParametrosActuales {
                            $$ = insTdD($3, $1.tipo); 
                        }
                        ;

/********************************************************************/

operadorLogico : AND_ {$$ = EMULT;}
               | OR_ {$$ = ESUM;}
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

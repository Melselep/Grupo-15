%{
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
extern char *yytext;
extern int yyleng;
extern int yylex(void);
extern void yyerror(char*);
int variable=0;
%}
%union{
   char* cadena;
   int num;
} 
%token ASIGNACION PYCOMA SUMA RESTA PARENIZQUIERDO PARENDERECHO COMA LEER ESCRIBIR INICIO FIN 
%token <cadena> ID
%token <num> CONSTANTE
%start programa

%%
/* objetivo: programa FDT */
programa: INICIO sentencias FIN
sentencias:  sentencias sentencia 
|sentencia
;
sentencia: ID {if(yyleng>32) yyerror("la longitud de la sentencia es mayor que lo permitido");} ASIGNACION expresion PYCOMA
| LEER PARENIZQUIERDO  lista_identificadores PARENDERECHO PYCOMA
| ESCRIBIR PARENIZQUIERDO lista_expresiones PARENDERECHO PYCOMA 
;
lista_expresiones:  expresion COMA lista_expresiones
| expresion
; 
lista_identificadores: ID COMA lista_identificadores
| ID
;
expresion: primaria 
|expresion operadorAditivo primaria
; 
primaria: ID
|CONSTANTE {printf("valores %d %d",atoi(yytext),$1);}
|PARENIZQUIERDO expresion PARENDERECHO
;
operadorAditivo: SUMA 
| RESTA
;
%%

int main() {
yyparse();
}
void yyerror (char *s){
printf ("Error semático: %s\n",s);
}
int yywrap()  {
  return 1;  
} 


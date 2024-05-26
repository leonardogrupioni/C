#include <stdio.h>
#include "eq2g.h"
/*
* Imprime a equacao do 2o grau
* Parametros:
*   Eq2g eq - equacao do 2o grau
*/
void imprimirEq2g(Eq2g eq){
    printf("\nEquacao: %.2lfx^2 + %.2lfx + %.2lf", eq.a, eq.b, eq.c);
}

/*
* Imprime delta da equacao do 2o grau
* Parametros:
*   Eq2g eq - equacao do 2o grau
*/
void imprimirDelta(Eq2g eq){
    printf("\ndelta = %lf", calcularDelta(eq));
}

/*
* Imprime as raizes da equacao do 2o grau
* Parametros:
*   double raiz1 - raiz1 da equacao do 2o grau
*   double raiz2 - raiz2 da equacao do 2o grau
*/
void imprimirRaizes(double raiz1, double raiz2){
    printf("\nRaiz1 = %lf", raiz1);
    printf("\nRaiz2 = %lf", raiz2);
}

/*
* Imprime mensagem
* Parametros:
*   char msg[] - mensagem que sera impressa
*/
void imprimirMsg(char msg[]){
    printf("\n%s\n\n", msg);
}


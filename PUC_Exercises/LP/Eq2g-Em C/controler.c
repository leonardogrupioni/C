#include <math.h>
#include "eq2g.h"
/*
* Calcula o valor de delta
* Parametros:
*   Eq2g eq - equacao do 2o grau
* Retorno:
*   double delta - valor de delta
*/
double calcularDelta(Eq2g eq){
    return (eq.b * eq.b - 4*eq.a*eq.c);
}

/*
* Calcula o valor da raiz 1
* Parametros:
*   Eq2g eq - equacao do 2o grau
* Retorno:
*   double raiz1 - valor da raiz1
*/
double calcularRaiz1(Eq2g eq){
    double delta = calcularDelta(eq);
    double raiz1 = (-eq.b + sqrt(delta))/(2*eq.a);

    return (raiz1);
}

/*
* Calcula o valor da raiz 2
* Parametros:
*   Eq2g eq - equacao do 2o grau
* Retorno:
*   double raiz1 - valor da raiz1
*/
double calcularRaiz2(Eq2g eq){
    double delta = calcularDelta(eq);
    double raiz2 = (-eq.b - sqrt(delta))/(2*eq.a);

    return (raiz2);
}

boolean temRaizes(Eq2g eq){
    boolean ret = TRUE;

    double delta = calcularDelta(eq);

    if (delta < 0) ret = FALSE;

    return ret;
}


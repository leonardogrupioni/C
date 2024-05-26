#include <stdio.h>
#include <stdlib.h>
#include "eq2g.h"

int main()
{
    // Utilizacao de novo tipo
    Eq2g eq1;


    double raiz1, raiz2;

    printf("===================================\n");
    printf(" Calculadora de equacao do 2o Grau\n");
    printf("===================================\n");

    // Entrada de dados
    printf("\nForneca valor de a: ");
    scanf("%lf", &eq1.a);

    printf("\nForneca valor de b: ");
    scanf("%lf", &eq1.b);

    printf("\nForneca valor de c: ");
    scanf("%lf", &eq1.c);

    imprimirEq2g(eq1);

    imprimirDelta(eq1);

    if (temRaizes(eq1)){
        raiz1 = calcularRaiz1(eq1);
        raiz2 = calcularRaiz2(eq1);
        imprimirRaizes(raiz1, raiz2);
    } else {
        imprimirMsg("Nao existem raizes Reais.");
    }

    return 0;
}

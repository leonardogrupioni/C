#include <stdio.h>
#include <stdlib.h>

int main()
{
    // imc = indice de massa corporal
    float imc, peso, altura;

    printf("Calculadora de IMC\n");
    printf("Qual o seu peso em kg:");
    scanf("%f", &peso);
    printf("Qual a sua altura em metros: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    //printf("Seu IMC eh: %.1f\n", imc);

    if (imc < 18.5) {
        printf("Seu peso esta baixo");
    } else if (imc < 24.9){
            printf("Seu peso esta normal");
        } else {
            printf("Voce esta com sobrepeso");
        }

    return 0;
}

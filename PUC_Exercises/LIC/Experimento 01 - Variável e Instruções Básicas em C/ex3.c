//EX_3
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // TempFahr = Temperatura em Fahrenheit; TempGC = Temperatura em Celcius
    float TempFahr, TempGC;

    printf("Qual o valor da temperatura em Fahrenheit: ");
    scanf("%f", &TempFahr);


    TempGC = (TempFahr - 32) / 1.8;

    printf("A temperatura convertida em graus C é: %5.2f\n", TempGC);


    if (TempGC < 0) {
        printf("a substancia esta em estado solido\n");
    } else {
        if (TempGC < 100) {
            printf("a substancia esta em estado liquido\n");
        } else {
            printf("a substancia esta em estado gasoso\n");
        }

    }

    return 0;
}

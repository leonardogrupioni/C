#include <stdio.h>
#include <stdlib.h>

int main() {

    float multa = 0;
    int veiculos = 0, casas = 0;

    do {
        printf("Quantos veiculos ha na residencia: ");
        scanf("%d", &veiculos);
        if (veiculos != 999 && veiculos > 2){
            casas = casas+1;
            multa = (veiculos - 2) * 12.89 + multa;
        }
    } while (veiculos!=999);

    printf("O total mensal arrecadado eh: RS%.2f  e a quantidade de casas multadas eh %d", multa, casas);

    return 0;
}

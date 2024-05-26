#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_CTYPE, "Portuguese");
    int num;
    printf("\nDigite um número inteiro: ");
    scanf("%d", &num);
    if (num%2==0){
            printf("\nO Número digitado é par!\n");
            num = num/2;
            if (num%2==0){
                printf("\nA metade do número par é par!\n");
            }else {
                printf("\nA metade do número par é ímpar!\n");
            }
    }else {
        printf("\nO Número digitado é impar!\n");
        }

    return 0;

}

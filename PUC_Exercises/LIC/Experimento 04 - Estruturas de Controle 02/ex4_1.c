#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_CTYPE, "Portuguese");
    int num;
    printf("\nDigite um n�mero inteiro: ");
    scanf("%d", &num);
    if (num%2==0){
            printf("\nO N�mero digitado � par!\n");
            num = num/2;
            if (num%2==0){
                printf("\nA metade do n�mero par � par!\n");
            }else {
                printf("\nA metade do n�mero par � �mpar!\n");
            }
    }else {
        printf("\nO N�mero digitado � impar!\n");
        }

    return 0;

}

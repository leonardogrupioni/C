#include <stdio.h>
#include <stdlib.h>

int main() {

    float nota, soma, media;
    int n;
    soma = 0;
    n = 0;
    do {
        printf("Nota do aluno: ");
        scanf("%f", &nota);
        if (nota != -1){
            soma = soma+nota;
            n = n+1;
        }

    } while (nota!=-1);

    media = soma / n;
    printf("A media da sala eh: %.2f", media);


    return 0;
}

#include "domino.h"
#include <stdio.h>
#include <stdlib.h>

void embaralharPecas(PECAS pecas[]){ //embaralharPecas: -pegar 28 numeros aleatorios e entregar ao usuario

    int temp = 0;
    int r = 0;
    for(int i = 0; i < 28; i++){
        r =  rand () % 28;
        temp = pecas[i].posicao;
        pecas[i].posicao = pecas[r].posicao;
        pecas[r].posicao = temp;
    }

    printf("\nAs 28 pecas embaralhadas sao: \n");
    for(int i = 0; i < 28; i++){
        //printf("Peca aleatoria #%d: %d | %d\n", pecas[i].posicao+1, pecas[i].l1, pecas[i].l2);
        printf("Peca aleatoria #%d: %d | %d\n", i+1, pecas[pecas[i].posicao].l1, pecas[pecas[i].posicao].l2);
    }
}

void desembaralharPeca(PECAS pecas[]){
    for(int i = 0; i < 28; i++){
       pecas[i].posicao = i;
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\nAs 28 pecas desembaralhadas sao: \n");
    for(int i = 0; i < 28; i++){
        printf("Peca #%d: %d | %d\n", pecas[i].posicao+1, pecas[i].l1, pecas[i].l2);
    }
}

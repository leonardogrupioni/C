#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "domino.h"
//#include "mudaPosicao.h"

void inicializarPecas(PECAS pecas[]){
    int i = 0;
        for(int j = 0; j <= 6; j++){ //0 0 0 0 0 0 0 1 1 1 1 1 1 2 2 2 2 2 3 3 3 3 4 4 4 5 5 6
            for(int k = j ; k <= 6; k++){ //0 1 2 3 4 5 6 1 2 3 4 5 6 2 3 4 5 6 3 4 5 6 4 5 6 5 6 6
                pecas[i].l1 = j; //atribui valor ao lado 1
                pecas[i].l2 = k; //atribui valor ao lado 2
                i++;
            }
        }
    for(int i = 0; i < 28; i++){
       //pecas[i].id = i;
       pecas[i].posicao = i;//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28
    }
}

void imprimirTodasPecas(PECAS pecas[]){
    printf("Pecas do Domino\nTotal: 28\n\n");
    printf("          Pecas\n");
    printf("N-daPeca Lado 1 | Lado 2\n");
    for(int i = 0; i < 28; i++){
        printf("   %d      %d   |   %d  \n", i+1, pecas[i].l1,pecas[i].l2);
    }
}

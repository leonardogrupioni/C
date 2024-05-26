#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "domino.h"
#include "mudaPosicao.h"

int main(){
    //funcao para gerar sempre um novo numero randomico
    srand(time(0));

    printf("JOGO DE DOMINO!\n\n");

    //criando array pecas:
    PECAS pecas[28];

    inicializarPecas(pecas);

    imprimirTodasPecas(pecas);

    embaralharPecas(pecas);

    desembaralharPeca(pecas);

    /*
    //vendendo as 7 primeiras peças
    printf("\n");
    printf("\n");
    printf("\n");
    for(int i = 0; i < 7; i++){
        pecas[i].stats = '1';
        printf("Peca entregue #%d: %d / %d", i+1, pecas[pecas[i].posicao].l1, pecas[pecas[i].posicao].l2);
        printf("\n");
    }

    */ //ideia para o futuro do projeto
    return 0;
}
 

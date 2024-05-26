#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include "mapa.h"

MAPA m; //declarando o mapa como struct e nomeando como m
POSICAO heroi;

int acabou(){
    return 0;
}

int ehDirecao(char direcao){
     return
        direcao == ESQUERDA || 
        direcao == CIMA ||
        direcao == BAIXO ||
        direcao == DIREITA;
    //retornando em logica booleana se for direcao devolve 0 se nao for devolve 1
}



void move(char direcao){

    //validando entrada do usuario
    if(!ehDirecao(direcao)) return; //sai da funcao automaticamente se o usuario digitar algo invalido
       //leia sempre ! como nao, se nao for direcao acaba a funcao, se for continua

    int proximox = heroi.x;
    int proximoy = heroi.y;

    //posicionando
    switch(direcao) {
        case ESQUERDA:
            proximoy--;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;
    }

    //testando obstaculos
    if(!ehValida(&m, proximox, proximoy)) {
        return;
    }
    if(!ehVazia(&m, proximox, proximoy)) {
        return;
    }

    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}

int main(){
    
    leMapa(&m);
    encontraMapa(&m, &heroi, HEROI);

    do {

        imprimeMapa(&m);

        char comando; //comando dado pelo usuario
        scanf(" %c", &comando);
        move(comando);
    
    } while(!acabou());

    
    liberaMapa(&m);

}

//OBS: escreva codigos que deixem claro a intencao ou seja use funcoes para isso e nomes melhores
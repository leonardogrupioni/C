//Model = aqui ficam as funcoes referentes a alteracoes de memoria, como alteracao das variaveis e arrays
//        alem disso structs e funcoes referentes a mesma ficam nos arquivos model.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "model.h"
#include "view.h"
#include "controller.h"

//funcao de inicializar pecas
void inicializarVariaveis(PECA pecas[], PECA_MESA mesa[], CONTADOR * cont){
    //inicializando pecas:*
    int i = 0;
    for(int j = 0; j <= 6; j++){ //0 0 0 0 0 0 0 1 1 1 1 1 1 2 2 2 2 2 3 3 3 3 4 4 4 5 5 6
        for(int k = j ; k <= 6; k++){ //0 1 2 3 4 5 6 1 2 3 4 5 6 2 3 4 5 6 3 4 5 6 4 5 6 5 6 6
            pecas[i].lado1 = j; //atribui valor ao lado 1
            pecas[i].lado2 = k; //atribui valor ao lado 2
            pecas[i].id = i;//atribui a posicao das peças em ordem 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
            i++;
        }
    }
    
}

void embaralharPecas(PECA pecas[]){ //embaralharPecas: pegar numeros aleatorios de 0 a 27 para trocar a posicao de todas as pecas
    srand(time(0)); //funcao para gerar sempre uma nova semente para gerar os numeros randomicos
    PECA temp; //variavel auxiliar para a substituicao das posicoes de lugar
    int r = 0; //variavel que recebe o numero aleatorio gerado pela funcao rand
    for(int i = 0; i < 28; i++){
        r =  rand () % 28; //funcao que gera o numero aleatorio
        temp = pecas[i]; //recebe a posicao i
        pecas[i] = pecas[r]; //passa a posicao randomica para a posicao i
        pecas[r] = temp; //envia para a posicao randomica a antiga posicao de i
    }
}

void distribuirPecas(PECA pecas[], CONTADOR * cont){
    for(int i = 0; i < 7; i++){
        pecas[i].status = JOGADOR_1; //envia pecas para o jogador 1
        pecas[i+7].status = JOGADOR_2; //envia pecas para o jogador 2
    }
    for(int i = 14; i < 28; i++){
        pecas[i].status = PILHA; //inicializa a pilha de pecas para compra
    }

    //inicializando contadores:
    cont->jogador1 = 7; 
    cont->jogador2 = 7;
    cont->pilha = 14;
    cont->mesa = 0;
}


int conferirPecaInicial(PECA pecas[], PECA_MESA mesa[], CONTADOR * cont){
    //funcao que retorna 1 para jogador 1 e 2 para jogador 2
    int pecaMaior = -1;
    int posicaoPecaMaior = -1;
    for(int i = 0; i < 14; i++){
        //debug//
        printf("peca #%d: %d | %d\n", i, pecas[i].lado1, pecas[i].lado2); 
        if(pecas[i].lado1 == pecas[i].lado2){
            if(pecas[i].lado1 > pecaMaior){
                pecaMaior = pecas[i].lado1;
                posicaoPecaMaior = i; //se peca maior estiver entre 0 e 6 J1 entre 7 e 13 J2
            }
        } 
    }
    
    if(posicaoPecaMaior != -1){
        if(posicaoPecaMaior < 14 && posicaoPecaMaior > 6) {
            fazerPrimeiraJogada(posicaoPecaMaior, pecas, mesa, &cont); //model
            return 2;
        } else {
            fazerPrimeiraJogada(posicaoPecaMaior, pecas, mesa, &cont); //model
            return 1;
        }
    } else {
        //conferir o player q tem a peca com maior soma 3 2 = 5 5 0 = 5
        int resultadoSoma[2];
        
        int controle = 0;
        do {
            conferirSomaPecas(pecas, &resultadoSoma);
            if(resultadoSoma[0] > resultadoSoma[1]){
                fazerPrimeiraJogada(posicaoPecaMaior, pecas, mesa, &cont); //model
                return 1;
                controle = 1; //manter estrutura de controle (perguntar se precisa)
            } else if(resultadoSoma[0] < resultadoSoma[1]){
                fazerPrimeiraJogada(posicaoPecaMaior, pecas, mesa, &cont); //model
                return 2;
                controle = 1;
            } else controle = 0;
        }while(controle == 0);//acessar funcao
    }
}

void conferirSomaPecas(PECA pecas[], int soma[]){ //Encontra a maior soma entre as pecas dos dois jogadores
    int maiorSomaJ1 = 0;
    int maiorSomaJ2 = 0;
    int somaJ1 = 0;
    int somaJ2 = 0;
        
    for(int i = 0; i < 7; i++)
    {
        somaJ1 = pecas[i].lado1 + pecas[i].lado2; //j1
        somaJ2 = pecas[i+7].lado1 + pecas[i+7].lado2; //j2
        
        if(somaJ1 > maiorSomaJ1){ 
            
            maiorSomaJ1 = somaJ1; 
        } 
        if(somaJ2 > maiorSomaJ2){  

            maiorSomaJ2 = somaJ2;
        } 
    }
    soma[0] = maiorSomaJ1; 
    soma[1] = maiorSomaJ2;

}

void fazerPrimeiraJogada(int posicaoPecaMaior, PECA pecas[], PECA_MESA mesa[], CONTADOR * cont){
    mesa[0].lado1 = pecas[posicaoPecaMaior].lado1;
    mesa[0].lado2 = pecas[posicaoPecaMaior].lado2;
    pecas[posicaoPecaMaior].status = MESA;
    cont->mesa++;
    if(posicaoPecaMaior < 7){
        //jogador 1
        cont->jogador1--;
        mesa[0].jogador = 1;
    } else {
        //jogador 2
        cont->jogador2--;
        mesa[0].jogador = 2;
    }
}

int fimDeJogo(PECA pecas[], CONTADOR * cont, PECA_MESA mesa[]){ // Verifica se as pecas de algum dos jogadores acabou
    if (cont->jogador1 == 0 || cont->jogador2 == 0){
        return 0;
    }
    
    else {
        return 1;
    }
}

int testarJogada(PECA pecas[],int pecaSelecionada, PECA_MESA mesa[],int lados[]){
 
    if(pecas[pecaSelecionada].lado1 == lados[0]){
        return 1;
    }else if(pecas[pecaSelecionada].lado2 == lados[1]){
        return 1;
    }if(pecas[pecaSelecionada].lado2 == lados[0]){
        inverterPeca(pecas, pecaSelecionada);
        return 1;
    }else if(pecas[pecaSelecionada].lado1 == lados[1]){
        inverterPeca(pecas, pecaSelecionada);
        return 1;
    }else return 0;
}

void inverterPeca(PECA pecas[], int pecaSelecionada){
    int temp = 0;

    temp = pecas[pecaSelecionada].lado1;

    pecas[pecaSelecionada].lado1 = pecas[pecaSelecionada].lado2;
    pecas[pecaSelecionada].lado2 = temp;
}
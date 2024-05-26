#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"

//Model = aqui ficam as funcoes referentes a alteracoes de memoria, como alteracao das variaveis e arrays
//        alem disso structs e funcoes referentes a mesma ficam nesete arquivo

//funcao de inicializar pecas
void inicializarPecas(PECA pecas[]){
    int i = 0;
    for(int j = 0; j <= 6; j++){ //0 0 0 0 0 0 0 1 1 1 1 1 1 2 2 2 2 2 3 3 3 3 4 4 4 5 5 6
        for(int k = j ; k <= 6; k++){ //0 1 2 3 4 5 6 1 2 3 4 5 6 2 3 4 5 6 3 4 5 6 4 5 6 5 6 6
            pecas[i].l1 = j; //atribui valor ao lado 1
            pecas[i].l2 = k; //atribui valor ao lado 2
            pecas[i].posicao = i;//atribui a posicao das peças em ordem 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
            i++;
        }
    }
}

//funcao que emaralha as pecas do domino, mais especificamente embaralha a variavel posicao do struct
void embaralharPecas(PECA pecas[]){ //embaralharPecas: pegar numeros aleatorios de 0 a 27 para trocar a posicao de todas as pecas
    srand(time(0)); //funcao para gerar sempre uma nova semente para gerar os numeros randomicos
    int temp = 0; //variavel auxiliar para a substituicao das posicoes de lugar
    int r = 0; //variavel que recebe o numero aleatorio gerado pela funcao rand
    for(int i = 0; i < 28; i++){
        r =  rand () % 28; //funcao que gera o numero aleatorio
        temp = pecas[i].posicao; //recebe a posicao i
        pecas[i].posicao = pecas[r].posicao; //passa a posicao randomica para a posicao i
        pecas[r].posicao = temp; //envia para a posicao randomica a antiga posicao de i
    }
}

void desembaralharPeca(PECA pecas[]){ //desembaralha as pecas voltando a variavel posicao ao seu valor inicial (re-inicializa)
    for(int i = 0; i < 28; i++){
       pecas[i].posicao = i;
    }
}

void distribuirPecas(PECA pecas[]){
    for(int i = 0; i < 7; i++){
        pecas[(pecas[i].posicao)].stats = J1; //envia pecas para o jogador 1
        pecas[(pecas[i].posicao+7)].stats = J2; //envia pecas para o jogador 2
    }
    for(int i = 14; i < 28; i++){
        pecas[(pecas[i].posicao)].stats = PILHA; //inicializa a pilha de pecas para compra
    }

    //inicializar pecas 
    pecas->contJ1 = 7;
    pecas->contJ2 = 7;
    pecas->contPilha = 14;
    pecas->contMesa = 0;
    
}

int conferirPecaInicial(PECA pecas[]){
    //funcao que retorna 1 para jogador 1 e 2 para jogador 2
    int pecaMaior = -1;
    int posicaoPecaMaior = -1;
    for(int i = 0; i < 14; i++){
        //debug//
        printf("peca #%d: %d | %d\n", i, pecas[pecas[i].posicao].l1, pecas[pecas[i].posicao].l2); 
        if(pecas[pecas[i].posicao].l1 == pecas[pecas[i].posicao].l2){
            if(pecas[pecas[i].posicao].l1 > pecaMaior){
                pecaMaior = pecas[pecas[i].posicao].l1;
                posicaoPecaMaior = i; //se peca maior estiver entre 0 e 6 J1 entre 7 e 13 J2
            }
        } 
    }
    
   if(posicaoPecaMaior != -1){
        if(posicaoPecaMaior < 14 && posicaoPecaMaior > 6) {
            return 2;
        } else return 1;
    } else {
        //conferir o player q tem a peca com maior soma 3 2 = 5 5 0 = 5
        int resultadoSoma[2];
        
        int controle = 0;
        do {
            conferirSomaPecas(pecas, &resultadoSoma);
            if(resultadoSoma[0] > resultadoSoma[1]){
                return 1;
                controle = 1; //manter estrutura de controle (perguntar se precisa)
            } else if(resultadoSoma[0] < resultadoSoma[1]){
                return 2;
                controle = 1;
            } else controle = 0;
        }while(controle == 0);//acessar funcao
    }
}

int fimDeJogo(PECA pecas[]){ // Verifica se as pecas de algum dos jogadores acabou
    if (pecas->contJ1 == 0 || pecas->contJ2 == 0){
        return 0;
    }
    else {
        return 1;
    }
}

/*int verificarTurno(PECA pecas[], int turno){
    
    if(turno % 2 == 0){
        turno = 2;
        return turno;
    }else if(turno % 2 != 0){
        turno = 1;
        return turno;
    }
}*/

/*
void verificarCompraDePecas(PECA pecas[], int turno){
    if(turno > 27){
        msgSemPecas();
    }else if(turno % 2 == 0){
        pecas[pecas[turno].posicao].stats = J2;
    }else if(turno % 2 != 0){
        pecas[(pecas[turno].posicao)].stats = J1;
    }
}
*/
void conferirSomaPecas(PECA pecas[], int soma[]){ //Encontra a maior soma entre as pecas dos dois jogadores
    int maiorSomaJ1 = 0;
    int maiorSomaJ2 = 0;
    int somaJ1 = 0;
    int somaJ2 = 0;
        
    for(int i = 0; i < 7; i++)
    {
        somaJ1 = pecas[pecas[i].posicao].l1 + pecas[pecas[i].posicao].l2; //j1
        somaJ2 = pecas[(pecas[i].posicao+7)].l1 + pecas[(pecas[i].posicao+7)].l2; //j2
        
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





//fazer funcao de jogar a peca, "transformar o stats em mesa"
//fazer funcao de comprar pecas da pilha,"passar o stats de pilha para J1 ou J2"
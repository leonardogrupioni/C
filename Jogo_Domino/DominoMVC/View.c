#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"
//View = arquivo que ficam armazenadas as funcoes referentes a interação com o usuario, quanto de mostrar na tela
//       quanto funcoes de recber dados enviados pelo usuario (funcoes relacionados a printf e scanf) 



void imprimirTodasPecas(PECA pecas[]){
    printf("Pecas do Domino\nTotal: 28\n\n");
    printf("          Pecas\n");
    printf("N-daPeca Lado 1 | Lado 2\n");
    for(int i = 0; i < 28; i++){
        printf("   %d      %d   |   %d  \n", i+1, pecas[i].l1,pecas[i].l2);
    }
}

void imprimirPecasEmbaralhadas(PECA pecas[]){
    
    printf("\nAs 28 pecas embaralhadas sao: \n");
    for(int i = 0; i < 28; i++){
        //possibilidade de transformar em funcao, funcao para imprimir peca, passando como parametro a peca e a posicao
        printf("Peca aleatoria #%d: %d | %d\n", i+1, pecas[pecas[i].posicao].l1, pecas[pecas[i].posicao].l2);
    }
}

void imprimirPecasDesembaralhadas(PECA pecas[]){
    printf("\nAs 28 pecas desembaralhadas sao: \n");
    for(int i = 0; i < 28; i++){
        printf("Peca #%d: %d | %d\n", pecas[i].posicao+1, pecas[i].l1, pecas[i].l2);
    }
}

int escolher() {
    int escolha;
    scanf("%d", &escolha);
    return escolha;
}

void imprimirInterface() {

    printf("\n==============================\n");
    printf("(1) - Jogar\n");
    printf("(2) - Retomar Partida\n");
    printf("(3) - Salvar Partida\n");
    printf("(4) - Carregar Partida Salva\n");
    printf("(5) - Regras\n");
    printf("(0) - Sair\n");
    printf("==============================\n");
    printf("Escolha sua opcao desejada: ");

}

void imprimirJogarMenu(){
    printf("\n==============================\n");
    printf("(1) - Dois jogadores\n");
    printf("(2) - Contra a IA\n");
    printf("==============================\n");
    printf("Escolha sua opcao desejada: ");    
}

void opcaoEscolhaInvalida() {
    printf("Sua opcao e invalida! Tente novamente \n");
}

void iniciarJogo() {
    printf("JOGO DE DOMINO!\n");
}

//funcao temporaria para indicar paginas de futuras etapas
void emDesenvolvimento(){
    printf("AVISO:\nEsta pagina ainda esta em desenvolvimento\nSera feita nas proximas etapas do projeto\n");
}

void sairDoJogo(){
    printf("Sair");
}

void jogadorInicial(int jogador){
    printf("O jogador %c comeca jogando\n", (jogador==1?'1':'2')); //uso do if iternario (se <condicao> <?> for verdadeira entao '<1opcao>' senão <:> '<2opcao>')

}

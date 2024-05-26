
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "model.h"
#include "view.h"
#include "controller.h"

//View = arquivo que ficam armazenadas as funcoes referentes a interação com o usuario, quanto de mostrar na tela
//       quanto funcoes de recber dados enviados pelo usuario (funcoes relacionados a printf e scanf) 

void imprimirTelaInicial(){
    printf("\n\n!!JOGO DE DOMINO!!\n\n");
}

void imprimirMenuPrincipal(){

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

int escolher() {
    int escolha;
    scanf("%d", &escolha);
    return escolha;
}

//funcao temporaria para indicar paginas de futuras etapas
void emDesenvolvimento(){
    printf("AVISO:\nEsta pagina ainda esta em desenvolvimento\nSera feita nas proximas etapas do projeto\n");
}

void imprimirEscolhaInvalida() {
    printf("Sua opcao e invalida! Tente novamente \n");
}

void imprimirSubMenuJogar(){
    printf("\n==============================\n");
    printf("(1) - Dois jogadores\n");
    printf("(2) - Contra a IA\n");
    printf("==============================\n");
    printf("Escolha sua opcao desejada: ");    
}

void imprimirJogar1x1() {
    printf("Iniciando jogo jogador contra jogador...\n");
}

void imprimirJogar1xIA() {
    printf("Iniciando jogo jogador contra Computador...\n");
}

void imprimirJogoIniciado(){
    printf("Jogo iniciado...\n");
    //limpar console
    printf("Peças embaralhadas e distribuidas\n");
    //limpar console
    printf("\nCalculando primeiro a jogar...\n");
    //limpar console + time
    printf("\nQue os jogos comecem!\n");
}

void imprimirJogadorInicial(int primeiroAJogar){
    printf("\nO primeiro a jogar é o jogador %d\n Jogada automatica: \n", primeiroAJogar);
}

void imprimirPeca(PECA pecas[], int posicao){
    printf("[%d|%d]", pecas[posicao].lado1, pecas[posicao].lado2);    
}

void imprimirPecaMesa(PECA_MESA mesa[], int posicao){
    printf("[%d|%d]", mesa[posicao].lado1, mesa[posicao].lado2);    
}

void imprimirMesa(PECA_MESA mesa[], CONTADOR * cont){
    printf("###############################\n");
    for(int i = 0; i < cont->mesa; i++){
        imprimirPecaMesa(mesa, i);
        printf("\t");
    }
    printf("###############################\n");
}

void imprimirTurno(int turno){
    printf("\nTurno do jogo #%d\n", turno);
}

void imprimrVezJogador(int jogador){
    printf("Vez do jogador #%d", jogador);
}

void imprimirMao(PECA pecas[], int jogador, CONTADOR * cont){
    
    //criando auxiliar para testar de quem é a peça
    char c_jogador;
    if(jogador == 1){
        c_jogador = JOGADOR_1;
    } else {
        c_jogador = JOGADOR_2;
    }
    
    printf("Pecas com o jogador #%d:\n", jogador);
    int condicao = 21;
    int auxiliar = 0;
    for(int i = 0; i < condicao; i++){
        if(pecas[i].status == c_jogador){
            imprimirPeca(pecas, i);
            printf("\t");
            auxiliar++;
        }
        if(jogador == 1){
            if(cont->jogador1 == auxiliar){
                condicao = cont->jogador1;
            }
        } else {
            if(cont->jogador2 == auxiliar){
                condicao = cont->jogador2;
            }
        }
    }
    printf("\n");
}

void imprimirMenuJogando(PECA pecas[], int jogador){
    printf("==================\n");
    printf("(1) - Jogar \n");
    printf("(2) - Comprar \n");
    printf("(3) - Sair/Voltar ao Menu \n");
    printf("==================\n");
}

void imprimirSelecionarPeca(CONTADOR * cont, int jogador){
    int condicao;
    condicao = (jogador==1?cont->jogador1:cont->jogador2);
    for(int i = 0; i < condicao; i++){
        printf("%c \t", 'a'+i);
    }
    printf("\n");
}

void imprimirJogadaInvalida(){
    printf("Sua jogada eh invalida!\n");
}

void imprimirJogadaFeita(){
    printf("Jogada feita com sucesso\n");
}

void imprimirCompraIndisponivel(){
    printf("A compra esta indisponivel!\n");
}

void imprimirPassarVez(){
    printf("Sua vez foi passada\n");
}

void imprimirHaJogadaDisponivel(){
    printf("Voce poussi pecas disponiveis para serem jogadas!\n");
}

void imprimirMenuCompra(PECA pecas[], CONTADOR * cont){
    printf("Voce comprou uma peca!\n");
}

void imprimirVoltarMenu(){
    printf("Voltando ao menu principal...\n");
}

void imprimirSairdoPrograma(){
    printf("Sair");
}

int selecionarPeca(CONTADOR * cont, int jogador){
    int temp;
    printf("escolha a peca desejada: ");
    scanf("%d", &temp);
    return temp;
}


//Controller = arquivo responsavel por armazenar o menu e as funcoes que farao a comunicacao do View com o Model, ou seja,
//             uma acao é requerida no View ela é enviada para o Controller que ao receber faz a ponte(conexao) com o Model
//             que executa a funcao necessaria e em seguida devolve para o Controller que envia para o View

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"

/* Funcao acessarMenuPrincipal: objetivo cotrolar o menu principal do jogo, podendo iniciar o jogo, ver regras, salvar o jogo, abrir jogo salvo, re-iniciar ou sair
*
*    PECA pecas[] - Parametro de entrada e saida
*    PECA_MESA mesa[] - Parametro de entrada e saida   
*/
void acessarMenuPrincipal(PECA pecas[], PECA_MESA mesa[], CONTADOR * cont){
    

    imprimirTelaInicial();//view 
    
    inicializarVariaveis(pecas, mesa, &cont);//model

    int escolha = 0; //variavel de escolha para o menu principal
    int sinal = 0; //variavel de sinal para controle da repeticao do menu

    do{
        
        sinal = 0; //para efeito de repeticao
        
        imprimirMenuPrincipal();

        escolha = escolher();//view

        switch(escolha){
            case 1: //jogar
                acessarSubMenuJogo(pecas, mesa, &cont); //controller
                break;
            case 2: //retomar partida em andamento
                emDesenvolvimento(); //view
                break;
            case 3: //salvar partida
                emDesenvolvimento(); //view
                break;
            case 4: //carregar partida salva
                emDesenvolvimento(); //view
                break;
            case 5: //regras
                imprimirRegras(); //view
                break;
            case 6: //re-iniciar programa para jogar novamente
                emDesenvolvimento(); //view
                break;
            case 0: //sair do programa
                imprimirSairdoPrograma(); //view
                sinal = 1; //altera o sinal para acabar com o loop
                break;
            default:
                imprimirEscolhaImvalida(); //view
                break;
        }

    } while(sinal == 0);

}

/* Funcao acessarSubMenuJogo: objetivo cotrolar o submenu do jogar, podendo escolher a quantidade de players e enviando para o controle do jogo 1x1 ou 1xIA
*
*    PECA pecas[] - Parametro de entrada e saida
*    PECA_MESA mesa[] - Parametro de entrada e saida   
*/
void acessarSubMenuJogo(PECA pecas[], PECA_MESA mesa[], CONTADOR * cont) {

    int escolha = 0; //escolha do usuario
    
    int sinal; //para controle do loop
    
    do{
        sinal = 0;
        
        imprimirSubMenuJogar(); //view
        escolha = escolher(); //view

        switch (escolha) {
            case 1: //1x1
                imprimirJogar1x1(); //view
                acessarJogo1x1(pecas, mesa, &cont);//controller
                break;
            case 2: //1xIA
                imprimirJogar1xIA(); //view
                emDesenvolvimento(); //view
                break;
            default:
                imprimirEscolhaImvalida(); //view
                sinal = 1;
                break;
        }
    } while(sinal == 1);

}

/* Funcao acessarJogo1x1: objetivo cotrolar o jogo de 2 jogadores 1x1, um menu que fica em repeticao ate o jogo terminar ou voltar ao menu principal
*
*    PECA pecas[] - Parametro de entrada e saida
*    PECA_MESA mesa[] - Parametro de entrada e saida   
*/
void acessarJogo1x1(PECA pecas[], PECA_MESA mesa[], CONTADOR * cont) {

    imprimirJogoIniciado(); //view

    int turno;
    int jogador;
    int primeiroAJogar;
    int voltarMenu;
    primeiroAJogar = conferirPecaInicial(pecas); //return + model

    imprimirJogadorInicial(primeiroAJogar); //view
    fazerPrimeiraJogada(pecas, mesa, &cont); //model
    imprimirMesa(mesa); //view
    
    //define o proximo jogador
    if(primeiroAJogar == 1){
        jogador = 2;
    } else jogador = 1;

    turno = 1; 

    int escolha;
    //variaveis auxiliares do jogar:
    int sinal;
    int posicao;
    int passar;
    int pecaSelecionada;
    do{
        imprimirMesa(mesa);
        switch (jogador) {
            case 1:
                do {
                    sinal = 1;
                    imprimrVezJogador(jogador);
                    imprimirMao(pecas, jogador);//
                    imprmirMenuJogando();
                    escolha = escolher();
                    switch (escolha){
                        case 1: //jogar
                            imprimirMao(pecas, jogador);
                            imprimirSelecionarPeca(&cont, jogador);
                            pecaSelecionada = selecionarPeca(&cont);
                            sinal = testarJogada(pecas, pecaSelecionada, mesa); //retorna 1 para bem sucedida e 2 para mao sucedida
                            if (sinal == 0){
                                imprimirJogadaInvalida();
                            } else {
                                fazerJogada(pecas, mesa, &cont, pecaSelecionada); //funcao dentro pra conferir lado mesa
                                imprimirJogadaFeita();
                            }
                            break;
                        case 2: //comprar
                            if(cont->pilha == 0){
                                imprimirCompraIndisponivel();
                                passar = verificarJogadasJogador(pecas, jogador);
                                if(passar == 0){
                                    imprimirPassarVez();
                                    sinal = 1;                                    
                                } else imprimirHaJogadaDisponivel();
                            } else {
                                imprimirMenuCompra(pecas, &cont);
                                comprar(pecas, &cont, jogador);
                            } 
                            break;
                        case 3:
                            imprimirVoltarMenu();
                            voltarMenu = 1;
                            sinal = 1;
                            break;
                        default:
                            imprimirEscolhaImvalida(); //view
                            break;
                    }

                    jogador = 2; //pasa para o proximo jogador 
                } while(sinal == 0);
                break;
            case 2:
                //repetir bloco do jogador 1
                jogador = 1;
                break;
            }
        turno++;        
    } while(fimDeJogo() != 0 || voltarMenu != 1); //verif



    //jogo iniciado
    //pecas embaralhadas e distribuidas
    //o jogador x comeca jogando 
    //imprimir mesa 
    //vez do jogador 2
    //interface
        //mesa atual
        //mao do jogador (abcdefghijklmnopqrstu)
        //comprar (2)
        //sair (3)
    //escolhe opcao 
        //peca nao compativel com a mesa atual, jogue novamente
        //comprar ate acabar a compra e passar a vez
    //trocar o turno e inverter o jogador e repetir o laco

}
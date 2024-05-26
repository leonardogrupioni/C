#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"
//#include "Model.c"//a principio nao deveria ter que incluir aqui, mas por conta de bug na IDE foi incluido

//Controller = arquivo responsavel por armazenar o menu e as funcoes que farao a comunicacao do View com o Model, ou seja,
//             uma acao é requerida no View ela é enviada para o Controller que ao receber faz a ponte(conexao) com o Model
//             que executa a funcao necessaria e em seguida devolve para o Controller que envia para o View


void menu(PECA pecas[]) {
    
    iniciarJogo();

    int controle = 1; //para repeticao do menu
    int escolha = 0;
       
    do {
        imprimirInterface();
        escolha = escolher();
        switch (escolha) {
            case 1: //jogar com submenu
                //possibilidade de transformar em funcao
                inicializarPecas(pecas);
                embaralharPecas(pecas);
                distribuirPecas(pecas);
                int jogadores = 0;
                //possibilidade de transformar em funcao
                do{
                    imprimirJogarMenu();
                    jogadores = escolher();
                    switch (jogadores) {
                    case 1: ; //2 jogadores
                        int primeiroAJogar = conferirPecaInicial(pecas);
                        jogadorInicial(primeiroAJogar);

                        break;
                    case 2: //Jogador contra IA
                        emDesenvolvimento();
                        break;
                    default:
                        break;
                    }
                } while(jogadores != 1 && jogadores != 2);
                break;
            case 2: //Retomar partida
                    emDesenvolvimento();
                break;
            case 3: //Salvar partida
                    emDesenvolvimento();
                break;
            case 4: //Carregar partida salva
                    emDesenvolvimento();
                break;
            case 5: //Regras
                    emDesenvolvimento();
                break;
            case 0: //Sair
                sairDoJogo();
                controle = 0;
                break;
            default:
                opcaoEscolhaInvalida();
                break;
        }
    } while (controle != 0);
    
    exit(0);

}

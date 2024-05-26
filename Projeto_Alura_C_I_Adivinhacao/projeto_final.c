```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

    printf("                                            \n\n");
    printf("                 .##@@&&&@@##.              \n");  
    printf("              ,##@&::##&&##::&@##.          \n");
    printf("             #@&:##000000000##:&@#          \n");
    printf("           #@&:#00'         '00#:&@#        \n");
    printf("          #@&:#0'             '0#:&@#       \n");
    printf("         #@&:#0                 0#:&@#      \n");
    printf("        #@&:#0                   0#:&@#     \n");
    printf("        #@&:#0                   0#:&@#     \n");
    printf("        "" ' "                   " ' ""     \n");
    printf("      _oOoOoOo_                   .-.-.     \n");
    printf("     (oOoOoOoOo)                 (  :  )    \n");
    printf("      )'     '(                .-.`. .'.-.  \n");
    printf("     /         \\              (_  '.Y.'  _)\n");
    printf("    | #         |             (   .'|'.   ) \n");
    printf("    \\           /              '-'  |  '-' \n");
    printf("     `=========`                            \n");
    printf("                                            \n");
    printf("   ************************************     \n");
    printf("   * Bem vindo ao Jogo de Adivinhação *     \n");
    printf("   ************************************     \n");

    int chute;
    int acertou = 0;
    int tentativas = 1;
    double pontos = 1000;

    srand(time(0));
    int numerosecreto = rand() % 100;
    

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch(nivel) {
        case 1:
            numerodetentativas = 20;
            break;

        case 2:
            numerodetentativas = 15;
            break;

        default:
            numerodetentativas = 6;
            break;
    }

    for(int i = 1; i <= numerodetentativas; i++) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou){
            break;
        }

        else if(maior) {
            printf("Seu chute foi maior que o número secreto\n");
        }

        else {
            printf("Seu chute foi menor que o número secreto\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;

    }

    printf("Fim de jogo!\n");

    if(acertou) {
        printf("Você ganhou!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    } else {
        printf("Você perdeu! Tente de novo!\n");
    }
}
```

#include <stdio.h>  //inclue a biblioteca com os comandos de C como printf
#include <stdlib.h> //inclue a biblioteca que disponibiliza comandos com exit
#include <locale.h> //inclue opções de linguagens

//declarando constantes
//#define NUMERO_DE_TENTATIVAS 5


int main() // main é o ponto de partida
{
    setlocale(LC_ALL, "Portuguese"); //o que esta em ingles fica em portugues como os ascentos

    //cabeçalho do jogo

    printf("*******************************************\n"); // "\n" é utilizado para descer uma linha
    printf("Bem vindo ao mais novo jogo de adivinhação!\n");
    printf("*******************************************\n");

    //criando variaveis

    int numsecreto, chute; //declaração de variaveis, int = numero inteiro, char(string) = texto, float = numero com decimal,

    // substituido por define//int NTentativas = 5; //numero de tentativas

    numsecreto = 43; //dps por em aleatorio

    //for (int i =1;  i <= NUMERO_DE_TENTATIVAS; i++) { // for em loop infinito: for (;;) e for siginifica colocar um trecho de comando em repetição
            // as três partes do for() estão separadas por ponto e vírgula (;), a primeira é a variável que será usada de contador, a segunda é a condição de parada do loop, a terceira é o incremento

    //int ganhou = 0;
    int tentativa = 1;

    while(1) { //loops infinitos tem que acabar com break em algum momento

        printf("   Tentativa %d\n", tentativa);
        printf("Qual é o seu chute?  ");
        scanf("%d", &chute); //faz a leitura do teclado e guarda em uma variavel, toda variavel tem q ter um & antes

        if(chute < 0 ) {
            printf("você não pode chutar numeros negativos\n");
            //i--;

            continue; //segue para a proxima interação, volta para o i++
        }

        printf("Seu chute foi %d \n", chute);

        int acertou = chute == numsecreto;

        if (acertou) { //o if é sinonimo para "se", dentro das parenteses vai a condição, e o igual de comparação são dois simbolos de igual "=="
            printf("Você acertou! Como você é habilidoso, meus parabéns! \n");  // acertou
            printf("Você jogou bem, jogue mais vezes!\n");

            // parar de executar o for
            //break; // vai parar o loop e ir ao final do while/for pulando tudo
            break;
        }
        else { // caso contrario...

            int maior = chute > numsecreto; // essa variavel esta declarada apenas dentro dessas chaves não podendo ser usada no main como um todo, ou seja nas demais chaves externas

            if (maior) {
                printf("Seu chute foi maior que o numero secreto \n");
            }
            else { //if (chute < NS) pode ser escrito assim tbm
                printf("Seu chute foi menor que o numero secreto \n");
            }
            printf("============================= \n");
            printf("Você infelizmente esta errado \n"); // errou
            printf("tente novamente, e nunca desista! \n");
            printf("============================= \n");
        }

        tentativa = tentativa + 1; //ou tentativa++ "sinonimos"

    }

    // printf("O numero %d é o secreto, não espalhe por ai em!", NS); //%d é uma mascara que indica numero

    printf("____________________________\n");
    printf("Você acerou em %d tentativas\n", tentativa);
    printf("Fim de jogo, até a próxima\n");
    printf("''''''''''''''''''''''''''''\n");

    return 0; // para fechar o cmd após pressionar qualquer tecla

} // chaves "{}" são escopos


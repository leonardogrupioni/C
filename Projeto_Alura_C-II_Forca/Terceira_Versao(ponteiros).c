#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

//Header assinatura dizendo que as funções existem no programa (o ideal é por em um arquivo header .h)
/*void abertura();
void chuta();
void desenhaforca();
void escolhepalavra();
int ganhou();
int enforcou();
int jachutou(char letra);
*/ //conteudo no arquivo forca.h

//variaveis globais podem ser usadas e estão disponiveis para o codigo inteiro, porem outra solução é usar ponteiros
//funcionam para o codigo inteiro
char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;
    //usar com cautela, pois variaveis globais pode ocorrer de perder o controle sobre a variavel


void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");   
}

void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

void desenhaforca() {

    printf("Você já deu %d chutes\n", chutesdados);

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

//funcao escolher palavra aleatoria
void escolhepalavra() {
    FILE* f; //FILE tipo de variavel arquivo que recebe como ponteiro
    
    //ler o arquivo
    f = fopen("palavras.txt", "r"); //abrir arquivo externo, fopen(<nome do arquivo>,<o que fazer com o arquivo, 'r' reading, leitura>)
    //f variavel que recebe algo do arquivo
    
    //testar o banco de dados de palavras
    if(f == 0) {
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }

    //contar a quantidade de palavras do arquivo (ler a primeira linha e devolver o numero contido nela)
    int qtddepalavras; //quantidade de palavras contidas no arquivo
    fscanf(f, "%d", &qtddepalavras); //leitura de arquivos fscanf(<nome do arquivo>, <o que sera lido>< ponteiro da variavel que vai receber a leitura>)

    //selecionar uma linha aleatoria usando o resto da divisao entre um numero aleatorio e a quantidade de linhas com palavras
    //calcular numero randomico
    srand(time(0));
    int randomico = rand() % qtddepalavras;

    //loop de 0 a numero randomico
    for(int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f); //fechar o arquvio aberto no fopen, pois o arquivo é guardado para ser usado pelo programa enquanto for chamado

    //obs: o fscanf le o arquivo e para onde terminou de ler naquele momento, ou seja, no primeiro fscanf com %d ele le o numero e para o ponteiro na proxima linha
    //     depois segue para a proxima linha e a cada vez que é chamado le a linha que esta e joga na proxima
}

int ganhou(){
    for(int i = 0; i < strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}

int enforcou(){
    int erros = 0;
    for(int i = 0; i < chutesdados; i++){
        int existe = 0;
        for(int j = 0; j < strlen(palavrasecreta); j++){
            if(chutes[i] == palavrasecreta[j]){
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros >= 5;
}

//funcao com retorno: alguem(em algum lugar) chama a funcao e pede que algo seja retornado.
int jachutou(char letra) {
    int achou = 0;
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

int main() {

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

    } while (!ganhou() && !enforcou());

}

//aprendizado: refatorar é alterar o nome de variaveis ou funcoes no caso de nao combinarem mais com o codigo
//funcoes tem que aparecer antes de serem usadas, ou pode se usar um header
//header é a assinatura das funcoes que ja existem
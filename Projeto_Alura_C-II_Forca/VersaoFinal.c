#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

#define TAMANHO_PALAVRA 20;

//variaveis globais
char palavrasecreta[20 ];
char chutes[26];
int chutesdados = 0;


int chuteserrados(){
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
    return erros;
}

int enforcou(){
   
    return chuteserrados() >= 5;
}

int ganhou(){
    for(int i = 0; i < strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}

void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");   
}

void chuta() {
    char chute;
    int alerta; 
    do {
        printf("Qual letra? ");
        scanf(" %c", &chute);
        for(int i = 0; i < 26; i++){
            if (chutes[i] == chute) {
                alerta = 1;
                printf("\nA letra %c ja foi chutada, chute novamente\n", chute);
                break;
            } else alerta = 0;
        }
    } while(alerta == 1);
    chutes[chutesdados] = chute;
    chutesdados++;
}

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

void desenhaforca() {

    //if iternarios: podem ser colocados ao longo do printf, basta colocar entre parenteses
    //               (<condicao> ? <opcoes dentro do if1 : opcao dentro do if2>)
    int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n"); 
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n");
    
    printf("Letra ja chutadas: ");
    for(int i = 0; i < 26; i++){
        if (chutes[i] == ' ') {

        } else printf("%c ", chutes[i]);
    }
    printf("\n");

    printf("Voce ja deu %d chutes\n", chutesdados);

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");
}

void adicionapalavra(){

    char quer; //selecionar opcao

    printf("Voce deseja adicionar uma nova palavra no jogo? (S/N) ");
    scanf(" %c", &quer);

    if(quer == 'S'){
        char novapalavra[20]; //criando espaco para a nova palavra
        printf("Qual a nova palavra? ");
        scanf("%s", novapalavra); //coletando nova palavra

        FILE* f;

        f = fopen("palavras.txt", "r+"); //r+ abre como leitura e escrita
        
        if(f == 0) {
            printf("Banco de dados de palavras nao disponivel\n\n");
            exit(1);
        }

        int qtd;//quantidade de linhas definidas no arquivo txt
        fscanf(f, "%d", &qtd);//fscanf coleta algo que esta no arquivo, <arquivo> <tipo de dado a ser lido> <variavel a ser incrementada>
        qtd++;//adiciona ao valor da qtd
        
        fseek(f, 0, SEEK_SET);//posiciona a cabeca de leitura na posicao do arquivo, aponta para o byte(linha que voce deseja) SEEK_SET linha inicial 0.
        fprintf(f, "%d", qtd);//escreve por cima do arquivo

        fseek(f, 0, SEEK_END);//aponta a cabeca de leitura para a ultima coisa do arquivo, para seu ultimo local
        fprintf(f, "\n%s", novapalavra);//fprintf = escreve no arquuivo <arquivo> <o que sera escrito> <string adicionada ao arquivo>
        
        fclose(f); //fechar o arquivo aberto no fopen
    }
}



//funcao escolher palavra aleatoria
void escolhepalavra() {
    FILE* f; //FILE tipo de variavel arquivo que recebe como ponteiro
    
    //ler o arquivo
    f = fopen("palavras.txt", "r"); //abrir arquivo externo, fopen(<nome do arquivo>,<o que fazer com o arquivo, 'r' reading, leitura>)
    //f variavel que recebe algo do arquivo
    
    //testar o banco de dados de palavras
    if(f == 0) {
        printf("Banco de dados de palavras nao disponivel\n\n");
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

int main() {

    abertura();

    escolhepalavra();

    do {

        desenhaforca();
        chuta();

    } while (!ganhou() && !enforcou());

    if(ganhou()) {
        printf("\n  Parabens! Voce Ganhou\n");
        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    } else {
        printf("\nVoce Enforcou, ou seja, PERDEU!\n");
        printf("A palavra era **%s**\n", palavrasecreta);
        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

    adicionapalavra();

}

#include <stdio.h>
#include <string.h>

//declaração de variaveis globais
char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

//o parenteses apos o nome indica uma funcao
void abertura(){ //₢riando a funcao de abertura que ira printar a capa do jogo
    printf("*******************\n");
    printf("*  Jogo da Forca  *\n");
    printf("*******************\n");
}

    //evite usar o mesmo nome na passagem de parametros e no programa, pois isso pode confundir, e deve entender que sao diferentes independente do nome
    //ou entender que so existem no contexto que forem declaradas
//capturar chute
void chuta(){ //entre parenteses esta a passagem de parametros, ou seja das variaveis entre as funcoes
                    // um exemplo seria uma passagem de parametros das variaveis char chutes[26], int tentativas, no cas de estarem no main e nao como globais
    //coletando chute
    char chute;
    printf("Qual a letra? ")
    scanf(" %c", &chute); //" %c" usa o espaço pois ignora o enter ele apenas finaliza
    
    //salvando chutes
    chutes[tentativas] = chute;
}

//teste de chute repetido
int jachutou(char letra){
    int achou = 0;
    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca() {

    printf("Você já deu %d chutes\n", tentativas);

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

//definindo a palavraSecreta
void escolhepalavra() {
    sprintf(palavrasecreta, "MELANCIA");
}

int main(){
    
    //definindo no tipo booleano o venceu e perdeu
    int acertou = 0;
    int enforcou = 0;

    abertura();
    escolhepalavra();

    //loop do jogo
    do {
        //acessando funcoes
        desenhaforca();
        chuta();

        tentativas++;

    } while (!acertou && !enforcou); //'!' é o sinal de negação
}
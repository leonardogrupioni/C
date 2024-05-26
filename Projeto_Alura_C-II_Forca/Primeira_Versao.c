#include <stdio.h>
#include <string.h>

void abertura(){
    printf("*******************\n");
    printf("*  Jogo da Forca  *\n");
    printf("*******************\n");
}


int main(){
    
    //definindo a palavraSecreta
    char  palavraSecreta[20];
    sprintf(palavraSecreta, "MELANCIA");

    //definindo no tipo booleano o venceu e perdeu
    int acertou = 0;
    int enforcou = 0;
    
    //condicionais
    char chutes[26];
    int tentativas = 0;

    //loop do jogo
    do {
        //loop testando se o chute corresponde a palavra
        for(int i = 0; i < strlen(palavraSecreta); i++) {

            int achou = 0;

            for(int j = 0; j < tentativas; j++) {
                if(chutes[j] == palavraSecreta[i]) {
                    achou = 1;
                    break;
                }
            }

            if(achou) {
                printf("%c ", palavraSecreta[i]);
            } else {
                printf("_ ");
            }

        }
        printf("\n");

        //coletando chute
        char chute;
        scanf(" %c", &chute); //" %c" usa o espaço pois ignora o enter ele apenas finaliza
        
        //salvando chutes
        chutes[tentativas] = chute;
        tentativas++;

    } while (!acertou && !enforcou); //'!' é o sinal de negação
}
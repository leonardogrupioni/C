//jogo foge foge - semelhante ao pac-man
#include <stdio.h>
#include <stdlib.h>

// \ 

//mapa sera usado varias vezes, logo variavel global para facilitar e nao ter que passar varios ponteiros
/*char mapa[5][10+1]; //declarando a matriz mapa
             //10 numero de caracteres, +1 terminador /0
*/
//declarando mapa para alocar dinamicamente:
char** mapa; //declarando um poteiro de ponteiro vulgo matriz

int linhas;
int colunas;


int main(){
    
    
    //Abrindo o arquivo que contem o mapa 
    FILE* f;
    f = fopen("mapa.txt", "r");
    
    if(f == 0) { //testando se o arquivo foi aberto corretamente
        printf("Erro na leitura do mapa\n");
        exit(1);
    }

    //ler a primeira linha
    fscanf(f, "%d %d", &linhas, &colunas);

    //declarando o mapa com alocacao dinamica
    /*
        pedindo um espaço de memoria para um inteiro
        int* v = malloc(sizeof(int)); sizeof(tipo) é uma funcao que passa quantos bytes um tipo precisa
        *v = 10;
        printf("inteiro alocado %d", *v);
        free(v); // toda a memoria que voce alocar dinamicamente deve ser liberada antes de fechar o programa
        guardando uma array
        int v[10] = malloc(sizeof(int) * 10); deve multiplcar por 10 ja que é uma array com 10 inteiros, o mesmo vale para os outros tipos ou string
        
        matriz é um ponteiro de ponteiro:
        ou seja deve utilizar duas estrelas na declaracao ** como:
        int** v = malloc(sizeof(int) * 5);
        for(int i = 0; i < 5; i++){
            v[i] = malloc(sizeof(int) * 10);
        }  // para uma matriz de 5x10, alocando os 50 ponteiros em memoria dinamica, sendo primeiro as 5 linhas e depois 10 colunas por linha

        DETALHE: O FREE TEM QUE LIBERAR TODAS AS POSICOES CRIADAS
        for(int i = 0; i < 5; i++){
            free(v[i]); dando free em todas as linhas incluindo todas suas colunas ja que passou apenas a posicao de linhas
        }
        free(v); para o ponteiro como um todo, lembrando que é um ponteiro de ponteiro entao deve limpar os ponteiros de ponteiro'1' e dps o ponteiro'1'
    */

    //alocacao dinamica do mapa:
    mapa = malloc(sizeof(char*) * linhas); //as linhas são ponteiros de char entao (char*) e multiplica pela variavel linhas
    for(int i = 0; i < linhas; i++){
        mapa[i] = malloc(sizeof(char) * (colunas+1)); //colunas+1 por conta do terminador
    }

    //leitura do mapa por linha (cada linha uma string "array de caracteres")
    for (int i = 0; i < linhas; i++){
        fscanf(f, "%s", mapa[i]);
    }

    //imprimindo mapa lido
    for (int i = 0; i < linhas; i++){
        printf("%s\n", mapa[i]);
    }
    
    //limpando o espaco de memoria
    for(int i = 0; i < linhas; i++){
        free(mapa[i]);
    }
    free(mapa);

    fclose(f);
    
}

//matriz dinamica:
//uma opcao nao dinamica é criar uma matriz com um tamanho limite para colocar o mapa, por exemplo uma de 200x200+1
//  o problema dessa matriz é que pode ser separado um espaço na memoria inutil



//ponteiros de ponteiros:
//int* indica um ponteiro, enquanto i** indica o ponteiro de um ponteiro, ou seja, 
//enquanto um vetor é um ponteiro para uma lista de posições, uma matriz é um ponteiro que aponta para uma lista de ponteiros, 
//e esses ponteiros da lista, apontam para posiçoes de memoria
//array = ponteiro -> lista
//matriz = ponteiro -> lista de ponteiros -> lista (a cada ponteiro da lista de ponteiros)  
#include <stdio.h>
#include <stdlib.h>

//pre-declarando as funcoes:
int liberaMapa();
int alocaMapa();
int leMapa();

// \ 
//declarando mapa para alocar dinamicamente:
char** mapa; //declarando um poteiro de ponteiro vulgo matriz

int linhas;
int colunas;

int liberaMapa(){
    //limpando o espaco de memoria
    for(int i = 0; i < linhas; i++){
        free(mapa[i]);
    }
    free(mapa);
}

int alocaMapa(){
    //alocacao dinamica do mapa:
    mapa = malloc(sizeof(char*) * linhas); //as linhas são ponteiros de char entao (char*) e multiplica pela variavel linhas
    
    for(int i = 0; i < linhas; i++){
        mapa[i] = malloc(sizeof(char) * (colunas+1)); //colunas+1 por conta do terminador
    }
}

int leMapa(){
    
    //Abrindo o arquivo que contem o mapa 
    FILE* f;
    f = fopen("mapa.txt", "r");
    
    if(f == 0) { //testando se o arquivo foi aberto corretamente
        printf("Erro na leitura do mapa\n");
        exit(1);
    }

    //ler a primeira linha
    fscanf(f, "%d %d", &linhas, &colunas);

    alocaMapa();

    //leitura do mapa por linha (cada linha uma string "array de caracteres")
    for (int i = 0; i < linhas; i++){
        fscanf(f, "%s", mapa[i]);
    }
    
    fclose(f);
}

int main(){
    
    leMapa();

    //imprimindo mapa lido
    for (int i = 0; i < linhas; i++){
        printf("%s\n", mapa[i]);
    }
    
    liberaMapa();

}


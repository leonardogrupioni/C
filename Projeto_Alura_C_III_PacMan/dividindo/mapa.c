#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

//posicionando o pacman
void andanomapa(MAPA* m, int xorigem, int yorigem, 
    int xdestino, int ydestino) {

    char personagem = m->matriz[xorigem][yorigem];
    m->matriz[xdestino][ydestino] = personagem;
    m->matriz[xorigem][yorigem] = VAZIO;

}

int ehValida(MAPA* m, int x, int y) {
    if(x >= m->linhas) //retorna 0 pq nao eh valida
        return 0;
    if(y >= m->colunas) 
        return 0; //retorna 0 pq nao eh valida

    return 1; //retorna 1 pq eh valida
} 

int ehVazia(MAPA* m, int x, int y) {
    return m->matriz[x][y] == VAZIO;
} //diz se o espaço esta vazio ou cheio

int liberaMapa(MAPA* m){
    //limpando o espaco de memoria
    for(int i = 0; i < (*m).linhas; i++){ //tem que troca de m para (*m) pois agora se trata de um ponteiro, então colocamos o asterisco para acessar o conteudo
        free(m->matriz[i]);               //porem (*m). em c é a mesma coisa que m->linhas, sao equivalentes
    }
    free(m->matriz);
}

int alocaMapa(MAPA* m){
    //alocacao dinamica do mapa:
    m->matriz = malloc(sizeof(char*) * m->linhas); //as linhas são ponteiros de char entao (char*) e multiplica pela variavel linhas
    
    for(int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas+1)); //colunas+1 por conta do terminador
    }
}

int leMapa(MAPA* m){
    
    //Abrindo o arquivo que contem o mapa 
    FILE* f;
    f = fopen("mapa.txt", "r");
    
    if(f == 0) { //testando se o arquivo foi aberto corretamente
        printf("Erro na leitura do mapa\n");
        exit(1);
    }

    //ler a primeira linha
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    alocaMapa(m);

    //leitura do mapa por linha (cada linha uma string "array de caracteres")
    for (int i = 0; i < m->linhas; i++){
        fscanf(f, "%s", m->matriz[i]);
    }
    
    fclose(f);
}

void imprimeMapa(MAPA* m){
    //imprimindo mapa lido
    for (int i = 0; i < m->linhas; i++){
        printf("%s\n", m->matriz[i]);
    }
}

void encontraMapa(MAPA* m, POSICAO* p, char c){
    
    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == c){
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}
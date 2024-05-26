#include <stdio.h>
#include <stdlib.h>

//pre-declarando as funcoes:
int liberaMapa();
int alocaMapa();
int leMapa();
void imprimeMapa();
void move(char direcao);
int acabou();

// \ 
//declarando mapa para alocar dinamicamente:
/*char** mapa; //declarando um poteiro de ponteiro vulgo matriz
int linhas;
int colunas;
*/
//transformando em struct, ja que uma variavel depende da outra, agrupando as variaveis com struct:

struct mapa{
    char** matriz; 
    int linhas;
    int colunas;
};

typedef struct mapa MAPA; //typedef definir um tipo e criar um apelido para esse tipo: <typedef> <struct name> <apelido>;

//struct typedef

MAPA m; //declarando o mapa como struct e nomeando como m

int liberaMapa(){
    //limpando o espaco de memoria
    for(int i = 0; i < m.linhas; i++){
        free(m.matriz[i]);
    }
    free(m.matriz);
}

int alocaMapa(){
    //alocacao dinamica do mapa:
    m.matriz = malloc(sizeof(char*) * m.linhas); //as linhas são ponteiros de char entao (char*) e multiplica pela variavel linhas
    
    for(int i = 0; i < m.linhas; i++){
        m.matriz[i] = malloc(sizeof(char) * (m.colunas+1)); //colunas+1 por conta do terminador
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
    fscanf(f, "%d %d", &(m.linhas), &(m.colunas));

    alocaMapa();

    //leitura do mapa por linha (cada linha uma string "array de caracteres")
    for (int i = 0; i < m.linhas; i++){
        fscanf(f, "%s", m.matriz[i]);
    }
    
    fclose(f);
}

void imprimeMapa(){
    //imprimindo mapa lido
    for (int i = 0; i < m.linhas; i++){
        printf("%s\n", m.matriz[i]);
    }
}

void move(char direcao){
    int x;
    int y;

    //encontra a posicao do personagem
    for(int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            if(m.matriz[i][j] == '@'){
                x = i;
                y = j;
                break;
            }
        }
    }

    //posicionando
    switch(direcao) {
        case 'a':
            m.matriz[x][y-1] = '@';
            break;
        case 'w':
            m.matriz[x-1][y] = '@';
            break;
        case 's':
            m.matriz[x+1][y] = '@';
            break;
        case 'd':
            m.matriz[x][y+1] = '@';
            break;
    }

    //apagando a posicao que ele estavas
    m.matriz[x][y] = '.';
}


int acabou(){
    return 0;
}

int main(){
    
    leMapa();

    do {

        imprimeMapa();

        char comando; //comando dado pelo usuario
        scanf(" %c", &comando);
        move(comando);
    
    } while(!acabou());

    
    liberaMapa();

}

//Variáveis declaradas como globais são globais para todo o programa. Mas, para que um arquivo enxergue uma variável global definida em outro arquivo, precisamos fazer uso da palavra extern.

/*
Imagine, por exemplo, uma variável int n; for definida no arquivo a.c. 
Para usarmos a mesma variável no arquivo b.c, precisaríamos redeclara-la 
com extern int n;. Agora sim, a variável n, global, é visível por ambos 
arquivos. Repare que só um arquivo a realmente declara, e os outros deixam 
claro que ela é "externa".*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "model.h"
#include "view.h"
#include "controller.h"

//recebendo a opcao selecionada do Menu
int receberOpcao(){

    int opcao;
    scanf(" %d", &opcao);

    return opcao;
}

void criarMundo(MUNDO* m){

    inicializarMundo(m);
    imprimirApresentarMundo();
    imprimirMundo(m);
}

//recebendo o tamanho da matriz mundo do usuario
void receberTamanhoMundo(MUNDO* m){

    imprimirEscolherTamanhoMundo();

    imprimirReceberLinha();
    scanf(" %d", &m->linhas);

    imprimirReceberColuna();
    scanf(" %d", &m->colunas);
}

//preenchendo a matriz com zeros
void inicializarMundo(MUNDO* m){

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            m->matriz[i][j] = VAZIO;
        }
    }
}

void imprimirMundo(MUNDO* m){

    //numerando as colunas
    printf(" ");
    for(int k = 0; k < m->colunas; k++){
            printf("  %d ", k);
           
    }printf("\n");

    for(int i = 0; i < m->linhas; i++){
        printf("%d", i); //numerando as linhas
        for(int j = 0; j < m->colunas; j++){

            if (m->matriz[i][j] == VAZIO)
                printf("   ");
            else 
                printf(" * ");

        }printf("\n");
    }
}

//recebendo a qnt de seres vivos e executando a funcao definirPosicaoSeresVivos()
void definirSeresVivos(MUNDO* m){

    int qtdSerVivo;

    imprimirEscolherQtdSeresVivos();
    scanf("%d", &qtdSerVivo);

    definirPosicaoSeresVivos(m, qtdSerVivo);

}

//verificando se a posicao desejada para inserir o ser vivo existe 
int posicaoValida(MUNDO* m, int x, int y){
    return (x <= m->linhas && y <= m->colunas);
}

//Colocando os seres vivos nas posicoes escolhidas
void definirPosicaoSeresVivos(MUNDO* m, int quantidade){

    if(quantidade == 0){
        imprimirOpcaoInvalida();
        definirSeresVivos(m);
        
    }

    imprimirEscolherPosicaoSeresVivos();

    int i = 1;
    do{
        int linha;
        int coluna;

        printf("\nSer Vivo %d:\n", i);

        imprimirReceberLinha();
        scanf("%d", &linha);

        imprimirReceberColuna();
        scanf("%d", &coluna);
    
        if(posicaoValida(m, linha, coluna)){ 
            m->matriz[linha][coluna] = SER_VIVO;
            i++;
        }else
            imprimirPosicaoInvalida();

    }while(i <= quantidade);
}

int receberQtdGeracoes(){
    
    int qtdGeracoes;
    imprimirEscolherQtdGeracoes();
    scanf(" %d",&qtdGeracoes);

    return qtdGeracoes;
}

//simula e imprime a proxima geracao de seres vivos 
void simularGeracao(MUNDO* m, MUNDO* auxiliar, int contador){

    contador++;
    printf("\n\t\tGeracao %d :\n", contador);
    
    inicializarMundoAuxiliar(auxiliar, m);
    percorrerMundo(m, auxiliar);
    atualizarMundo(m, auxiliar);

}

//preenchendo o mundo auxiliar com os espacos vazios assim como o mundo m 
void inicializarMundoAuxiliar(MUNDO* auxiliar, MUNDO* m){

    auxiliar->linhas = m->linhas;
    auxiliar->colunas = m->colunas;
    
    inicializarMundo(auxiliar);

}

//lendo o mundo m e atualizando o mundo auxiliar com a proxima geracao 
void percorrerMundo(MUNDO* m, MUNDO* auxiliar){

    int vizinhos = 0;
    
    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            vizinhos = contarVizinhos(m, i, j);
            gerarProximaGeracao(m, auxiliar, vizinhos, i, j);
        }
    }
}

//Contando a quantidade de seres vivos vizinhos (verificando todas as 8 celulas vizinhas do ser vivo )
int contarVizinhos(MUNDO* m, int x, int y){
    
    int contVizinhos = 0;

    if(posicaoValida(m, x-1, y-1)){
        if(m->matriz[x-1][y-1] == SER_VIVO)
            contVizinhos++;
    }
     if(posicaoValida(m, x-1, y)){
        if(m->matriz[x-1][y] == SER_VIVO)
            contVizinhos++;
    }
     if(posicaoValida(m, x-1, y+1)){
        if(m->matriz[x-1][y+1] == SER_VIVO)
            contVizinhos++;
    }
     if(posicaoValida(m, x, y-1)){
        if(m->matriz[x][y-1] == SER_VIVO)
            contVizinhos++;
    }
     if(posicaoValida(m, x, y+1)){
        if(m->matriz[x][y+1] == SER_VIVO)
            contVizinhos++;
    }
    if(posicaoValida(m, x+1, y-1)){
        if(m->matriz[x+1][y-1] == SER_VIVO)
            contVizinhos++;
    }
    if(posicaoValida(m, x+1, y)){
        if(m->matriz[x+1][y] == SER_VIVO)
            contVizinhos++;
    }
    if(posicaoValida(m, x+1, y+1)){
        if(m->matriz[x+1][y+1] == SER_VIVO)
            contVizinhos++;
    }

    return contVizinhos;
}

//atualizando o mundo auxiliar com a proxima geracao de seres vivos 
void gerarProximaGeracao(MUNDO* m, MUNDO* auxiliar, int vizinhos, int x, int y){
    
    //Reproducao: um ser vivo nasce numa celula vazia se essa celular vazia tiver exatamente 3 vizinhos.
    if(m->matriz[x][y] == VAZIO){
        if(vizinhos == 3)
            auxiliar->matriz[x][y] = SER_VIVO;
    }

    //Sobrevivencia: Um ser vivo que tenha 2 ou 3 vizinhos sobrevive para a geracao seguinte.
    if(m->matriz[x][y] == SER_VIVO){
        if(vizinhos == 2 || vizinhos == 3 )
            auxiliar->matriz[x][y] = SER_VIVO;
    }

    //Morte por falta de comida: Um ser vivo com 4 ou mais vizinhos morre de fome.
    if(m->matriz[x][y] == SER_VIVO){
        if(vizinhos >= 4)
            auxiliar->matriz[x][y] = VAZIO;
    }
    
    //Morte por solidao: Um ser vivo com 0 ou 1 vizinho morre de solidao.
    if(m->matriz[x][y] == SER_VIVO){
        if(vizinhos == 0 || vizinhos == 1)
            auxiliar->matriz[x][y] = VAZIO;
    }
}

//O mundo m recebe a geracao atualizada dos seres vivos (que esta no mundo auxiliar)
void atualizarMundo(MUNDO* m, MUNDO* auxiliar){
    
    for(int i = 0; i < m->linhas; i ++){
        for(int j = 0; j < m->colunas; j++){
                m->matriz[i][j] = auxiliar->matriz[i][j];
        }
    }
}

int receberVelocidadeDeSimulacao(){
    
    int velocidade;
    imprimirEscolherVelocidade();
    scanf("%d", &velocidade);

    return velocidade;
}

//Causando um delay durante a execucao do codigo 
void aplicarVelocidadeDeSimulacao(float velocidadeSimulacao){

    //convertendo os segundos de delay em milisegundos
    int milisegundos = 1000 * velocidadeSimulacao;

    //armazenando o tempo de inicio do delay
    clock_t inicio = clock();

    while (clock() < inicio + milisegundos);
}

void validarPosicaoPadraoSeresVivos(MUNDO* m, MUNDO* auxiliar){

    int escolhaPadrao;
    scanf(" %d", &escolhaPadrao);
        
    int x;
    int y;

    imprimirReceberLinha();
    scanf("%d", &x);

    imprimirReceberColuna();
    scanf("%d", &y); 

    inicializarMundoAuxiliar(auxiliar, m);

    switch(escolhaPadrao){

        case 1: 

            if(posicaoValida(m, x, y) && posicaoValida(m, x+1, y) && posicaoValida(m, x+2, y)){
                
                auxiliar->matriz[x][y] = SER_VIVO;
                auxiliar->matriz[x+1][y] = SER_VIVO;
                auxiliar->matriz[x+2][y] = SER_VIVO;
            }

            break;

        case 2:

             if(posicaoValida(m, x, y) && posicaoValida(m, x, y+1) && posicaoValida(m, x, y+2)){
                
                auxiliar->matriz[x][y] = SER_VIVO;
                auxiliar->matriz[x][y+1] = SER_VIVO;
                auxiliar->matriz[x][y+2] = SER_VIVO;
            }

            break;

        case 3:

            if(posicaoValida(m, x, y) && posicaoValida(m, x, y+1) && posicaoValida(m, x+1, y) && posicaoValida(m, x+1, y+1)){
                
                auxiliar->matriz[x][y] = SER_VIVO;
                auxiliar->matriz[x][y+1] = SER_VIVO;
                auxiliar->matriz[x+1][y] = SER_VIVO;
                auxiliar->matriz[x+1][y+1] = SER_VIVO;
            }

            break;

        case 4:
            if(posicaoValida(m, x, y) && posicaoValida(m, x+1, y-1) && posicaoValida(m, x+2, y-1)){
                
                auxiliar->matriz[x][y] = SER_VIVO;
                auxiliar->matriz[x+1][y-1] = SER_VIVO;
                auxiliar->matriz[x+2][y-1] = SER_VIVO;

            }

            break;

        case 5:
            if(posicaoValida(m, x, y) && posicaoValida(m, x+1, y+1) && posicaoValida(m, x+2, y+1) && posicaoValida(m, x+2, y) && posicaoValida(m, x+2, y-1)){
                
                auxiliar->matriz[x][y] = SER_VIVO;
                auxiliar->matriz[x+1][y+1] = SER_VIVO;
                auxiliar->matriz[x+2][y+1] = SER_VIVO;
                auxiliar->matriz[x+2][y] = SER_VIVO;
                auxiliar->matriz[x+2][y-1] = SER_VIVO;
            }

            break;

        case 6:
             if(posicaoValida(m, x, y) && posicaoValida(m, x+1, y-1) && posicaoValida(m, x+2, y-2)){
                
                auxiliar->matriz[x][y] = SER_VIVO;
                auxiliar->matriz[x+1][y-1] = SER_VIVO;
                auxiliar->matriz[x+2][y-2] = SER_VIVO;
            }

            break;

        default:

            imprimirOpcaoInvalida();
            break;
        
    }

   atualizarMundo(m, auxiliar);

}

void salvarMundo(MUNDO* m){

    FILE* f;

    f = fopen("mundo.txt", "w");

    if( f == NULL){
        imprimirMensagemErro();
        exit(1);
    }


    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            
            fprintf(f, "%c", m->matriz[i][j]); 
        }
        fprintf(f, "\n");  
    }

    fclose(f);

    imprimirMensagemMundoSalvo();

}

void carregarMundoSalvo(MUNDO* m){

    FILE* g;
    
    g = fopen("mundo.txt", "r+");
    
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            printf("\nnumero: %c\n", m->matriz[i][j]);
            fscanf(g, " %c", m->matriz[i][j]); // BUG * BUG * BUG * BUG * BUG * BUG * BUG 
        }
    }

    fclose(g);

    imprimirMundo(m);

    imprimirMensagemMundoCarregado();

}

// Bug: Problemas com a funcao carregarMundoSalvo(MUNDO* m) -> nao consigo passar o mundo do arquivo txt para a matriz m 

#define MAX 60
#define MIN 10

#define SER_VIVO '1'
#define VAZIO '0'

#ifndef _MODEL_H_
#define _MODEL_H_

struct mapa{
    int matriz[MAX][MAX];
    int linhas;
    int colunas;
};
typedef struct mapa MUNDO;

#endif

int receberOpcao();
void receberTamanhoMundo(MUNDO* m);
void criarMundo(MUNDO* m);
void inicializarMundo(MUNDO* m);
void imprimirMundo(MUNDO* m);
void definirSeresVivos(MUNDO* m);
int posicaoValida(MUNDO* m, int x, int y);
void definirPosicaoSeresVivos(MUNDO* m, int qtdSerVivo);
void percorrerMundo(MUNDO* m, MUNDO* auxiliar);
int contarVizinhos(MUNDO* m, int x, int y);
int receberQtdGeracoes();
void inicializarMundoAuxiliar(MUNDO* destino, MUNDO* m);
void gerarProximaGeracao(MUNDO* m, MUNDO* auxiliar, int vizinhos, int x, int y);
void simularGeracao(MUNDO* m, MUNDO* auxiliar, int geracoes);
void atualizarMundo(MUNDO* m, MUNDO* auxiliar);
int receberVelocidadeDeSimulacao();
void aplicarVelocidadeDeSimulacao(float velocidadeSimulacao);
void validarPosicaoPadraoSeresVivos(MUNDO* m, MUNDO* auxiliar);
void salvarMundo(MUNDO* m);
void carregarMundoSalvo(MUNDO* m);

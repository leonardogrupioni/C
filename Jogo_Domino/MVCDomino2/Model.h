//struct do tipo peca
typedef struct _peca{
    int l1; //lado 1
    int l2; //lado 2
    //int id; //id de 0 a 27;
    int posicao; //posicao da peca
    char stats; //onde esta a peca, P = pilha, 1 = jogador1, 2 = jogador2, M = mesa.
    //contadores
    int contJ1; //contador de pecas com jogador 1
    int contJ2; //contador de pecas com jogador 2
    int contPilha; //contador de pecas na pilha
    int contMesa; //contador de pecas na mesa
}PECA;

#define J1 '1' //jogador 1
#define J2 '2' //jogador 2
#define PILHA 'p'
#define MESA 'm'

//constantes
#define TOTALPECAS 28

//pre-declara funcoes
void inicializarPecas(PECA pecas[]);
void embaralharPecas(PECA pecas[]);
void desembaralharPeca(PECA pecas[]);
void distribuirPecas(PECA pecas[]);
int conferirPecaInicial(PECA pecas[]);
//void verificarCompraDePecas(PECA pecas[], int turno);
int fimDeJogo(PECA pecas[]);
void conferirSomaPecas(PECA pecas[], int soma[]);
//int verificarTurno(PECA pecas[], int turno);
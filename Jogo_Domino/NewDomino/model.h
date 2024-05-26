//novo tipo de dado: estrutura peca para jogo de domino
typedef struct _peca{
    //lados
    int lado1; 
    int lado2;
    //posicao da peca no domino
    int id;
    //status atual da peca entre: Jogador1, Jogador2, Mesa ou Pilha
    char status;
} PECA;

//novo tipo de dado: contadores para peças que estao com Jogador1, Jogador2, Mesa ou Pilha
typedef struct _contadores{
    int pilha;
    int mesa;
    int jogador1;
    int jogador2;
} CONTADOR;

//novo tipo de dado: Mesa, tipo de dado para armazenar as peças que estao na mesa

typedef struct p_mesa{
    int lado1;
    int lado2;
    int jogador;
    int soma; 
} PECA_MESA;

//definindo constantes para utilizar no status do tipo PECA
#define JOGADOR_1 '1'
#define JOGADOR_2 '2'
#define PILHA 'p'
#define MESA 'm'

//definindo constantes do jogo
#define TOTAL_PECAS 28

//pre-declaracao de funcoes model:


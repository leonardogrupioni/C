#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

//conteudo mapa.h
struct mapa{
    char** matriz; 
    int linhas;
    int colunas;
};

struct posicao{
    int x;
    int y;
};

typedef struct posicao POSICAO;

typedef struct mapa MAPA; //typedef definir um tipo e criar um apelido para esse tipo: <typedef> <struct name> <apelido>;

int liberaMapa(MAPA* m);
int alocaMapa(MAPA* m);
int leMapa(MAPA* m);
void imprimeMapa(MAPA* m);
void encontraMapa(MAPA* m, POSICAO* p, char c);
int ehValida(MAPA* m, int x, int y);
int ehVazia(MAPA* m, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
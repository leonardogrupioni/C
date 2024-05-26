//testes e conceito basico de ponteiro

#include <stdio.h>

//passagem de parametros com mesmo nome, porem endereços diferentes: o que ocorre?
/*
void joga(int tentativas) {
    printf("joga %d\n", tentativas);
    tentativas++;
    printf("joga %d\n", tentativas);
}

int main() {

    int tentativas = 0;
    printf("main %d\n", tentativas);

    tentativas++;
    printf("main %d\n", tentativas);

    tentativas++;
    printf("main %d\n", tentativas);

    joga(tentativas);

    printf("main %d\n", tentativas);

}

//no console
    main 0
    main 1
    main 2
    joga 2
    joga 3
    main 2
*/
//isso ocorre pois esta havendo uma passagem por copia 
//"Ou seja, sempre que passamos uma variável para uma 
//função, a máquina copia a variável e cria uma nova, 
//para que a original fique intacta."


//pensando do ponto de vista de ponteiros:
/*
int c = 10;
int* ponteiro;

// ponteiro apontando para o mesmo endereco de c
ponteiro = &c;

// imprime o endereco da variavel c
printf("%d %d\n", ponteiro, &c);

// imprime o conteúdo da variavel c
printf("%d %d\n", *ponteiro, c);
*/

//aplicando:

void calcula(int* c2){
    printf("calcula %d %d\n", (*c2), c2);
    (*c2)++;
    printf("calcula %d %d\n", (*c2), c2);
}

int main(){
    int c = 10;

    printf("main %d %d\n", c, &c);
    calcula(&c);
    printf("main %d %d\n", c, &c);
}

/*informações:

''' int c = 10; ''' declara a variavel inteira "c", e atribui o valor 10
esta variavel "c" esta alocada em um endereço de memoria

''' printf("main %d %d\n", c, &c); ''' imprime o conteudo da variavel c e seu endereço
''' calcula(&c); ''' acessa a funcao void calcula e envia como parametros o endereço da variavel c
"&c" - passagem do endereço de memoria

''' void calcula(int* c2) ''' a funcao calcula recebe o endereço de memoria quando utiliza o * junto a ddeclaração da variavel
int* - nao vem um inteiro vem o endereço de memoria de um inteiro

''' (*c2) ''' usa o "asterisco c2" para acessar o conteudo da memoria endereçada
''' (*c2)++; ''' soma 1 ao valor do dado contido no endereco de memoria passado na passagem de parametros

obs: o nome nao faz diferença o que importa é que a variavel c2 recebe um endereço de 
memoria ou seja aponta para um endereço, nesse caso de c, a variavel 
c2 aponta para o endereço de c, ou seja, é um ponteiro
...fazemos isso para alterar o valor da variavel em diferentes locais do programa 



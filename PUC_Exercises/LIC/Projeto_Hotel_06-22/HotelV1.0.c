//PROJETO DE LIC - CONTROLE DE RESERVAS E OCUPAÇÃO DO HOTEL
//COM-MA1A - GRUPO 04 - INTEGRANTES: LEONARDO GRUPIONI, VICTORIA FERRARESE, KEISY ALVES
//DATA DE INICIO 07/06/2022
//PRIMEIRA VERSÃO Definição da estrutura de dados para representar a alocação dos 
                //apartamentos e implementação dos requisitos REQ01, REQ02 e REQ03
//prog1.c

//bibliotecas:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

//declaração de constantes:
#define ANDARES 20; //andares do hotel
#define APTOS 14; //aptos por andar

// \n ||

//função reservar
void reservar(char mat[20][14]){
    int a, ap;

    do {
        printf("Digite o apartamento no qual deseja fazer a resrerva:\n");
        printf("Andar: ");
        scanf("%d", &a);
        printf("Apartamento: ");
        scanf("%d", &ap);
    } while(a > 20 || a < 1 || ap > 14 || ap < 1);
    
    a = 20 - a;
    ap = ap - 1;

    mat[a][ap] = '1';
}
//função check-in
void checkin(char mat[20][14]){
    int a, ap;

    do {
        printf("Digite o apartamento no qual deseja fazer o check-in:\n");
        printf("Andar: ");
        scanf("%d", &a);
        printf("Apartamento: ");
        scanf("%d", &ap);
    } while(a > 20 || a < 1 || ap > 14 || ap < 1);
    
    a = 20 - a;
    ap = ap - 1;

    mat[a][ap] = '2';
}
//função check-out
void checkout(char mat[20][14]){
    int a, ap;

    do {
        printf("Digite o apartamento no qual deseja fazer o check-out:\n");
        printf("Andar: ");
        scanf("%d", &a);
        printf("Apartamento: ");
        scanf("%d", &ap);
    } while(a > 20 || a < 1 || ap > 14 || ap < 1);
    
    a = 20 - a;
    ap = ap - 1;

    mat[a][ap] = '.';
}
//função cacelarReserva
void cancelarReserva(char mat[20][14]){
    int a, ap;

    do {
        printf("Digite o apartamento no qual deseja fazer o check-out:\n");
        printf("Andar: ");
        scanf("%d", &a);
        printf("Apartamento: ");
        scanf("%d", &ap);
    } while(a > 20 || a < 1 || ap > 14 || ap < 1);
    
    a = 20 - a;
    ap = ap - 1;

    mat[a][ap] = '.';
}


//função imprimir mapa do hotel
void imprimirMapa(char mat[20][14]){
    printf("Apto ->         01      02      03      04      05       06      07      08     09      10      11      12      13      14");
    for (int linha = 0; linha < 20; linha++){
        //calculo para imprimir matriz ao contrario
        int n = 20;
        n = n - linha;
        if (n > 9) { //teste para imprimir antes do numero de uma casa um "0"
            printf("\nAndar %d         ", n);
        } else {printf("\nAndar 0%d         ", n);}
        //imprimnir colunas por linha
        for (int coluna = 0; coluna < 14; coluna++){
            
            if (mat[linha][coluna] == '1'){ //imprimir apartamento reservado
                printf("R       ");
            } else if (mat[linha][coluna] == '2'){ //imprimir apartamento ocupado
                printf("O       "); 
            } else {printf(".       "); }//imprimir apartamento vazio   
        } 
    }
}

//main / interacao com o usuario
int main(){
    //definindo regiao dos simbulos
    //setLocale(LC_ALL, "Portuguese");
    
    //seja bem vindo:
    printf("Seja bem vindo ao Hotel!\n");
    
    //matriz Hotel
    char m[20][14];    
    
    
    //menu:
    int op;
    int repetir = 0;
    do {
        op = 0;
        printf("\n\nMenu do Hotel:\n(1) CHECK-IN DE HOSPEDE\n(2) CHECK-OUT DE HOSPEDE\n(3) RESERVA DE APARTAMENTO\n(4) CANCELAR UMA RESERVA\n(5) MAPA DE OCUPAÇÃO E RESERVAS DO HOTEL\n(6) INFORMAÇÕES DE HOSPEDE\n(7) TAXAS DE OCUPAÇÃO E RESERVAS DO HOTEL\n(8) SAIR DO PROGRAMA\n");
        do {
            printf("\nDigite a opção desejada: ");
            scanf("%d", &op);   
        } while (op > 8 || op < 0);
        

        switch(op){
            case 1:
                printf("Opção Selecionada: (1) CHECK-IN DE HOSPEDE\n");
                //acessar funcao checkin
                checkin(m);
                break;
            case 2:
                printf("Opção Selecionada: (2) CHECK-OUT DE HOSPEDE\n");
                //acessar funcao checkout
                checkout(m);
                break;
            case 3:
                printf("Opção Selecionada: (3) RESERVA DE APARTAMENTO\n");
                //acessar funcao
                reservar(m); 
                break;
            case 4:
                printf("Opção Selecionada: (4) CANCELAR UMA RESERVA\n");
                //acessar funcao 
                cancelarReserva(m);
                break;
            case 5:
                printf("Opção Selecionada: (5) MAPA DE OCUPAÇÃO E RESERVAS DO HOTEL\n");
                imprimirMapa(m);
                break;
            case 6:
                printf("Opção Selecionada: (6) INFORMAÇÕES DE HOSPEDE\n");
                //acessar funcao 
                break;
            case 7:
                printf("Opção Selecionada: (7) TAXAS DE OCUPAÇÃO E RESERVAS DO HOTE\n");
                //acessar funcao 
                //modelo usar contador
                break;
            case 8:
                printf("\nOpção Selecionada: (8) SAIR DO PROGRAMA\n");
                printf("O PROGRAMA FOI FECHADO\n");
                repetir = 1;
                //exit;
        }
        
    } while(repetir == 0);
}

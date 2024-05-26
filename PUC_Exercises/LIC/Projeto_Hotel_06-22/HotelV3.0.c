//PROJETO DE LIC - CONTROLE DE RESERVAS E OCUPAÇÃO DO HOTEL
//COM-MA1A - GRUPO 04 - INTEGRANTES: LEONARDO GRUPIONI, VICTORIA FERRARESE, KEISY ALVES
//DATA DE INICIO 07/06/2022
//LicHotelv2.c

//bibliotecas:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HotelV2.0_HeaderHotel.h"

//HEADER EM OUTRO ARQUIVO RODAR APENAS COM OS DOIS NA MESMA PASTA

//variavel global matriz hotel:
char hotel[20][14];

struct HOSPEDE{
    char cpf[15]; //XXX XXX XXX XX
    char nome[30]; //Nome Sobrenome (usar gets)
    char endereco[100]; //endereco completo: <rua> <numero> <complemento> <cidade> <estado> <pais> <cep>
    char telefone[20]; // (Codigo de area) (DDD) (Numero)
    char email[50]; //email@blabla.bla
};
struct HOSPEDE hospedesHotel[20][14];


void alocarMatriz(int x[1], int y[1]){
    x[0] = x[0] - 1; //andar = andar - 1 = (posição na matriz)
    y[0] = y[0] - 1; //apto = apto - 1 = (posição na matriz)
}

//legenda ()vazio = '.', (R)reservado = '1', (O)ocupado '2';

int testarReserva(int z[1], int w[1]){
    int indisponivel = 1;
    int disponivel = 0;    
    if(hotel[z[0]][w[0]] == '2' || hotel[z[0]][w[0]] == '1'){
        return indisponivel;
    } else return disponivel;
}

int testarCheckin(int z[1], int w[1]){ 
    int indisponivel = 1;
    int disponivel = 0;    
    if(hotel[z[0]][w[0]] == '2'){
        return indisponivel;
    } else return disponivel;
}

int testarCheckout(int z[1], int w[1]){ 
    int indisponivel = 1;
    int disponivel = 0;    
    if(hotel[z[0]][w[0]] == '2'){
        return disponivel;
    } else return indisponivel;
}

int testarCancelaReserva(int z[1], int w[1]){ 
    int indisponivel = 1;
    int disponivel = 0;    
    if(hotel[z[0]][w[0]] == '1'){
        return disponivel;
    } else return indisponivel;
}

void addInfoHospede(int z[1], int w[1]){
    printf("Adicionar dados do hospede: \n");
    fflush(stdin);
    printf("CPF (apenas numeros): ");
    fgets(hospedesHotel[z[0]][w[0]].cpf, 14, stdin);    
    printf("Nome: ");
    fgets(hospedesHotel[z[0]][w[0]].nome, 29, stdin);
    printf("Endereco: ");
    fgets(hospedesHotel[z[0]][w[0]].endereco, 99, stdin);
    printf("Telefone: ");
    fgets(hospedesHotel[z[0]][w[0]].telefone, 19, stdin);
    printf("Email: ");
    fgets(hospedesHotel[z[0]][w[0]].email, 49, stdin);
    printf("Dados adicionados com sucesso!\n");    
}

int conferirLotacao(){
    int contLot = 0; //contLot = contador de lotacao
    //loop varredura da lotacao do hotel
    for (int linha = 19; linha >= 0; linha--){
        for (int coluna = 0; coluna < 14; coluna++){
            if (hotel[linha][coluna] == '1' || hotel[linha][coluna] == '2'){ 
                contLot++;  
            }
        } 
    }
    return contLot;
}

void reservar(){
    int a[1], ap[1];//a = andar, ap = apto
    int loop; //controlador do loop
    int opInterna; //opcao de selecao
    do {
        loop = 1;
        do {
            printf("Digite o apartamento no qual deseja fazer a reserva:\n");
            printf("Andar: ");
            scanf("%d", &a[0]);
            printf("Apartamento: ");
            scanf("%d", &ap[0]);
        } while(a[0] > 20 || a[0] < 1 || ap[0] > 14 || ap[0] < 1); //testar entrada
    
        alocarMatriz(a, ap); 
        if (testarReserva(a,ap) == 1){
            printf("Este apartamento esta indisponivel\n");
            printf("Voce deseja reservar outro apartamento? (1) SIM (2) NAO\n");
            scanf("%d", &opInterna);
            if (opInterna == 2) loop = 0;
        } else {
            hotel[a[0]][ap[0]] = '1'; 
            printf("Apartamento reservado com sucesso\n");
            loop = 0;   
        } 
    } while(loop == 1);
}

void checkin(){
    int a[1], ap[1];
    int loop; //controlador do loop
    int opInterna; //opcao de selecao
    do {
        loop = 1;
        do {
            printf("Digite o apartamento no qual deseja fazer o checkin:\n");
            printf("Andar: ");
            scanf("%d", &a[0]);
            printf("Apartamento: ");
            scanf("%d", &ap[0]);
        } while(a[0] > 20 || a[0] < 1 || ap[0] > 14 || ap[0] < 1); //testar entrada
        
        alocarMatriz(a, ap); 
        if (testarCheckin(a,ap) == 1){
            printf("Este apartamento esta indisponivel para check-in\n");
            printf("Voce deseja fazer checkin de outro apartamento? (1) SIM (2) NAO\n");
            scanf("%d", &opInterna);
            if (opInterna == 2) loop = 0;
        } else {
            hotel[a[0]][ap[0]] = '2'; 
            printf("Apartamento ocupado com sucesso\n");
            addInfoHospede(a,ap);
            loop = 0;   
        }     
    } while(loop == 1);
}

void checkout(){
    int a[1], ap[1];
    int loop; //controlador do loop
    int opInterna; //opcao de selecao
    do {
        loop = 1;
        do {
            printf("Digite o apartamento no qual deseja fazer o checkout:\n");
            printf("Andar: ");
            scanf("%d", &a[0]);
            printf("Apartamento: ");
            scanf("%d", &ap[0]);
        } while(a[0] > 20 || a[0] < 1 || ap[0] > 14 || ap[0] < 1); //testar entrada
        
        alocarMatriz(a, ap); 
        if (testarCheckout(a,ap) == 1){
            printf("Este apartamento nao esta ocupado\n");
            printf("Voce deseja fazer check-out de outro apartamento? (1) SIM (2) NAO\n");
            scanf("%d", &opInterna);
            if (opInterna == 2) loop = 0;
        } else {
            hotel[a[0]][ap[0]] = '.'; 
            printf("Apartamentos desocupado com sucesso\n");
            loop = 0;   
        }     
    } while(loop == 1);
}

void cancelarReserva(){
    int a[1], ap[1];
    int loop; //controlador do loop
    int opInterna; //opcao de selecao
    do {
        loop = 1;
        do {
            printf("Digite o apartamento no qual deseja cancelar a resrerva:\n");
            printf("Andar: ");
            scanf("%d", &a[0]);
            printf("Apartamento: ");
            scanf("%d", &ap[0]);
        } while(a[0] > 20 || a[0] < 1 || ap[0] > 14 || ap[0] < 1); //testar entrada
        
        alocarMatriz(a, ap); 
        if ((testarCancelaReserva(a,ap)) == 1){
            printf("Este apartamento nao esta reservado\n");
            printf("Voce deseja cancelar a reserva de outro apartamento? (1) SIM (2) NAO\n");
            scanf("%d", &opInterna);
            if (opInterna == 2) loop = 0;
        } else {
            hotel[a[0]][ap[0]] = '.'; 
            printf("Reserva cancelada com sucesso\n");
            loop = 0;   
        }     
    } while(loop == 1);
}

void quartosReservado(){
    int controle = 1;
    printf("Apartamentos reservados: ");
    for (int linha = 19; linha >= 0; linha--){
        for (int coluna = 0; coluna < 14; coluna++){
            if (hotel[linha][coluna] == '1'){ //imprimir apartamento reservado
                printf("Andar %d° Apartamento %d | ", linha+1, coluna+1);
                controle = 0;  
            }
        } 
    }
    if (controle == 1) printf("Nao ha apartamentos reservados!\n");
}

void taxaOcupacao(){
    int contR = 0; //contR = contador de aptos reservados
    int contO = 0; //contO = contador de aptos ocupados
    int opTaxa; //opcao de selecao do switch
    float taxas[3]; //taxas de ocupacao
    printf("Taxa de ocupacao do hotel: \n");
    for (int linha = 19; linha >= 0; linha--){
        for (int coluna = 0; coluna < 14; coluna++){
            if (hotel[linha][coluna] == '1'){ //contar apartamentos reservados
                contR++;  
            }
            if (hotel[linha][coluna] == '2'){ //contar apartamentos ocupados
                contO++;  
            }
        } 
    }
    printf("Qual taxa de ocupacao voce deseja acessar:\n");
    printf("(1) TAXA DE OCUPACAO (RESERVADOS E OCUPADOS)\n");
    printf("(2) TAXA DE OCUPACAO (RESERVADOS)\n");
    printf("(3) TAXA DE OCUPACAO (OCUPADOS)\n");
    do {
        printf("Qual opcao voce deseja: ");
        scanf("%d", &opTaxa);
    } while(opTaxa > 3 || opTaxa < 1); // controle de selecao
    switch(opTaxa){
        case 1: //taxa ocupação reservas/ocupados
            taxas[0] = (contR + contO) * 100.0 / 280.0; 
            printf("Taxa de ocupacao de apartamentos reservados e ocupados: %.2f %%", taxas[0]);
            break;
        case 2: //taxa ocupação reservados
            taxas[1] = contR * 100.0 / 280.0;
            printf("Taxa de ocupacao de apartamentos reservados: %.2f %%", taxas[1]);
            break;
        case 3: //taxa ocupação ocupados
            taxas[2] = contO * 100.0 / 280.0;
            printf("Taxa de ocupacao de apartamentos ocupados: %.2f %%", taxas[2]);
            break;
    }
}
//taxa de ocupação calculo:
//280 --- 100%
//apto -- taxa%
//legenda: total de apartamentos do hotel = 280

void infoHospedes(){
    int a[1], ap[1];
    int loop; //controlador do loop
    int opInterna; //opcao de selecao
    do {
        loop = 1;
        do {
            printf("Digite o apartamento no qual deseja acessar as informacoes do hospede:\n");
            printf("Andar: ");
            scanf("%d", &a[0]);
            printf("Apartamento: ");
            scanf("%d", &ap[0]);
        } while(a[0] > 20 || a[0] < 1 || ap[0] > 14 || ap[0] < 1); //testar entrada
        
        alocarMatriz(a, ap); 
        if (testarCheckout(a,ap) == 1){ //testar se ha alguem ocupando este apto (reciclagem de funcao)
            printf("Nao ha hospede neste apartamento\n");
            printf("Voce deseja ver as informacoes de outro hospede? (1) SIM (2) NAO\n");
            scanf("%d", &opInterna);
            if (opInterna == 2) loop = 0;
        } else { 
            printf("Informacoes do hospede:\n");
            printf("Adicionar dados do hospede: \n");
            printf("CPF: %s\n", hospedesHotel[a[0]][ap[0]].cpf);
            printf("Nome: %s\n", hospedesHotel[a[0]][ap[0]].nome);
            printf("Endereco: %s\n", hospedesHotel[a[0]][ap[0]].endereco);
            printf("Telefone: %s\n", hospedesHotel[a[0]][ap[0]].telefone);
            printf("Email: %s\n", hospedesHotel[a[0]][ap[0]].email);
            printf("\n");    
            loop = 0;   
        }     
    } while(loop == 1);

}

//função imprimir mapa do hotel
void imprimirMapa(){
    printf("Apto ->         01      02      03      04      05       06      07      08     09      10      11      12      13      14");
    for (int linha = 19; linha >= 0; linha--){

        if (linha > 8) { //teste para imprimir antes do numero de uma casa um "0"
            printf("\nAndar %d         ", linha+1);
        } else {printf("\nAndar 0%d         ", linha+1);}
        //imprimnir colunas por linha
        for (int coluna = 0; coluna < 14; coluna++){
            
            if (hotel[linha][coluna] == '1'){ //imprimir apartamento reservado
                printf("R       ");
            } else if (hotel[linha][coluna] == '2'){ //imprimir apartamento ocupado
                printf("O       "); 
            } else {printf(".       "); }//imprimir apartamento vazio   
        } 
    }
}

//main (interacao com o usuario)
int main(){
    //seja bem vindo:
    printf("Seja bem vindo ao Hotel!\n");
       
    //menu:
    int op;
    int repetir = 0;
    int opInterna;
    do {
        op = 0;
        printf("\nMenu do Hotel:\n(1) CHECK-IN DE HOSPEDE\n(2) CHECK-OUT DE HOSPEDE\n(3) RESERVA DE APARTAMENTO\n(4) CANCELAR UMA RESERVA\n(5) MAPA DE OCUPACAO E RESERVAS DO HOTEL\n(6) INFORMACOES DE HOSPEDE\n(7) TAXAS DE OCUPACAO E RESERVAS DO HOTEL\n(8) SAIR DO PROGRAMA\n");
        do {
            printf("\nDigite a opcao desejada: ");
            scanf("%d", &op);   
        } while (op > 8 || op < 0);
        
        switch(op){
            case 1:
                printf("Opcao Selecionada: (1) CHECK-IN DE HOSPEDE\n");
                checkin();
                break;
            case 2:
                printf("Opcao Selecionada: (2) CHECK-OUT DE HOSPEDE\n");
                checkout();
                break;
            case 3:
                if ((conferirLotacao()) == 280){
                    printf("Nao e possivel reservar, pois nao ha apartamentos disponiveis\n");
                    break;
                }
                printf("Opcao Selecionada: (3) RESERVA DE APARTAMENTO\n");
                printf("Voce deseja visualisar os apartamentos ja reservados antes de fazer a reserva? digite (1), se nao digite (2)\n");
                scanf("%d", &opInterna);
                switch(opInterna){
                    case 1:
                        quartosReservado();
                        reservar(); 
                        break;
                    default:
                        reservar();
                        break;
                }  
                break;
            case 4:
                printf("Opcao Selecionada: (4) CANCELAR UMA RESERVA\n");
                cancelarReserva();
                break;
            case 5:
                printf("Opcao Selecionada: (5) MAPA DE OCUPACAO E RESERVAS DO HOTEL\n");
                imprimirMapa();
                break;
            case 6:
                printf("Opcao Selecionada: (6) INFORMACOES DE HOSPEDE\n");
                infoHospedes();
                break;
            case 7:
                printf("Opcao Selecionada: (7) TAXAS DE OCUPACAO E RESERVAS DO HOTE\n");
                taxaOcupacao();
                break;
            case 8:
                printf("\nOpcao Selecionada: (8) SAIR DO PROGRAMA\n");
                printf("O PROGRAMA FOI FECHADO\n");
                repetir = 1;
                //exit;
        }
        
    } while(repetir == 0);
}
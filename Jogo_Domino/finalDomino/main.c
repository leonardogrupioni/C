/* Jogo de Domino
*  PUC-SP Ciencias da Computacao
*  2° Periodo LP - Laboratorio de programacao (COM-MA2A)
*  Professor Julio Arakaki
*  Grupo: Gabriel Odakura, Julia Martins, Leonardo Grupioni e Victoria Ferrarese
*  Objetivo: Desenvolver em C um jogo de domino, utilizando o modelo MVC para organização do codigo, o jogo  
*            seguira as regras convencionais do domino e podera ser jogado entre dois jogadores ou contra a IA. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//inclui os outros arquivos do projeto e unifica o todo
#include "model.h"
#include "view.h"
#include "controller.h"

int main(){
    
    //criando a array pecas
    PECA pecas[TOTAL_PECAS];

    //criando a array mesa
    PECA_MESA mesa[TOTAL_PECAS];

    //criando tipo contador
    CONTADOR * cont = (CONTADOR*) malloc(sizeof(CONTADOR));

    int lados[2];

    //acessando o controller
    acessarMenuPrincipal(pecas, &cont, mesa, lados);
    
    free(cont);
}
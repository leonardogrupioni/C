#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void imprimirAbertura(){
    printf("\n\nBEM-VINDO(A) AO JOGO DA VIDA!!\n\n");
}
void imprimirMenuInicial(){
    printf("\nMENU:\n");
    printf("[1] Criar novo mundo\n");
    printf("[2] Carregar mundo salvo\n");
    printf("\nSelecione a opcao que deseja: ");
}
void imprimirMenuJogar(){
    printf("\nMENU:\n");
    printf("[1] Adicionar seres vivos\n");
    printf("[2] Simular geracoes\n");
    printf("[3] Limpar mundo\n");
    printf("[4] Salvar mundo\n");
    printf("[5] Voltar\n");
    printf("\nSelecione a opcao que deseja: ");
}
void imprimirMenuAdicionarSerVivo(){
    printf("\n");
    printf("[1] Adicionar seres vivos manualmente (um por um)\n");
    printf("[2] Escolher padrao ja existente de seres vivos\n");
    printf("\nSelecione a opcao que deseja: ");
}
void imprimirMenuSimularGeracao(){
    printf("\n");
    printf("[1] Definir o tempo de simulacao das geracoes\n");
    printf("[2] Simular geracoes automaticamente\n");
    printf("[3] Simular geracoes manualmente\n");
    printf("\nSelecione a opcao que deseja: ");
}
void imprimirPadroesSeresVivos(){
    
    printf("\n\t\tPADROES DE SERES VIVOS: \n\n");
    printf(" *                      *     *        *  \n");
    printf(" *    * * *    * *    *         *     *   \n");
    printf(" *             * *    *     * * *    *    \n\n");
    printf("[1]    [2]     [3]    [4]    [5]     [6]  \n");
    printf("\nSelecione a opcao que deseja: ");
}
void imprimirApresentarMundo(){
    printf("\t\tEsse e o seu mundo!!\n");
}
void imprimirOpcaoInvalida(){
    printf("\nOpcao invalida!!\n");
}
void imprimirEscolherTamanhoMundo(){
    printf("\nO tamanho do mundo deve ser entre 10 e 60. Escolha o tamanho desse mundo: \n");
}
void imprimirReceberLinha(){
    printf("Linha: ");
}
void imprimirReceberColuna(){
    printf("Coluna: ");
}
void imprimirEscolherQtdSeresVivos(){
    printf("\nQuantos seres vivos deseja colocar no mundo? ");
}
void imprimirEscolherPosicaoSeresVivos(){
    printf("\nDigite a coordenada de cada ser vivo que ira colocar no mundo\n");
}
void imprimirPosicaoInvalida(){
    printf("\nPosicao invalida\n");
}
void imprimirEscolherQtdGeracoes(){
    printf("Determine a quantidade de geracoes que deseja simular: ");
}
void imprimirProximaGeracao(){
    printf("\nDigite ""p"" para simular a proxima geracao e digite ""s"" para parar a simulacao\n");
}
void imprimirEscolherVelocidade(){
    printf("\nDetermine o tempo de simulacao das geracoes (em segundos): \n");
}
void imprimirMensagemErro(){
    printf("\nDesculpe, banco de dados indisponivel...\n");
}
void imprimirMensagemMundoSalvo(){
    printf("\nMundo salvo com exito!\n");
}
void imprimirMensagemMundoCarregado(){
    printf("\nMundo carregado com exito!\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "Portuguese");

    printf("=================\n");
    printf("Calculadora Em C!\n");
    printf("=================\n");

    float operando1, operando2, resultado;
    int operacao, rep = 0;

    while (rep == 0){
        printf("\nDigite o primeiro valor: ");
        scanf("%f", &operando1);
        printf("Digite o segundo valor: ");
        scanf("%f", &operando2);

        op:
        printf("Selecione qual tipo de opera��o voc� deseja \n [1] - soma \n [2] - subtra��o \n [3] - divis�o \n [4] - multiplica��o\n [5] - sair da calculadora\n");
        scanf("%d", &operacao);

        switch (operacao) {
        case 1:
            resultado = operando1 + operando2;
            break;
        case 2:
            resultado = operando1 - operando2;
            break;
        case 3:
            resultado = operando1 / operando2;
            break;
        case 4:
            resultado = operando1 * operando2;
            break;
        case 5:
            exit(0);
        break;
        default:
            printf("Este valor n�o � valido, digite uma op��o valida");
            goto op;
        }

        printf("O resultado da opera��o � %.2f", resultado);
        //printf("\nDigite [1] para continuar calculando ou qualquer outra tecla para sair");
        //scanf("&d", &rep);
    }




    printf("");
    return 0;
}

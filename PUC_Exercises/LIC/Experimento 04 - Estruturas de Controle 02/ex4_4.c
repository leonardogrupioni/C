#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //declaracao dos dados
    int dia, mes, ano;

    //dados de entrada
    printf("Digite a data:\n");
    printf("Dia:");
    scanf("%d", &dia);
    printf("Mes: ");
    scanf("%d", &mes);
    printf("Ano: ");
    scanf("%d", &ano);

    //declaracao p/calculo
    int qdias = 0; // quantidade de dias
    int mes30 = 30;
    int mes31 = 31;
    int fev = 28;
    //mes com 30 dias: abr, jun, set, nov (4,6,9,11)
    //mes com 31 dias: jan, mar, mai, jul, ago, out, dez (1,3,5,7,8,10,12)
    //fev em n bissexto = 28 dias

    //contagem dos dias até a data de entrada:
    switch (mes){
    case 1: //jan
    qdias = dia;
    break;
    case 2: //fev
    qdias = mes31 + dia;
    break;
    case 3: //mar
    qdias = mes31 + fev + dia;
    break;
    case 4: //abr
    qdias = mes31*2 + fev + dia;
    break;
    case 5: //mai
    qdias = mes31*2 + fev + mes30 + dia;
    break;
    case 6: //jun
    qdias = mes31*3 + fev + mes30 + dia;
    break;
    case 7: //jul
    qdias = mes31*3 + fev + mes30*2 + dia;
    break;
    case 8: //ago
    qdias = mes31*4 + fev + mes30*2 + dia;
    break;
    case 9: //set
    qdias = mes31*5 + fev + mes30*2 + dia;
    break;
    case 10: //out
    qdias = mes31*5 + fev + mes30*3 + dia;
    break;
    case 11: //nov
    qdias = mes31*6 + fev + mes30*3 + dia;
    break;
    case 12: //dez
    qdias = mes31*6 + fev + mes30*4 + dia;
    break;
    default:
    printf("o mes digitado é invalido");
    }

    // em caso de ano bissexto:
    if (ano%4==0 && ano%100!=0 && mes>2) {
        qdias = qdias+1;
    }

    printf("Do inicio do ano %d, até a data %d/%d/%d, se passaram %d dias", ano, dia, mes, ano, qdias);

    return 0;
}

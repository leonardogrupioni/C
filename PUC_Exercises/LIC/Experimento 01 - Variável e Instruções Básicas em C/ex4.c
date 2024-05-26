//EX_4
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // qpag = quantidade de paginas; qh = quantidade de horas; qhr = resto da quantidade de horas;
    // qm = quantidade de minutos; resto da quantidade de minutos; qs = quantidade de segundos.
    int qpag = 0, qh = 0, qhr = 0, qm = 0, qmr = 0, qs = 0;

    printf("Quantas paginas da lista telefonica voce deseja imprimir? ");
    scanf("%d", &qpag);

    /*qs = 12 * qpag;
    while (qs > 59) {
        qs = qs - 60;
        qm = qm + 1;
    }
    while (qm > 59) {
        qm = qm - 60;
        qh = qh + 1;
    }*/

    qs = qpag * 12;
    qh =  qs / 3600;
    qhr = qs % 3600;
    qm = qhr / 60;
    qmr = qhr % 60 = qs;
    qs = qmr;

    printf("ira demorar %d horas %d minutos %d segundos", qh, qm, qs);
    return 0;
}

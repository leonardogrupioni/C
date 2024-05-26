#include <stdio.h>
#include <stdlib.h>
/*programa calcular media final de lic*/


int main() {

    float p1;
    float p2;
    float a1;
    float a2;
    float n1;
    float n2;
    float mf;

    printf("digite o resultado da prova 1:");
    scanf("%f",&p1);

    printf("digite o resultado da prova 2:");
    scanf("%f",&p2);

    printf("digite o resultado da atividade 1:");
    scanf("%f",&a1);

    printf("digite o resultado da atividade 2:");
    scanf("%f",&a2);

    n1 = (p1*3+a1*2)/5;
    n2 = (p2*3+a2*2)/5;
    mf = (n1+n2)/2;

    printf("media final igual a %f", mf);

    return(0);

}

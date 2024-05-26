#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Tabela de Convercao\n");

    float fahr, cel;

    printf("Farenheits | Celsius\n");
    for (int i = 0; i <= 300; i=i+20) {
        fahr = i;

        cel = ((fahr-32)/1.8);

        printf("%.1f\t   %f \n", fahr, cel);
    }

}

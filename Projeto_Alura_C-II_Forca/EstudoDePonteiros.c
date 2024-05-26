//Escreva uma função soma que recebe um ponteiro de inteiro num e mais 
//dois inteiros a e b. A função deve calcular a soma de a+b em num.
#include <stdio.h>
#include <stdlib.h>

void soma(int* num, int a, int b){
    (*num) = a + b;
}

int main(){
    int num;
    int a,b;
    a = 10;
    b = 10;
    soma(&num, a, b);
    printf("A soma de a = %d + b = %d, eh num = %d",a,b,num);
}
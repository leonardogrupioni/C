#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void){

	setlocale(LC_ALL, "Portuguese"); //LC_CTYPE = apenas texto

	// p1 e p2 = provas; a1 e a2 = atividades; n1 e n2 = medias 1 e 2; mf = media final.
    float p1 = 0, p2 = 0, a1 = 0, a2 = 0, n1, n2, mf;
    // nm = nome da matéria
    char nm[7];

    printf("De qual matéria você deseja saber a média final?\n");
    scanf("%s", &nm);

    printf("===============================\n");
    printf("Calculo da média final de: %s\n", nm);
    printf("===============================\n\n");

    printf("OBS: use ',' para notas com decimais\n\n");


    p1_: //usado no goto
    printf("Digite a nota da prova 1: ");
    scanf("%f", &p1);

    /*while ((p1 < 0 || p1 > 10)) {
        printf("A nota %3.2f é Invalida!\n", p1);
        printf("Digite uma nota entre 0 e 10\n");
        getch (0);
    }*/

    if ((p1 < 0 || p1 > 10)) {
            while(p1 != -1) {
            printf("A nota %3.2f é Invalida!\n", p1);
            printf("Digite uma nota entre 0 e 10\n");
            goto p1_; //usado para voltar a linha p1_
        }
    }

    a1_:
    printf("Digite a nota da atividade 1: ");
    scanf("%f", &a1);

    if ((a1 < 0 || a1 > 10)) {
            while(a1 != -1) {
            printf("A nota %3.2f é Invalida!\n", a1);
            printf("Digite uma nota entre 0 e 10\n");
            goto a1_;
        }
    }

    p2_:
    printf("Digite a nota da prova 2: ");
    scanf("%f", &p2);

    if ((p2 < 0 || p2 > 10)) {
            while(p2 != -1) {
            printf("A nota %3.2f é Invalida!\n", p2);
            printf("Digite uma nota entre 0 e 10\n");
            goto p2_;
        }
    }

    a2_:
    printf("Digite a nota da atividade 2: ");
    scanf("%f", &a2);

    if ((a2 < 0 || a2 > 10)) {
            while(a2 != -1) {
            printf("A nota %3.2f é Invalida!\n", a2);
            printf("Digite uma nota entre 0 e 10\n");
            goto a2_;
        }
    }

    // duvida: é possivel transformar esses comandos repetidos 4 vezes em apenas 1, que possa ser usado como variavel?


    n1 = (p1*3+a1*2)/5;
    n2 = (p2*3+a2*2)/5;
    mf = (n1+n2)/2;

    if(mf < 5){
        printf("\nInfelizmente sua média final é: %3.2f\n", mf);
        printf("Você esta reprovado nessa matéria\n");
    }
    else {
        printf("\nParabéns você foi aprovado com média: %3.2f\n", mf);
    }

    return(0);

    // meta: criar uma opcao de repetir o programa sem fechar o cmd, mantendo a primeira materia salva e podendo consultar o boletim ao final.
}



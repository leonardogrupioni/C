#ifndef EQ2G_INCLUDED
#define EQ2G_INCLUDED
// novo tipo de dado
typedef struct _eq2g{
    double a, b, c;
 } Eq2g;
#endif // Eq2g

typedef int boolean;

#define TRUE 1
#define FALSE 0

// prototipos (assinaturas) da funcoes
void imprimirEq2g(Eq2g);
void imprimirDelta(Eq2g);
double calcularDelta(Eq2g);
double calcularRaiz1(Eq2g);
double calcularRaiz2(Eq2g);
void imprimirRaizes(double, double);
void imprimirMsg(char []);
boolean temRaizes(Eq2g);

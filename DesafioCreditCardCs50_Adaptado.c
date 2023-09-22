#include <stdio.h>
#include <string.h>

int main()
{
   	// Declaração de variavel para armazenar a sequencia dos digitos
   	long long int n;
    
   	// Declaração de array para armazenar cada valor da sequencia de digitos em uma posição
   	int valor[16];

    	// Solicita um número longo até que seja inserido um valor maior ou igual a 1
   	do {
    		printf("Numero: ");
    		scanf("%lld", &n);
    	} while (n < 1);
    
	// Inicialização dos contadores de soma zerados
	int primeiraSoma = 0;
	int segundaSoma = 0; 
	
	int i = 0; // Inicia o apontador "indice" com 0 para inserir na primeira posição da array 
	
	// Ao alterar a estrutura de dados de varias variaveis para uma array que comporta todas as variaveis
    	// é possível alterar a inicialização sequencial de todas as variaveis por um loop que acessa todas
    	// as posições da array
	
	for(i = 0; n!=0; i++){ // Loop que adiciona os digitos na array e alimenta os contadores de primeira e segunda soma
		valor[i] = n % 10; // Armazena na array
		n = n / 10; // Avança para o proximo digito
		
		if(i % 2 != 0){ // Verifica se o indice esta na posicao adequada para multiplar o valor por 2 avançando de 2 em 2
			if((valor[i] * 2) / 10 != 0){ // Verifica se algum dos numeros quando multiplicado por 2 possui algum valor decimal
				primeiraSoma = primeiraSoma + (valor[i] * 2) / 10; // Adiciona a soma o valor decimal
				primeiraSoma = primeiraSoma + (valor[i] * 2) % 10; // Adiciona a soma o valor da unidade
			} else primeiraSoma = primeiraSoma + valor[i] * 2; // Se não há valor decimal adiciona apenas o valor da unidade
		} else segundaSoma = segundaSoma + valor[i];// Adiciona os valores que não pertencem a primeira regra, na segundaSoma
	}
	int qtd = i; // Quantidade de numeros na array
	
	int somaTotal = primeiraSoma + segundaSoma; // Junta os dois contadores
	
	if(somaTotal%10 == 0){ // Verifica se a soma dos contadores deu um valor terminado em 0
		if((qtd == 16) && (valor[qtd-1] == 5 && (valor[qtd-2] >= 1 && valor[qtd-2] <= 5))) printf("\nMASTERCARD\n");
		else if((qtd == 15) && (valor[qtd-1] == 3 && (valor[qtd-2] == 4 || valor[qtd-2] == 7))) printf("\nAMERICAN EXPRESS\n");
		else if((qtd == 13 || qtd == 16) && (valor[qtd-1] == 4))printf("\nVISA\n");	
	} else printf("\nINVALIDO\n");
	// Vale ressaltar que a validação quando há uma array é feita acessando a posicao da array pela qtd de elementos em vez de uma variavel fixa
	
    return 0;
}

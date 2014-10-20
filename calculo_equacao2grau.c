#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
Calcula a equacao do 2 grau.
*/
int main(){
    
	// Armazena os coeficientes da equacao do 2 grau que o usuario ira informar.
	int a = 0;
	int b = 0;
	int c = 0;
	
	// Armazena as raizes da equacao.
	float x1 = 0;
	float x2 = 0;
	
	// armazena o valor de dalta.
	float delta = 0;
	
	// condicao para realizar ou nao mais uma equacao.
	char simOuNao = 'c';
	
	printf("Calculo equacao 2 grau\n");
	
	do {
	
		printf("Digite o valor dos coeficientes:\n");
	
		printf("Digite o valor de \'a\':\n");
	    scanf("%d", &a);
	
		printf("Digite o valor de \'b\':\n");
	    scanf("%d", &b);
	    
	    printf("Digite o valor de \'c\':\n");
	    scanf("%d", &c);
	
		// achar o delta
		delta = pow(b, 2) - 4 * a * c;
		
		if (delta < 0) {
			// nao existe raiz real
			printf("Nao existe raiz real\n");	
		} else {
			
			// calcula a primeira raiz
			x1 = (-b + sqrt(delta)) / (2 * a);
			
			if (delta > 0) {
				// delta sendo maior que zero, gerara duas raizes
				x2 = (-b - sqrt(delta)) / (2 * a);	
				printf("As raizes dessa equacao do 2 grau eh... x1: %.2f e x2: %.2f\n", x1, x2);
			} else {
				printf("Delta eh igual a zero. Existe apenas uma raiz: %.2f\n", x1);
			}
		}
		
		printf("Deseja realizar mais uma equacao?(y,n)\n");
		/*
		 preciso colocar o espaco antes do conversor %c, pois esse conversor ira 
		 consumir o caracter de nova linha que coloquei anteriormente na pergunta, gerando assim uma
		 condicao sempre falsa.		 
		*/

		//printf("%d", simOuNao);
		//simOuNao = getch(); // pega o que foi digitado sem precisar que o usuario aperte enter.
		//printf("%d", simOuNao);
		fflush( stdin );
		
		scanf("%c", &simOuNao); // parece que o
		
		// testa a condicao de realizar outro calculo ou encerrar.
	} while ( simOuNao == 'y' );
	
    system("pause");
    return 0;
}


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
	
	printf("Calculo equacao 2 grau\n");
	
	printf("Digite o valor de 'a':\n");
	scanf("%d", &a);
	
	printf("Digite o valor de 'b':\n");
	scanf("%d", &b);
	
	printf("Digite o valor de 'c':\n");
	scanf("%d", &c);
	
	// achar o delta
	delta = pow(b, 2) - 4 * a * c;
	
	if (delta < 0) {
		// nao existe raiz real
		printf("Nao existe raiz real\n");
	} else {
	
		// calcula das raizes
		x1 = (-b + sqrt(delta)) / (2 * a);
	
		x2 = (-b - sqrt(delta)) / (2 * a);
	
		printf("As raizes dessa equacao do 2 grau eh... x1: %.2f e x2: %.2f\n", x1, x2);
	}
	
	system("pause");
	return 0;
}

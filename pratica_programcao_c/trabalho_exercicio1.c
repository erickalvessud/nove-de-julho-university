#include<stdio.h>
#include<stdlib.h>
#define SIZE 7

/*

Exercicio 1:

Criar um programa que leia um vetor de 7 elementos de valores reais e apresente-os na ordem inversa àquela
em que foram fornecidos.

autor: Erick Alves

*/
int main(void){
	
	float numbers[SIZE];
	int i;
	
	printf("Digite %d valores no vetor de numeros reais:\n", SIZE);
	
	for(i = 0; i < SIZE; i++){
		
		printf("Elemento %d: ", i);
		scanf("%f", &numbers[i]);
	}
	
	printf("Valores digitados:\n\n");
	
	printf("| ");
	for(i = 0; i < SIZE; i++){
		printf("%.2f", numbers[i] );
		
		if (i + 1 < SIZE) {
			printf("\t");
		}
	}
	printf(" |\n");
	
	printf("\nForma inversa do que foi fornecido:\n\n");
	
	printf("| ");
	for(i = SIZE - 1; i >= 0; i--) {
		printf("%.2f", numbers[i] );
		
		if (i - 1 >= 0) {
			printf("\t");
		}
	}
	printf(" |\n");
	
	system("pause");
	return 0;
}

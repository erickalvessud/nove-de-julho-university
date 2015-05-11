#include<stdio.h>
#include<stdlib.h>
#define SIZE 16

/*
Exercicio 2:
Criar um programa que leia um vetor de 16 posicoes de valores inteiros e troque os 8 primeiros valores pelos
8 ultimos valores e vice-versa. Ao final apresentar na tela os dados do vetor obtido.
*/

int main(void){
	int numbers[SIZE];
	int i;
	
	for(i = 0; i < SIZE; i++) {
		printf("Element %d: ", i + 1);
		scanf("%d", &numbers[i]);
	}
	
	printf("\n");
	
	int temp = 0;
	int middle = SIZE / 2; 
	
	for(i = 0; i < middle; i++) {
		temp = numbers[i];
		numbers[i] = numbers[ i + middle ];
		numbers[ i + middle ] = temp;
	}

	printf("%d primeiros valores trocados pelos %d ultimos e vice-versa.\n\n", middle, middle);
	
	printf("| ");
	for(i = 0; i < SIZE; i++) {
		printf("%d", numbers[i]);
		
		if (i + 1 < SIZE) {
			printf("\t");
		}
	}
	printf(" |\n");
	
	system("pause");
	return 0;
}


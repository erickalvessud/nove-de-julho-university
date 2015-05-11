#include<stdio.h>
#include<stdlib.h>
#define TIME 2
#define SIZE 4

/*

Exercicio 3:

Criar um programa que leia dois vetores de 4 posições de valores inteiros. Criar outro vetor preenchendo-o
nas posições pares com os valores do primeiro vetor e nas posições ímpares com os valores do segundo vetor.
Apresentar na tela os dados do vetor criado.

autor: Erick Alves

*/
int main(void){
	
	int nums1[SIZE];
	int nums2[SIZE];
	
	int allNumbers[SIZE * 2];
	
	int i;
	int j;
	
	printf("Preencha duas listas de numeros inteiros:\n");
	
	for (i = 0; i < TIME; i++) {
		
		printf("%d Lista de numeros\n", i + 1);
		
		for (j = 0; j < SIZE; j++) {
			
			if (i == 0) {
				
				printf("Elemento %d: ", j);
				scanf("%d", &nums1[j]);
			} else {
				
				printf("Elemento %d: ", j);
				scanf("%d", &nums2[j]);
			}
		}
		printf("\n");
	}
	
	int pos = 0;
	int pos2 = 0;
	
	for (i = 0; i < SIZE * 2; i++) {
		
		if(i % 2 == 0) {
			
			allNumbers[i] = nums1[pos];
			pos++;
		} else {
			
			allNumbers[i] = nums2[pos2];
			pos2++;
		}
	}
	
	printf("Lista contendo os valores da lista 1 nas posicoes pares e da lista 2 nas posicoes impares:\n\n");
	
	printf("| ");
	for (i = 0; i < SIZE * 2; i++) {
		printf("%d", allNumbers[i]);
		
		if (i + 1 < SIZE * 2) {
			printf("\t");
		}
	}
	printf(" |\n");
	
	system("pause");
	return 0;
}

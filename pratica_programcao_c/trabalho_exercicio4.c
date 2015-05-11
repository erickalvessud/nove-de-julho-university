#include<stdio.h>
#include<stdlib.h>
#define L 4
#define C 4

/*

Exercicio 4:

Criar um programa que leia uma matriz 4 x 4 de valores inteiros e apresente na tela a localização (linha e
coluna) do maior valor da matriz.

autor: Erick Alves

*/
int main(void){
	
	int matriz[L][C];
	int i = 0;
	int j = 0;
	
	printf("Preencha a matriz %dx%d com valores inteiros: \n", L, C);
	
	for (i = 0; i < L; i++) {
		
		for (j = 0; j < C; j++) {
			printf("Elemento [%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	int linhaMaiorNum  = 0;
	int colunaMaiorNum = 0;
	
	for (i = 0; i < L; i++) {
		
		for (j = 0; j < C; j++) {
			
			if (matriz[linhaMaiorNum][colunaMaiorNum] < matriz[i][j]) {
				linhaMaiorNum = i;
				colunaMaiorNum = j;
			}
		}
	}
	
	printf("O maior elemento esta na Linha %d, Coluna %d", linhaMaiorNum, colunaMaiorNum);
	
	system("pause");
	return 0;
}

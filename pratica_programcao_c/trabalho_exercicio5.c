#include<stdio.h>
#include<stdlib.h>
#define ROW 5
#define COL 5

/*

Exercicio 5:

Criar um programa que declare uma matriz 5 x 5 e preencha com 1 a diagonal principal e com 0 os demais
elementos. Apresentar na tela a matriz obtida.

autor: Erick Alves

*/
int main(void){
	
	int matriz[ROW][COL];
	int i;
	int j;
	
	for(i = 0; i < ROW; i++ ){
		
		for (j = 0; j < COL; j++){
			
			if(i == j){
				
				matriz[i][j] = 1;	
			} else {
				matriz[i][j] = 0;	
			}
		}	
	}	
	
	for(i = 0; i < ROW; i++ ){
		
		printf("| ");
		
		for (j = 0; j < COL; j++){
			
			printf("%d", matriz[i][j]);
			
			if(j + 1 < COL){
				printf("\t");
			} else {
				printf(" |");
			}
		}
		if (i + 1 < ROW){
			printf("\n");
			printf("| ");
			printf("\t\t\t\t  ");
			printf("| ");
			printf("\n");
		}
	}
	
	system("pause");
	return 0;
}




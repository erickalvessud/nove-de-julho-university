#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*

Exercicio 6:

Criar um programa que leia uma string e substitua todas as ocorr?ncias da letra x (min?sculo) ou da letra X
(ma?usculo) pelo n?mero 0. Ao final, apresentar a string modificada e a quantidade de substituicoes.

autor: Erick Alves

*/

int main(void){
	
	char s[60];
	int i;
	
	printf("Digite uma frase qualquer\n");
	
	gets(s);
	
	int stringLength  = strlen(s);
	
	int qtdSubst = 0;
	for (i = 0; i < stringLength; i++ ) {
		if (s[i] == 'x' || s[i] == 'X') {
			s[i] = '0';
			qtdSubst++;
		}
	}
	
	puts(s);
	printf("Quantidade de substituicoes: %d\n", qtdSubst);
	
	system("pause");
	return 0;
}

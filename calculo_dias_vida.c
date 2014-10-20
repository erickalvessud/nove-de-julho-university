#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*c) Ler a idade de uma pessoa. Calcular e apresentar a existencia desta pessoa em
numero de dias, em numero de horas, em numero de minutos e em numero de
segundos.*/
int main(){
	
	int idade = 0;
	
	int dia = 0;
	int hora = 0;
	int minuto = 0;
	int segundo = 0;
	
	
	printf("Quantos dias de vida voce tem?\n");
	printf("Vamos comecar. Qual eh a sua idade?\n");
	scanf("%d", &idade);
	
	dia 	= idade * 365;
	hora 	= dia * 24;
	minuto 	= hora * 60;
	segundo	= minuto * 60;
	
	printf("Você tem %d dias, %d horas, %d minutos, %d segundos de vida.\n", dia, hora, minuto, segundo);
	
	system("pause");
	return 0;
}

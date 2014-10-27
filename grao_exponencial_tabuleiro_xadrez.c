#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int i = 1;
	double result = 0;
	double total = 0;
	
	while( i <= 64){
		
		if (result == 0) {
			result++;
			total = total + result;
			printf("Casa: %d \t Graos: %.1f\n", i, result);
			printf("Total de graos ate aqui: %.1f\n", result);
			i++;	
			continue;
		}
		
		result = result * 2;
		
		printf("Casa: %d \t Graos: %.1f\n", i, result);
		
		total = total + result;
		printf("Total de graos ate aqui: %.1f\n", total);
		i++;
	}
	printf("Total de graos a ser pago: %.1f\n", total);
	
	system("pause");
	return 0;
}

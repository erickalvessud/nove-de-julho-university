#include<stdio.h>
#include<stdlib.h>

int main(){	
	
	char simOuNao = 'c';
	
	printf("Calculo do desconto do INSS\n");
	
	do {
	
		char nome[10] = "0";
		float salarioBruto = 0;
		float salarioLiquido = 0;
		float taxaINSS = 0;
		float descontoINSS = 0;
		
		printf("Digite seu nome:\n");
		scanf("%s", &nome);
		
		printf("Digite seu salario:\n");
		scanf("%f", &salarioBruto);
		
		if(salarioBruto <= 500){
			//8%
			taxaINSS = 8/100.;
			descontoINSS = salarioBruto * taxaINSS;
			salarioLiquido = salarioBruto - descontoINSS;
			
		} else if (salarioBruto > 500 && salarioBruto <= 1000){
			//10%
			taxaINSS = 10/100.;
			descontoINSS = salarioBruto * taxaINSS;
			salarioLiquido = salarioBruto - descontoINSS;
		} else {
			//12%
			taxaINSS = 12/100.;
			descontoINSS = salarioBruto * taxaINSS;
			salarioLiquido = salarioBruto - descontoINSS;
		}
		
		int i = 0;
		printf("Nome do colaborador: ");
		while(i < (sizeof(nome)/sizeof(nome[0]))){
			printf("%c", nome[i]);
			i++;
		}
		printf("\n");
		
		printf("Salario Base (Bruto): %.2f \n", salarioBruto);
		printf("Taxa INSS: %.2f \n", taxaINSS);
		printf("Desconto INSS: %.2f \n", descontoINSS);
		printf("Salario Liquido: %.2f \n\n", salarioLiquido);
		
		printf("“Deseja fazer mais algum cálculo? (S/N)\n");
		fflush( stdin );
		
		scanf("%c", &simOuNao);
		
	} while ( simOuNao == 'S' || simOuNao == 's' );
	
	system("pause");
	return 0;
}

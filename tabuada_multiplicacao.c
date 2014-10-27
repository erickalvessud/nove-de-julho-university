#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int antecedente = 0;
	int consequente = 0;
	int resultado = 0;
	
	while(antecedente <= 12){
		
		consequente = 0;
		
		while(consequente <= 12){
			
			printf("%d x %d = %d \t %d x %d = %d \t %d x %d = %d \t %d x %d = %d \t\n", antecedente, consequente, (antecedente * consequente),
			antecedente + 1, consequente, ((antecedente + 1) * consequente),
			antecedente + 2, consequente, ((antecedente + 2) * consequente),
			antecedente + 3, consequente, ((antecedente + 3) * consequente));

			consequente++;
		}
		printf("\n");		
		antecedente = antecedente + 4;
	}
	
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int numeroUsuario = 0;
	int testeNovamente = 1;
	
	printf("Eh Primo?\n");

	while(testeNovamente == 1){
		
		printf("Digite um numero e saiba se ele eh primo ou nao:\n");
		scanf("%d", &numeroUsuario);
		
		int i = 2;
		int ehprimo = 0;
		
		while( i <= numeroUsuario ){
			
			if ( numeroUsuario % i == 0) {
				
				if (i == numeroUsuario) {
					ehprimo = 1;	
				}
				break;
			}
			i++;
		}
		if (ehprimo == 1) {
			printf("%d eh primo\n", numeroUsuario);
		} else {
			printf("%d nao eh primo\n", numeroUsuario);
		}
		printf("Deseja testar novamente? (Digite 0 para nao ou 1 para sim)\n");
		scanf("%d", &testeNovamente);
	}
	system("pause");
	return 0;
}

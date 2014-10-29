#include<stdio.h>
#include<stdlib.h>

int main(){
    
	float imc = 0;    
    // valores inseridos pelo usuario.
    float massa = 0;
    float altura = 0;
    
	// indice que o usuario perde ou ganha por mes.(informado pelo usuario)
    float taxaUsuario = 0;
    
	// peso ideal de uma pessoa normal.
    float pesoIdeal = 0;
    float pesoDiff = 0;
    // meses que o usuario precisa para perder ou ganhar peso para chegar ao seu peso ideal.
    int mes = 0;
    
    float ideal = 0;
    
    printf("Digite seu peso:\n");
    scanf("%f", &massa);
    
    printf("Digite sua altura:\n");
    scanf("%f", &altura);
    
    imc = massa / (pow(altura, 2));
    
    if( imc < 17) {
        printf("Muito abaixo do peso\n");
    } else if( imc >= 17 && imc < 18.49 ) {
        printf("Abaixo do peso\n");           
    } else if (imc >= 18.5 && imc < 24.99){
        ideal = 1;
        printf("Peso normal\n");             
    } else if (imc >= 25 && imc < 29.99) {
        printf("Acima do peso\n");           
    } else if(imc >=30 && imc < 34.99){
        printf("Obesidade 1\n");    
    } else if( imc >=35 && imc < 39.99){
        printf("Obesidade 2\n");   
    } else {
        printf("Obesidade 3\n");           
    }
    
	if (ideal == 0) {

		if (imc < 18.5) {
          // ele esta abaixo do peso
          
          	pesoIdeal = 18.5 * (pow(altura, 2));
                
       	} else {
         	// ele acima do peso
         
          	pesoIdeal = 24.99 * (pow(altura, 2));         
       	}

       	pesoDiff = massa - pesoIdeal;
	   
	   	float result = 0;
	   	
		if (pesoDiff > 0) {
	    	
	    	printf("Para sua altura, seu peso ideal eh %.2f Voce precisa perder: %.2fkg\n", pesoIdeal, pesoDiff);
	        printf("Em porcentagem, quanto voce consegue perder\n");
	        scanf("%f", &taxaUsuario);                 
	        
	        while( massa > pesoIdeal){
	             result = massa * (taxaUsuario/100);
	             massa = massa - result;
	             imc = massa / (pow(altura, 2));
	             mes++;
	             
	             printf("Sua massa eh %.2f, seu IMC: %.2f, em %d\n", massa, imc, mes);
	        }
	    } else {
	    	
			printf("Seu peso ideal eh %.2f Voce precisa ganhar: %.2f\n", pesoIdeal, pesoDiff);
	        printf("Em porcentagem, quanto voce consegue ganhar\n");
	        scanf("%f", &taxaUsuario);                 
	        
	        while( massa < pesoIdeal){
	             result = massa * (taxaUsuario/100);
	             massa = massa + result;               
	             imc = massa / (pow(altura, 2));
	             mes++;
	             printf("Sua massa eh %.2f, seu IMC: %.2f, em %d\n", massa, imc, mes);
	        }
	    }
	          
    } else {
    	printf("Voce esta entre o IMC ideal. Seu IMC eh %.2f\n", imc);
    }

    system("pause");
    return 0;
    
}

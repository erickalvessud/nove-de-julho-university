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
    float massaIdeal = 0;
    float massaDiff = 0;
    // meses que o usuario precisa para perder ou ganhar peso para chegar ao seu peso ideal.
    int mes = 0;
    
    float ideal = 0;
    
    printf("Calcular o IMC\n\n");
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
          	massaIdeal = 18.5 * (pow(altura, 2));
                
       	} else {
         	// ele acima do peso    
          	massaIdeal = 24.99 * (pow(altura, 2));         
       	}

       	massaDiff = massa - massaIdeal;
	   	
	   	if (massaDiff > 0){
			printf("Para sua altura, seu peso ideal eh %.2f Voce precisa perder: %.2fkg\n", massaIdeal, massaDiff);
	        printf("Quantos por cento voce consegue perder por mes?\n");
	        scanf("%f", &taxaUsuario); 
		} else {
			printf("Seu peso ideal eh %.2f Voce precisa ganhar: %.2f\n", massaIdeal, (massaDiff * -1)); // multiplico por -1 para tirar o sinal negativo
	        printf("Quantos por cento voce consegue ganhar por mes?\n");
	        scanf("%f", &taxaUsuario);
		}
	   
	   	float result = 0;
		
		// simplifiquei colocando apenas um laco de repeticao.
		// se o diferenca entre a massa atual e a massa normal for positivo E a massa atual for maior que a massa ideal OU se a diferenca entre a massa atual e a massa normal for negativa e a massa atual for menor que a massa ideal, continua o laco.
		// Quando essa condicao nao for mais satisfeita, ele termina a iteracao do laco.
		while ( (massaDiff > 0 && massa > massaIdeal) || (massaDiff < 0 && massa < massaIdeal)){
			
			// descobrir o resultado da porcentagem sobre a massa atual.
			result = massa * (taxaUsuario/100);
			
			if (massaDiff > 0){
				// diminue da massa atual a porcentagem encontrada
				massa = massa - result;
			} else {
				// aumenta da massa atual a porcentagem encontrada
				massa = massa + result;
			}
			// calcula para saber o novo IMC da massa nova.
			imc = massa / (pow(altura, 2));
			
			// incrementa o contador de meses
	        mes++;
	        
			printf("No %d mes, sua massa sera %.2f, seu IMC: %.2f\n", mes, massa, imc);
		}
		
	    /*	
	    //logica antiga
	    
	    	printf("Para sua altura, seu peso ideal eh %.2f Voce precisa perder: %.2fkg\n", massaIdeal, massaDiff);
	        printf("Em porcentagem, quanto voce consegue perder\n");
	        scanf("%f", &taxaUsuario);                 
	        
	        while( massa > massaIdeal){
	             result = massa * (taxaUsuario/100);
	             massa = massa - result;
	             imc = massa / (pow(altura, 2));
	             mes++;
	             
	             printf("Sua massa eh %.2f, seu IMC: %.2f, em %d\n", massa, imc, mes);
	        }
	    } else {
	    	
			printf("Seu peso ideal eh %.2f Voce precisa ganhar: %.2f\n", massaIdeal, massaDiff);
	        printf("Em porcentagem, quanto voce consegue ganhar\n");
	        scanf("%f", &taxaUsuario);                 
	        
	        while( massa < massaIdeal){
	             result = massa * (taxaUsuario/100);
	             massa = massa + result;               
	             imc = massa / (pow(altura, 2));
	             mes++;
	             printf("Sua massa eh %.2f, seu IMC: %.2f, em %d\n", massa, imc, mes);
	        }
	    }
	    */
    } else {
    	printf("Voce esta entre o IMC ideal. Seu IMC eh %.2f\n", imc);
    }

    system("pause");
    return 0;
    
}

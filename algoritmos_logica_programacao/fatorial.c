#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int fatorial = 1;
    
    int i = 1;
    int result = 1;
    
	printf("Representacao do valor de um fatorial\n");
	printf("Digite um numero fatorial:\n");
	scanf("%d", &fatorial);
    
    while(i <= fatorial){
        
        result = result * i;
        i++;        
    }
    
    printf("Fatorial de %d! eh: %d \n", fatorial, result);
    
    system("pause");
    return 0;
}


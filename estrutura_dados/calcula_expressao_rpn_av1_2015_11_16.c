#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define TOPO_LINHA 200
#define TOPO_COLUNA 200

double pilhaResultado[200];
int topoPilhaResultado = -1;

char pilhaSaidaRPN[TOPO_LINHA][TOPO_COLUNA];
int topoLinPilhaSaida = 0;
int topoColPilhaSaida = 0;

char pilhaOperadores[200];
int topoPilhaOperadores = -1;

/** Declaracoes das funcoes do sistema **/

/* 
 * Funcao que transforma uma expressao
 * Infixa em Notacao Polonesa Inversao
 */
void notacaoInfixaToRPN(char expressao[] );

double calculaExpressao();

/*
 * Calcula dois numeros pelo operador passado como parametro.
 */
double calculaElementos(double numero1, double numero2, char operador);

/*
 * Empilha um numero na pilha de resultados.
 */
void empilharResultado(double numero);

/*
 * Desempilha um numero da pilha de resultados.
 */
double desempilharResultado();

/*
 * Empilha elementos na pilha de saida.
 */
void empilharNaPilhaSaida(char elemnto);

/*
 * Avanca uma posicao na linha da pilha de saida.
 */
void proximaLinhaDaPilhaSaida();

/*
 * Empilha elementos na pilha de operadores.
 */
void empilharNaPilhaOperadores(char elemento);

/*
 * Dempilha elementos na pilha de operadores.
 */
char desempilhaDaPilhaOperadores();

/** funcoes de validacao **/

/*
 * Retorna um valor menos um (-1), se o primeiro argumento 
 * for menor que o segundo argumento,
 * ou 0 se ambos forem iguais ou um (1) se o primeiro argumento for maior que o segundo argumento.
 * Operadores de multiplicacao (*) e divisao (/) possuem mesma precedencia e tem maior precedencia 
 * sobre soma (+) e subtracao (-). Soma (+) e subtracao (-) possuem a mesma precedencia.
 */
int comparaPrecedencias(char elemento, char elementoAnterior);

/*
 * Verifica se o caracter passado e um operador (/, *, +, -) ou nao.
 */
int ehSinal(char);

/*
 * Verifica se o caracter passado e um operador de multiplicacoo (*) ou divisao (/).
 */
int ehSinalMutiplicacaoOuDivisao(char);

/*
 * Verifica se o caracter passado e um operador de soma (+) ou subtracao (-).
 */
int ehSinalSomaOuSubtracao(char);

/*
 * Procura o indice do sinal anterior à esquerda, se houver,
 * caso nao exista, retorna o indice retornada.
 */
int getIndiceProximoSinalEsquerda(char[], int);

/*
 * Imprime o resultado de uma matriz.
 */
void printMatriz();

int menu();

/*
 * Funcao principal do sistema.
 */
int main(void){
	
	//char expressao[] = {'2','1','+','3','*','2','\0'};
	char expressao[TOPO_LINHA];
	 
	int i = 0;
	
	double resultadoFinal = 0.;
    
	for(;;){
        i = menu();
        switch(i){
             case 1: 
				  system("cls");
			      printf("Entre com uma expressão aritmetica para o programa: \n");
			      fflush(stdin);
			      gets(expressao);
                  notacaoInfixaToRPN(expressao);
                  break;
             case 2: 
                  printMatriz();
                  system("pause");
                  break;
             case 3: 
	 			  resultadoFinal = calculaExpressao();
	 			  
				  memset(pilhaSaidaRPN, 0, 255);
				   
	 			  printf("Resultado Final da Expressao: %.2f\n", resultadoFinal);	 
                  system("pause");
                  break;
             case 4:
                  exit(1);
        }
     } 
}

int menu(){
    int i;
    system("cls");
    printf("\n\t Menu\n");
    printf("\n\t1. Empilha");
    printf("\n\t2. Desempilha\n");
    printf("\t3. Calcula expressão \n");
    printf("\t4. Sair \n\n\t");
    scanf("%d", &i);
    return i;
}

double calculaExpressao(){
	int i = 0;

	 for ( i = 0; i <= topoLinPilhaSaida; i++) {
	 	
		int j = 0;
		
	 	//char elementosChar[topoColPilhaSaida];
	 	char elementosChar[TOPO_COLUNA] = {'\0'};
		
		char elemento = '\0';

	 	while ( ( elemento = elementosChar[j] = pilhaSaidaRPN[i][j] ) != '\0' ) {

	 		if ( ehSinal( elemento ) ) {
	 			
	 			double numero1 = desempilharResultado();
	 			double numero2 = desempilharResultado();
	 			
	 			double resultadoParcial = calculaElementos(numero2, numero1, elemento);
	 			
	 			empilharResultado(resultadoParcial);
			} else {
				// entra apos recuperar todos os numeros que compoem o numero final.
			 	if ( pilhaSaidaRPN[i][(j + 1)] == '\0' ) {
			 		
					int numero = atoi(elementosChar);
					
					empilharResultado(numero);
				}
			}
			j++;
		 }
	 }
	 
	 double resultadoFinal = desempilharResultado();
	 
	 return resultadoFinal;
}

double calculaElementos(double numero1, double numero2, char operador){
	
	double resultado = 0.;
	
	switch(operador) {
		case '/':
			resultado = (numero2 != 0) ? numero1 / numero2 : 0.;
			break;
		case '*':
			resultado = numero1 * numero2;
			break;
		case '+':
			resultado = numero1 + numero2;
			break;
		case '-':
			resultado = numero1 - numero2;
			break;
	}
	return resultado;
}

void empilharResultado(double numero){
	topoPilhaResultado++;
	pilhaResultado[topoPilhaResultado] = numero;
}

double desempilharResultado(){
	double resultado = 0.;
	resultado = pilhaResultado[topoPilhaResultado];
	topoPilhaResultado--;
	return resultado;
}

void notacaoInfixaToRPN(char expressao[] ){
	
	int index = 0;
	 
	char elemento = '\0';
	 
	 while ( ( elemento = expressao[index] ) != '\0') {
	 	
	 	if ( ehSinal(elemento) )  {
	 		
	 		//do {
	 		proximaLinhaDaPilhaSaida();
			
			char elementoAnterior = '\0';
			while (1) {
			
		 		elementoAnterior = desempilhaDaPilhaOperadores();
		 		
		 		if ( elementoAnterior != '\0' ) {
				 	 
					 if ( comparaPrecedencias(elemento, elementoAnterior) <= 0 ){
			 			
			 			empilharNaPilhaSaida(elementoAnterior);
			 			
			 			//empilharNaPilhaOperadores(elemento);
			 			
						proximaLinhaDaPilhaSaida();
						
						
					 } else {
					 	
					 	empilharNaPilhaOperadores(elementoAnterior);
					 	empilharNaPilhaOperadores(elemento);
					 	break;
					 }
		 		} else {
				 	empilharNaPilhaOperadores(elemento);
				 	break;
				}
		 	}
		 	
		 } else {
		 	
			 empilharNaPilhaSaida(elemento);	
		 }
	 	
	 	index++;
	 }
	 
	 char elementoOperador = '\0';
	 
	 while ( ( elementoOperador = desempilhaDaPilhaOperadores() ) != '\0' ) {
		
		proximaLinhaDaPilhaSaida(elementoOperador);
		
		empilharNaPilhaSaida(elementoOperador);
	 }
}

void empilharNaPilhaSaida(char elemento){
	pilhaSaidaRPN[topoLinPilhaSaida][topoColPilhaSaida] = elemento;
	topoColPilhaSaida++;
}

void proximaLinhaDaPilhaSaida(){
	topoLinPilhaSaida++;
	topoColPilhaSaida = 0;
}

void empilharNaPilhaOperadores(char elemento){
	topoPilhaOperadores++;
	pilhaOperadores[topoPilhaOperadores] = elemento;
}

char desempilhaDaPilhaOperadores(){
	
	char resultado = '\0';
	if( topoPilhaOperadores >= 0){
		
		resultado = pilhaOperadores[topoPilhaOperadores];
		topoPilhaOperadores--;
	}
	return resultado;
}

// comparaPrecedencia
int comparaPrecedencias(char elemento, char elementoAnterior){
	int ehIgual = 0;
	
	if ( ( ehSinalMutiplicacaoOuDivisao(elemento) && ehSinalMutiplicacaoOuDivisao(elementoAnterior) )
			||
		 (ehSinalSomaOuSubtracao(elemento) && ehSinalSomaOuSubtracao(elementoAnterior))	 
		) {
		ehIgual = 0;
	} else if ( ehSinalSomaOuSubtracao(elemento) ) {
		
		if ( ehSinalMutiplicacaoOuDivisao(elementoAnterior) ) {
			ehIgual = -1;
		}
	} else {
		ehIgual = 1;
	}
	
	return ehIgual;
}


int getIndiceProximoSinalEsquerda(char *expr, int i){
	int j = 0;
	for (j = ( i - 1 ); j >= 0; j--) {
		if (ehSinal(expr[j])) {
			// retorna o proximo sinal a esquerda
			return j;
		}
	}
	return i;
}

int ehSinal(char c){
	switch(c) {
		case '/':
		case '*':
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}

int ehSinalMutiplicacaoOuDivisao(char c){
	if (c == '*' || c == '/')
		return 1;
	return 0;
}

int ehSinalSomaOuSubtracao(char c){
	if (c == '+' || c == '-')
		return 1;
	return 0;
}

void printMatriz(){
	int i = 0;
	int j = 0;
	
	for (i = 0; i < 7; i++) {
		for ( j = 0; j < 7; j++) {
			printf("Elemento[%d][%d]: %c\n", i, j, pilhaSaidaRPN[i][j]);
		}
	}
}


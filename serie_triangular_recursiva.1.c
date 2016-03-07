#include<stdio.h>
#include<stdlib.h>

int sequenciaTriangular(int n);

int main () {
    
    int n = 0;
    printf("Insira o valor \n");
    scanf("%d", &n);
    printf("%d\n", sequenciaTriangular(n));
    system("pause");
    return 0;
}

int sequenciaTriangular(int n) {
    if(n <= 1)
         return 1;
    else
        return n + sequenciaTriangular(n - 1);
}

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
    int i, st = 0;

    for (i = 1; i <= n; i++ ) {
        st += i;
    }
    return st;
}

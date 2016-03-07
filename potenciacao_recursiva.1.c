#include<stdio.h>
#include<stdlib.h>

int pow(int b, int e);

int main() {
    int b,e = 0;
    printf("Insira o valor \n");
    scanf("%d", &b);
    scanf("%d", &e);
    printf("%d\n", pow(b, e));
    system("pause");
    return 0;
}

int pow(int b, int e){

    if( b == 1 || e == 0 )
        return 1;
    else
        return b * pow(b, e - 1);       
}


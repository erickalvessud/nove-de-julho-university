#include<stdlib.h>
#include<stdio.h>

void printList(int list[]){
    int i;
    printf("{ ");
    for (i = 0; i < 5; i++) {
        printf("%d", list[i]);
        if((i + 1) < 5){
            printf(", ");
        }
    }
    printf(" }\n");
}

void selectionSort(int numList[], int size){

    int i, j, min, temp;

    for ( i = 0; i < (size - 1); i++) {
        // assume first index is the minimus.
        min = i;

        // search to the minimal value.
        for(j = (i + 1); j < size; j++ ) {

	    // if some value is less than the minimal, change the minimal for it.
	    if ( numList[j] < numList[min] ) {
	        min = j;
            }
	}

	if (i != min) {
	    temp = numList[i];
	    numList[i] = numList[min];
	    numList[min] = temp;
	}
    }

}


int main(){

    int numList[] = {4, 2, 5, 3, 1};

    selectionSort(numList, 5);

    printList(numList);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>

/*
* Bubble sort example.
*/

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

void sortList(int nums[], int size){
//    int size = sizeof(nums)/sizeof(nums[0]);
//    printf("Size in bytes: %d\n", sizeof(nums));
//    printf("Element size: %d\n", sizeof(nums[0]));
//    printf("Size: %d\n", size);
    int i, j, temp;

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            printf("nums[%d] (%d) > nums[%d] (%d) = %s\n", i, nums[i], j, nums[j], ((nums[i] > nums[j])?"true":"false") );
            if(nums[i] > nums[j]){
                printf("Changing number %d from pos %d to pos %d\n", nums[i], i, j);
                printf("And number %d from pos %d to pos %d\n", nums[j], j, i);
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                printf("Parcial result:\n");
                printList(nums);
                printf("\n");
            } else {
                printf("Nothing to do.\n\n");
            }
        }

    }
}

int main(void){

    int numsUnsorted[] = { 4, 1, 3, 5, 2};
    int numsSorted[5];
//printf("Size in bytes: %d\n", sizeof(numsUnsorted));
//printf("Size in bytes: %d\n", sizeof(numsSorted));
    int i;

    printf("Bubble Sort exemple!\n\nInicial list\n");

    printList(numsUnsorted);

    printf("\nProcessing...\n");
    sortList(numsUnsorted, 5);

    printf("Finish!\n\nSorted elements:\n");

    printList(numsUnsorted);
    return 0;
}


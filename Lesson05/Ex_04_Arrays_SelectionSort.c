#include <stdio.h>

void selectionSort(int array[], int size) {

    int n = 10;    
    int min_index;
    for(int i = 0; i < n - 1; i++) {
        min_index = i;
        for(int j = i + 1; j < n; j++) {
            if(array[min_index] > array[j]) {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }

    printf("Sorted Array:\n");
    for(int i = 0; i < n; i++)  {
        printf("%d", array[i]);
    }
    printf("\n");

}

int main(int argc, char* argv[]) {

    int array[] = {3,2,6,5,4,7,8,9,5,1};
    int arrayLength = sizeof(array)/sizeof(array[0]);

    selectionSort(array, arrayLength);

}


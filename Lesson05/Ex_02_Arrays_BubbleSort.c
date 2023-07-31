#include <stdio.h>

void bubbleSortHighestToLowest(int array[], int size) {
    int current;
    for(int i = 0; i < size; i++) {
        // {50, 28, 98, 30, 40}; 
        for(int j = 1; j < size; j++){
            if(array[j - 1] < array[j]) {
                current = array[j - 1];
                array[j - 1] = array[j];
                array[j] = current;

                // printf("\nSwapped | %d | on index | %d | with | %d | on index | %d |\n", array[i], i, array[j], j );

                }  
            }

        }
        
    }

void bubbleSortLowestToHighest(int array[], int size) {

    int current;

    for(int i = 0; i < size; i++) {
        // {50, 28, 98, 30, 40}; 
        for(int j = 1; j < size; j++) {

            if(array[j - 1] > array[j]) {
                current = array[j - 1];
                array[j - 1] = array[j];
                array[j] = current;
            }

        }
    }

}

void printArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("\nIndex: | %d |, value [ %d ]\n", i, array[i]);
    }
}


int main(int argc, char* argv[]) {

    int array[5] = {50, 28, 98, 30, 40}; 
    int arrayLength = sizeof(array)/sizeof(array[0]);

    bubbleSortHighestToLowest(array, arrayLength);

    printf("\nBubblesort highest to lowest : \n");
    printArray(array, arrayLength);
    printf("\n==============================\n\n");

    printf("\nBubblesort lowest to highest : \n");
    bubbleSortLowestToHighest(array, arrayLength);
    printArray(array, arrayLength);

    // printf("\nBubblesort highest to lowest using while : \n");
    // bubbleSortHighestToLowestUsingWhile(array, arrayLength);
    // printArray(array, arrayLength);


}
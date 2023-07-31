#include <stdio.h>

void linearSearching(int array[], int key, int size) {

    for(int i = 0; i < size; i++) {
        if(array[i] != key) {
            printf("The number: | %d | is not equal to our key : | %d |\n", array[i], key );
            array[i + 1];
        } else {
            printf("\nThe element equal to our key is : | %d |\n ", array[i]);
            break;
        }
    }

}

int main(int argc, char* argv[]) {

    int key = 30;
    int array[5] = {50, 28, 98, 30, 40}; 
    int arrayLength = sizeof(array)/sizeof(array[0]);

    linearSearching(array, key, arrayLength);






}
#include <stdio.h>

void invertArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // Swap elements at start and end positions
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move the start and end positions towards the middle
        start++;
        end--;
    }
}

int main() {
    int myArray[5] = {39, 81, 83, 93, 60};
    int arrayLength = sizeof(myArray) / sizeof(myArray[0]);

    printf("Original array: ");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", myArray[i]);
    }

    invertArray(myArray, arrayLength);

    printf("\nInverted array: ");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", myArray[i]);
    }

    printf("\n");

    return 0;
}


/*

    gcc Ex_06_Arrays_3.c -o buildEx06Arrays3

    ./buildEx06Arrays3

*/
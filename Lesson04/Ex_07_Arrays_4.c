#include <stdio.h>

    int printElementOnOffset(int *ptr, int offset) {
        int *newPtr = ptr + offset;
        return *newPtr;

    }



int main(int argc, char* argv[]) {

    int myArray[5] = {1, 2, 3, 4, 5};

    int *arrayPtr = myArray;

    int offset = 2;

    int value = printElementOnOffset(arrayPtr, offset);

    printf("Value of arr[%d] = %d \n", offset, *(arrayPtr + offset));
}

/*

    gcc Ex_07_Arrays_4.c -o buildEx07Arrays4

    ./buildEx07Arrays4

*/
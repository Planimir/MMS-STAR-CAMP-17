#include <stdio.h>

int main(int argc, char* argv) {

    

    int myArray1[5] = {15, 28, 33, 45, 50};
    int arrOneLength = sizeof(myArray1)/sizeof(myArray1[0]);

    int myArray2[] = {15, 28, 33, 45, 50, 95, 80};
    int arrTwoLength = sizeof(myArray2)/sizeof(myArray2[0]);

    for(int i = 0; i < arrOneLength ; i++){
        printf("Element in row | %d |, value | %d | \n" , i, myArray1[i]);
    }

    for(int i = 0; i < arrTwoLength ; i++){
        printf("\nElement in row | %d |, value | %d | \n" , i, myArray2[i]);
    }




    return 0;
} 

/*

    gcc Ex_04_Arrays_1.c -o buildEx04Arrays1

    ./buildEx04Arrays1

*/
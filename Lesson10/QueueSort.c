#include <stdio.h>
#include<stdlib.h>

typedef struct Point {
    double x;
    double y;
}P;


int cmpfunc_descending(const void *a, const void *b) {

    // checks if they are negative or positive.
   return ( *(int*)a - *(int*)b );
   // in order to change from descending to ascending - > replace a and b's places.

}

int cmpfunc_ascending (const void *a, const void *b) {

    // checks if they are negative or positive.
   return ( *(int*)b - *(int*)a );
   // in order to change from descending to ascending - > replace a and b's places.

}

int main(int argc, char* argv) {

    size_t i = 0;

    int arr[] = {4, 5, -10, 15, 31, 22, 45, 1};

    int arrLength = sizeof(arr) / (arr[0]);

    printf("\nBefore qsort() :\n");
    for(i = 0; i < arrLength; i++) {
        printf(" %d", arr[i]);
    }

    qsort(arr, arrLength, sizeof(int), cmpfunc_descending);

    printf("\n Descending qsort() :\n");
    for(i = 0; i < arrLength; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

        qsort(arr, arrLength, sizeof(int), cmpfunc_ascending);

    printf("\nAscending qsort() :\n");
    for(i = 0; i < arrLength; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");


}
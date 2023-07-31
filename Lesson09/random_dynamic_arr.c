#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int* genRandom(size_t elem_c) {
    int *arr = malloc(sizeof(int)*elem_c);
    for(size_t i = 0; i < elem_c; i++) {
        arr[i] = -100 + rand()%200;
        //      [-100, 99]
        // rand()%100  === 0-99
        // rand()%200  === 0-199
        // rand()%100 - 100 === -100-0
        // *(arr + i) = ...
    }
    return arr;
}
int main() {
    // srand(55);
    srand(time(NULL));
    int* arr = genRandom(30);
    for(size_t i = 0; i < 30; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
}
#include <stdio.h>
#include <stddef.h>

int isPositive(int a);

int addOne(int a);

void filter_and_map( const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t* dest_cnt);

int main() {
    int arr[8] = {1, 2, 3, 4, -1, -2, 11, -100};
    int dest[10];
    size_t new_size;

    filter_and_map(arr, 8, isPositive, addOne, dest, &new_size);

    printf("new_size = %zu\n", new_size);
    printf("dest = {");
    for (size_t i = 0; i < new_size; i++) {
        printf("%d", dest[i]);
        if (i < new_size - 1) {
        printf(", ");
        }
    }
    printf("}\n");

    return 0;
}

int isPositive(int a) {
    return a > 0 ? 1 : 0;
}

int addOne(int a) {
    return a + 1;
}

void filter_and_map( const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t* dest_cnt) {

    if (!dest) {
        return;
    }

    size_t count = 0;

 
    for (size_t i = 0; i < n; i++) {
        if (filter_f(arr[i])) { 
            dest[count] = map_f(arr[i]); 
            count++;
        }
    }

    *dest_cnt = count;
}

/*
    gcc -std=c11 -o task3 task3.c -Wall -Wextra

    ./task3

*/
#include <stdio.h>

int isEven(int a); 

int isPrime(int a);

int square(int a);

int countBits(int a);

void filter_and_map( const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t* dest_cnt);


int main() {

    // Print only the even numbers from an array:
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int dest1[10];
    size_t size1;
    filter_and_map(arr1, 10, isEven, NULL, dest1, &size1);  // No map function; just filter.
    for (size_t i = 0; i < size1; i++) {
        printf("%d ", dest1[i]);
    }
    printf("\n");


    // To find the square of only the prime numbers from an array:
    // int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int dest2[10];
    // size_t size2;
    // filter_and_map(arr2, 10, isPrime, square, dest2, &size2);
    // for (size_t i = 0; i < size2; i++) {
    //     printf("%d ", dest2[i]);
    // }
    // printf("\n");


    // Find the number of bits that are 1 only for the positive elements of an array:
    // int arr3[] = {15, -5, 8, -12, 3, -1};
    // int dest3[6];
    // size_t size3;
    // filter_and_map(arr3, 6, isPositive, countBits, dest3, &size3);
    // for (size_t i = 0; i < size3; i++) {
    //     printf("%d ", dest3[i]);
    // }
    // printf("\n");

    
    return 0;
}


int isEven(int a) {
    return a % 2 == 0 ? 1 : 0;
}

int isPrime(int a) {
    if (a < 2) return 0;
    for (int i = 2; i <= a / 2; i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

int square(int a) {
    return a * a;
}

int countBits(int a) {
    int count = 0;
    while (a) {
        count += a & 1;
        a >>= 1;
    }
    return count;
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
    gcc -std=c11 -o task4 task4.c -Wall -Wextra

    ./task4

*/
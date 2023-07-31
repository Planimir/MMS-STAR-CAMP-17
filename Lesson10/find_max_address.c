#include <stdio.h>

void find_max_addr(int arr[], size_t n, int *max_elem);

void find_max_ptr(int arr[], size_t n, int *max_elem, int **max_ptr);



int main(int argc, char *argv[]) {

    int arr[] = {1, 2, -5, 100, 12, 3};

    int *ptr;
    int *max_ptr;
    int max_elem;

    find_max_ptr(arr, 6, &max_elem, &max_ptr);

    printf("MAX VALUE : %d\n", max_elem);
    printf("MAX VALUE : %p\n", max_ptr);


}


void find_max_addr(int arr[], size_t n, int *max_elem) {

    int MAX = arr[0];
    for(size_t i = 1; i < n; i++) {
        if(arr[i] > MAX) {
            MAX = arr[i];
        }
    }

    *max_elem = MAX;

}

void find_max_ptr(int arr[], size_t n, int *max_elem, int **max_ptr) {

    int MAX = arr[0];
    for(size_t i = 1; i < n; i++) {
        if(arr[i] > *max_elem) {
            *max_elem = arr[i];
            *max_ptr = arr  + i;
        }
    }

    *max_elem = MAX;

}

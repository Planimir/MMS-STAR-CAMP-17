#include<stdio.h>
#include<stdlib.h>
void* genArray(void (*init_elem)(void*), size_t elem_c, size_t elem_size) {
    void *arr = malloc(elem_c*elem_size);
    //адресът на ел. 0: arr
    //адресът на ел. 1: (char*)arr+elemSize
    //адресът на ел. 2: (char*)arr+2*elemSize
    //адресът на ел. 3: (char*)arr+3*elemSize
    for(size_t i = 0; i < elem_c; i++) {
        printf("Calling function init_elem with address: %p\n", (char*)arr + i*elem_size);
        init_elem((char*)arr + i*elem_size);
    }
    return arr;
}

void init_int_to_100(void* ptr) {
    int *int_ptr = (int*)ptr;
    *int_ptr = 100;
}
void init_double_to_random(void* ptr) {
    *((double*)ptr) = (rand()%200000 - 100000)/1000.;
}
int main() {
    int *arr = genArray(init_int_to_100, 33, sizeof(int));
    for(size_t i = 0; i < 33; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);

    double *arr2 = genArray(init_double_to_random, 10, sizeof(double));
    for(size_t i = 0; i < 10; i++) {
        printf("%f ", arr2[i]);
    }
    printf("\n");
    free(arr2);
    return 0;
}
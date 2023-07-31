#include <stdio.h>
#include <string.h>
#include <inttypes.h>

int main() {

    double a = 3.141516;   
    uint64_t b;

    // &b - the address of the destined variable to get the value.
    // &a - the address of the variable, from which we are getting the data
    // 8 - the bits

    printf("\n");
    memcpy(&b, &a, 8);
    for(size_t i = 64; i >= 1; i--) {
        printf("%d", !!(b & (1ULL << (i - 1))));
    }
    printf("\n");
    b = b & ~(1ULL<<63);
    for(size_t i = 64; i >= 1; i--) {
        printf("%d", !!(b & (1ULL << (i - 1))));
    }
    memcpy(&a, &b, 8);

    printf("%lf", a);

    char arr[100];
    memcpy(arr + 5, arr, 10);



}
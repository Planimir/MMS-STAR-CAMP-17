#include <stdio.h>
#include <limits.h>
#include <inttypes.h>

int main() {
    // UB access to unitialized local variable
    int a;
    a = a + 5;

    // UB: access to element outside of array bounds
    int arr[5] = {1, 2, 3, 4, 5};
    arr[5] = 2;


    // UB: derefence
    int *p = NULL;

    // A points to Integer's max value and by incrementing it, it may overflow.
    int c = INT_MAX;
    c++;

    // UB: access of object through pointer to incompatible type
    double d = 3.14159;
    uint64_t t *p1 = &d; 
    *p1 = 1; // UB 


}

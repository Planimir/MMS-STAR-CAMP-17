#include <stdio.h>
#include <string.h>

typedef struct A {
    char a; // 1 byte
    // 3 bytes padding
    int b; // 4 byte
} A;

typedef struct B {
    int a; // 4 bytes
    char b; // 1 byte
    // 3 bytes padding
} B;

typedef struct C {
    double a; // 8 bytes
    int b; // 4 bytes
    // 4 bytes padding
} C;

typedef struct D {
    char a; // 1 byte
    double b; // 8 bytes
    // 7 bytes pading
} D;

typedef struct E {

    char name[6]; // 6 bytes
    // 2 bytes padding
    double height; // 8 bytes
    short age; // 2 bytes  [-2^15 : 2^15 -1]
    // 6 bytes padding
} E;               

typedef struct F {

    char name[6];   // 6 bytes
                    // 2 bytes padding
    short age;      // 2 bytes  [-2^15 : 2^15 -1]
    double height;  // 8 bytes
    short age2;     // 2 byte

    // 6 bytes padding
} F; 
int main() {
    printf("\nSIZE OF A: %lu", sizeof(A));
    printf("\nSIZE OF A: %lu", sizeof(B));
    printf("\nSIZE OF A: %lu", sizeof(C));
    printf("\nSIZE OF A: %lu", sizeof(D));
    printf("\nSIZE OF A: %lu", sizeof(E));


    
    return 0;
}
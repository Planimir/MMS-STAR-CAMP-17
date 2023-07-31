#include<stdio.h>
#include<inttypes.h>
typedef union A {
    double a;
    uint64_t b;
} A;
int main() {
    A union1;
    union1.a = 3.14;
    printf("%lf\n", union1.a);
    printf("%lu\n", union1.b);
}
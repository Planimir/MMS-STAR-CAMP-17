#include<stdio.h>
int* f() {
    static int a;
    printf("%d\n", a);
    return &a;
}
int main() {
    int *p = f();
    *p = *p + 10;
    *p = *p + 10;
    f();
    return 0;
}
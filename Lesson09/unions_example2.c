#include<stdio.h>
struct Point3D{
    double x;
    double y;
    double z;
} p1;
struct A {
    char a; //1 byte
    //3 bytes padding
    int b;  // 4 byte
};
struct B {
    int a;
    char b;
    // 3 bytes padding
};
typedef union C {
    int a;
    float b;
    char a;
} C;
int main() {
    printf("%lu", sizeof(C));
    return 0;
}
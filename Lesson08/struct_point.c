#include <stdio.h>

typedef struct Point {
    double x; // 8 byte-a
    double y; // 8 byte-a

} P;

// *p сочи към началото където е запаметена структурата Point.

//Pass argument by pointer
void print(P *p) {
    double *x_p = p;
    printf("%p %p\n", x_p, p);
    printf("%lf", *x_p);
    printf("%lf", p->y);

}

// Pass argument by value
void print2(P p) {
    double *x_p = p;    
    printf("%lf %lf\n", p.x, p.y);

}

int main() {
    P p1 = { 2.8, 2.9};
//  -----------################----------------------
//             ^
//            &p1      

    sizeof(P); // 16 bytes 
    print(&p1);
}
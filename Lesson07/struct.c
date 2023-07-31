#include <stdio.h>

typedef struct Point {
    double x;
    double y;
} P;

typedef struct  {

    int houseNumber;
    char streetName[30];
    char *residenName[10];
    P coordinates;
    // void (*f)(int, int);
    int arr[];

} ADR;

int main() {

    P a;
    a.x = 15.6;
    a.y = 18.9;

    printf("%lf\n", a.x);
    printf("%lf\n", a.y);

    P b = {30.2, 45.1};
    printf("%lf\n", b.x);
    printf("%lf\n", b.y);

    P c = {
        .x = 39.2,
        .y = 49.5
    };

    printf("%lf\n", c.x);
    printf("%lf\n", c.y);

    char name1[] = "Ivan";
    char name2[] = "Gosho";
    ADR adr1 = {
        120,
        "Cherni Vrah",
        {name1, name2},
        {
            .x = 22.5,
            .y = 100.5
        }

    };

    ADR *p1 = &adr1;
    printf("Longitude: %lf\n", (*p1).coordinates.x);
    printf("Longitude: %lf\n", p1->coordinates.x);


    return 0;
}
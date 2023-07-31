#include <stdio.h>
#include <math.h>

int triangle(double a, double b, double c, double* area, double* perimeter);

int main(int argc, char* argv[]) {

    double a, b, c, area, perimeter;
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        if(triangle(a, b, c, &area, &perimeter) == - 1) {
            printf("Invalid input\n");
        } else {
            printf("Area : %lf\n Perimeter: %lf\n", area, perimeter);
            return 1;
        }
    }


    triangle(a, b, c, &area, &perimeter) == 0;
    printf("Perimeter = %f\n", perimeter);
    printf("Area = %f\n", area);
    
    return 0;
}

// A - лице
// perimeter - сбор
int triangle(double a, double b, double c, double *area, double *perimeter) {
    // Проверяваме дали има актуален триъгълник.
    if(a <= 0 || b <= 0 || c <= 0 || (a+b <= c) || (a+c <= b) || (b+c <= a)) {
        printf("Invalid sides, cannot form a triangle.\n");
        return 1;
    }
    
    // Смятаме и запазваме периметъра
    *perimeter = a + b + c;

    // Смятаме и запазваме половината на параметъра
    double HP = *perimeter / 2;
    
    // Смятаме лицето 
    *area = sqrt(HP * (HP - a) * (HP - b) * (HP - c));

    return 0;
}
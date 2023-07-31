#include <stdio.h>
#include <math.h>

int triangle(double a, double b, double c, double* area, double* perimeter);

int main(int argc, char* argv[]) {

    double a, b, c, area, perimeter;
    a = 3.0;
    b = 4.0;
    c = 5.0;


    triangle(a, b, c, &area, &perimeter) == 0;
    printf("Perimeter = %f\n", perimeter);
    printf("Area = %f\n", area);
    
    return 0;
}

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
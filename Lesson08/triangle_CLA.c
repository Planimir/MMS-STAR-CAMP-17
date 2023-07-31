#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
FILE *stdout, *stderr, stdi;

stdout - стандартния изход
stderr - стандартния изход за грешки
stdin  - стандартния вход
*/

int triangle(double a, double b, double c, double *area, double *perimeter);

// ./triangle 1.2 3.5 7.8

// char** argv == char* argv[]
int main(int argc, char* argv[]) {

    if(argc != 4) {
        // check stderr in the man libraries.
        fprintf(stderr, "Invalid number of arguments\n");
        return 1;
    }

    // if we write ./triangle asdf it won't understand if we have given it the wrong value.
    double a = atof(argv[1]),
    b = atof(argv[2]),
    c = atof(argv[3]); // check in the man libraries.
    printf("%lf %lf %lf", a, b, c);

    double P, A;
    if(triangle(a, b, c, &P, &A) == -1) {
        fprintf(stdout, "Invalid input\n");
    } else {
        fprintf(stdout, "\nAREA: %lf\nPerimeter: %lf\n", A, P);
    }

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
#include <stdio.h>
#include "my_math_converter.h"

int main(int argc, char* argv[]) {

    double fahrenheit;
    printf("\nEnter the temperature in fahrenheit : \n");
    scanf("%lf", &fahrenheit);

    fahrenheitToCelsiusConverter(fahrenheit);

    return 0;
}

/*

gcc my_main_converter.c my_math_converter.c -lm -o linkedProgram

./linkedProgram

*/
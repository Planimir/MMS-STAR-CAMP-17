#include <stdio.h>
#include "my_math.h"

int main(int argc, char* argv[]) {

    double num = 5.25;

    double squareResult = square(num);
    double cubeResult = cube(num);
    
    printf("The square of %.2f if %.2f\n", num, squareResult);
    printf("The cube of %.2f if %.2f\n", num, cubeResult);

    return 0;
}


/*
1 row

gcc my_main.c my_math.c -lm -o linkedProgram -Wall -Wextra -Werror


OR

by linker :

gcc -c my.math_c -o my_math.o
gcc -c my.main.c -o my_main.o
gcc my_main.o my_math.o -lm -o program

*/
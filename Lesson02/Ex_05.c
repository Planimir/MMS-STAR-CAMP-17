#include <stdio.h>
#include <math.h>


int main(int argc, char* argv[]) {

    int number = 347;
    int current;
    int bit;

    while(number > 0) {
        current = number;
        number /= 2;
        bit = current % 2;
        printf("\nNumber : %d / 2 = %d ( %d ) \n", current, number, bit);
    }


    return 0;
}
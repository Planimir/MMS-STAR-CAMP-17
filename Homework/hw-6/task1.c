#include <stdio.h>

double abs_diff(double a, double b);

double mySqrt(double number, double threshold);

int main() {
    printf("%f\n", mySqrt(25, 0.0001));
    printf("%f\n", mySqrt(2, 0.0001));

    return 0;
}

double abs_diff(double a, double b) {
    double diff = a - b;
    return diff < 0 ? -diff : diff;
}

double mySqrt(double number, double threshold) {
    if (number < 0) {
        printf("Cannot compute the square root of a negative number\n");
        return -1;
    }
    
    if (number == 0 || number == 1) {
        return number;
    }

    double guess = number / 2.0;
    double previous_guess = 0;

    while (abs_diff(guess, previous_guess) > threshold) {
        previous_guess = guess;
        guess = (guess + number / guess) / 2.0;
    }

    return guess;
}


/*

    gcc -std=c11 -o task1 task1.c

    ./task1


*/
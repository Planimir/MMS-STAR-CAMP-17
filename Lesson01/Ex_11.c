#include <stdio.h>

int main(void) {

    double num1, num2, num3, average;
    
    printf("\nEnter first number: \n");
    scanf("%lf", &num1);
    printf("\nEnter second number: \n");
    scanf("%lf", &num2);
    printf("\nEnter third number: \n");
    scanf("%lf", &num3);

    average = (num1 + num2 + num3) / 3;
    printf("The average number of the sum of %lf, %lf and %lf is equal to : %lf", num1, num2, num3, average);

    return 0;
}
#include <stdio.h>

int main(int argc, char* argv[]) {

    int number;
    int calculatedNumber = number % 2;
    printf("Entser your number: \n");
    scanf("%d", &number);

    if(number % 2 == 0) {

        printf("Remaining number : | %d |, so the number is even", calculatedNumber);

    } else {

        printf("Remaining number : | %d |, so the number is uneven", calculatedNumber);
        
    }

}



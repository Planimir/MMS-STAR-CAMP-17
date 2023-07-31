#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {

    int number = 347;
    int base = 10;
    int result = 0; 
    int placeValue = 0; // stepenen pokazatel

    while(number > 0) {
        int digit = number % 10;
        result += digit * pow(base, placeValue);
        placeValue++; 
        number /= 10;
        printf("\n%d\n", number);
    }

    return 0;
}
#include <stdio.h>



int main(int argc, char* argv[]){

    int myBinary = 0b1011; // 11 in decimal
    int myOctal = 031; // 25 in decimal
    int myHex = 0xA5; // 16^1 * A (10) + 16^0 * 5 = 160 + 5 = 165 

    printf("\nBinary number: %d", myBinary);
    printf("\nOctal number: %d", myOctal);
    printf("\nHex number: %d\n", myHex);

    return 0;
}
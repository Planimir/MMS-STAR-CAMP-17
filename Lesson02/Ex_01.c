#include <stdio.h>

int main(int argc, char* argv[]) {
    char myChar = 'a';
    int myInt = 42;
    float myFloat = 3.14;
    double myDouble = 3.14159265359;
    _Bool myBool = 1;
    // reduce the boilerplate.
    printf("myChar: %c\n", myChar);
    printf("myInt: %d\n", myInt); 
    printf("myFloat: %f\n", myFloat); 
    printf("myDouble: %lf\n", myDouble); 
    printf("myBool: %d\n", myBool);


    // binary numeric system

    int myBinary = 0b1011;
    printf("Binary number: %d\n", myBinary);

    int octalNumberOne = 031;
    int octalNumberTwo = 31;
    printf("Octal number one: %d\n", octalNumberOne);
    printf("Octal number two: %d\n", octalNumberTwo);
    return 0;
}
 


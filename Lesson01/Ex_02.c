#include <stdio.h>

// Prototype of the function square
int square(int num);

int main(int argc, char* argv[]) {

    

// int num = 5;
// int result = square(num);
// printf("\n%d squared equals to : %d\n\n", num, result);

int num;

scanf("%d", &num);

int result = square(num);
printf("\n%d squared equals to : %d\n", num, result);


}

// Declaration and Definition of the function
int square(int num) {

    return num * num;
}
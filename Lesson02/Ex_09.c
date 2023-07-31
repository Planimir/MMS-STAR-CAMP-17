#include <stdio.h>

int main(int argc, char* argv[]) {
    
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;

    if ( a == 1 && b == 2 && c == 3 && d == 4) {

        printf("\nAll are correct.\n");
    } else {

        printf("\nNot all of them are correct.\n");
    }

    if ( a == 1 || b == 3 || c == 4 || d == 5 ) { 

        printf("\nOne of them is correct and thats enough.\n");
    } else {

        printf("\nNot even one of them is correct.\n");
    }


/*

int a = 1;
int b = 2;

1*2^0 = 1*1 = 1
a = 000 000 01
 
1*2^1 = 1*2 = 2

01 + 10  = 11

1*2^0 + 1*2^1 = 1*1 + 1*2 = 1 + 2 = 3; ( in decimal )
b = 000 000 10
*/

    int result = a ^ b;
    printf("%d", result);

    return 0;
}

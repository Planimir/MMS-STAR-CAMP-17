#include <stdio.h>

int fact_for(int size);
int fact_rec(int size);

int main(int argc, char* argv) {

    printf("Factorial by FOR: ");
    printf("%d\n", fact_for(5));
    

    printf("Factorial by RECURSION: ");
    printf("%d\n", fact_rec(5));

 }

 int fact_for(int size) {

    int result = 1;

    for(int i = 1; i <= size; i++) {
        
        result *= i;

    }

    return result;
 }

 int fact_rec(int size) {

    if(size == 0 || size == 1) {
        return 1;
    } else {

        return size * fact_rec(size-1);
    }
 }

 
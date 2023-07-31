#include <stdio.h>

int main(int argc, char* argv[]) {

    // we create pointer pc and variable c
    int *pc, c;

    // setting variable c's value to be 22
    c = 22;

    printf("\nAddress of c: %p", &c);
    printf("\nValue of c: %d", c);
    
    // // Now, pc holds the memory address of the variable c.
    // It means that pc "points to" the memory location where the value of c (22 in this case) is stored.

    pc = &c;

    printf("\nAddress of pc: %p", &pc);
    printf("\nContent of pc: %d", *pc);

    c = 11 ;

    printf("\nAddress of pc: %p", &pc);
    printf("\nContent of pc: %d", *pc);


    // we change c's value because *pc gets c's address 
    // and when we change *pc's value, we change c's value as well.
    *pc = 7;

    printf("\nAddress of c: %p", &c);
    printf("\nValue of c: %d\n", c);


    // Mistakes which we often make :

    // pc is an address, but c isn't.
    
    // pc = 7;
    // pc = c;

    // &c is an address, but *pc
}


/*

    gcc Ex_02_Pointer_2.c -o buildEx02Pointer2

    ./buildEx02Pointer2


*/
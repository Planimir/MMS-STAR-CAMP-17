#include <stdio.h>

int main(int argc, char* argv[]) {

    int num = 10;
    int *ptr = &num;

    printf("\nNumber ( Value ): %d", num);

    printf("\nPointer ( Address ): %p\n", ptr);

    int num2 = *ptr;
    printf("\nValue ( pointer value ): %d\n", num2);


    // check if by setting the variable num2's value from the pointer *ptr, is equal to num,
    // which *ptr points to its address, taking its value.
    if(num2 == num) {

        printf("Value: %d Num: %d, they are equal. \n", num2, num);
    }

    // change num's value by refering to *ptr.
    printf("\nNum old value: %d\n", num);
    *ptr = 20;
    printf("Num new value: %d\n", num);


    
}



/*

    gcc Ex_01_Pointer_1.c -o buildEx01Pointer1

    ./buildEx01Pointer1


*/
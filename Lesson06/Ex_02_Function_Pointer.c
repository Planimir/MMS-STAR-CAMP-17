#include <stdio.h>

void printHeight(int a);

void printMsg(void (*f)(int));

int main(int argc, char* argv[]) {

    void (*f)(int) = printHeight;
    printf("\n%p\n", f);
    printf("%lu\n", sizeof(f));
    printMsg(printHeight);
    f(20);
    
    return 0;
}

void printHeight(int a) {
    printf("\nMy height is: | %d |\n", a);
}

void printMsg(void (*f)(int)) {
printf("Hello: ");
f(10);

}
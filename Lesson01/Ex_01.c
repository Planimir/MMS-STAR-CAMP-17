#include <stdio.h>

int main(void) {

    int a = 5;

    printf("\n%d\n", a);

    printf("\nEnter your name: \n");
    char name[20];
    scanf("\n%s", name);
    printf("Your name is: \n%s\n", name);

    return 0;
}
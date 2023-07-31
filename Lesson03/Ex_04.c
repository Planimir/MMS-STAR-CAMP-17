#include <stdio.h>

int main(int argc, char* argv[]) {

    int number;

    printf("1.Start\n2.End\n");
    scanf("%d", &number);

    switch(number) {

        case 1:
            for(int i = 0; i < 5; i++) {

                printf("\nNumber : | %d |", i);
            }
            printf("\n");
             break;
        case 2:
                printf("\nNo number printing, gg\n");
                break;
        default:
            break;
            
    }
    
}
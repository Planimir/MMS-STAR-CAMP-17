#include <stdio.h>

int main(int argc, char* argv[]) {

    int choice;
    int numbersCount;
    int cycledNumberCount = 0;

    printf("\nChoose : \n0 - even numbers\n1 - uneven numbers\n");
    scanf("%d", &choice);

    if(choice == 0) {
    printf("\nHow many numbers do you want to print out?\n");
    scanf("%d", &numbersCount);

        for(int i = 0; i < 100; i++){   

            cycledNumberCount++;
            if(cycledNumberCount < numbersCount && (i % 2 == 0)) {
                printf(" %d ", i );
                
            }
        }
    } else if(choice == 1) {
        printf("\nHow many numbers do you want to print out?\n");
        scanf("%d", &numbersCount);

        for(int i = 0; i < 100; i++){   
            
            cycledNumberCount++;
            if(cycledNumberCount < numbersCount && (i % 2 == 1)) {
                printf(" %d ", i );
                
            }
        }

    }

    return 0;

}

#include <stdio.h>

int main(int argc, char* argv[]) {

    int choice;
    int outputCount;

    printf("\n0 - Even\n1 - Uneven\n");
    scanf("%d", &choice);

    if(choice == 0) {

        printf("How many even numbers do you want to print: \n");
        scanf("%d", &outputCount);

        for(int i = 0; i < 100; i++){
            if(i % 2 == 0 && i = outputCount) {
                printf("%d\n", i);
            }
        }

    } else if(choice == 1) {

        printf("How many uneven numbers do you want to print: \n");
        scanf("%d", &outputCount);

        for(int i = 0; i < 100; i++){
            if(i % 2 == 1 && i = outputCount) {
                printf("%d\n", i);
            }
        }
    }

}



// kato napishesh 0 [chetni] ili 1 [nechetni] da ti izpishe chisla do 100 kato moje 
// da izbere kolko chisla da printira, demek ako napishe 5, samo 5 chisla pluchava
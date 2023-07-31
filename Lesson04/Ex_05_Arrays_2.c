#include <stdio.h>


int myArray[7] = {4, 5, 3, 7, 2, 3, 4};

int arrLength = sizeof(myArray)/sizeof(myArray[0]);

int current = 0;

int result = 0;

int sum = 0;

void calculateHighestToLowestNumber(int array[]) {

    int current = myArray[0];

    for(int i = 0; i < arrLength; i++){
        
        if(current > myArray[i]){

            myArray[i + 1];

        } else {
            current = myArray[i];
        } 
        
    }

    printf("\nHighest number: | %d |", current);

}

void calculateLowestToHighestNumber(int array[]) {
    int current = myArray[0];

     for(int j = 0; j < arrLength; j++){
         if(current < myArray[j]){

            myArray[j + 1];

        } else {

            current = myArray[j];

        }
    }
    
      printf("\nLowest number:  | %d |\n", current);

}

void calculateAverageSum(int array[]) {
    
    for (int i = 0; i < arrLength; i++) {
        sum += myArray[i];
    }
    
    int averageSum = (int)sum / arrLength;
    printf("Average sum of the array: | %d |\n", averageSum);
    


}

int main(int argc, char* argv[]) {

    calculateHighestToLowestNumber(myArray);

    calculateLowestToHighestNumber(myArray);

    calculateAverageSum(myArray);

      
}

/*

    gcc Ex_05_Arrays_2.c -o buildEx05Arrays2

    ./buildEx05Arrays2

*/
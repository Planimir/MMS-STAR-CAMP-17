#include <stdio.h>

void mergeSorted(int *arr1, int sizeArr1, int *arr2, int sizeArr2, int *dest);

void merge(int *arr1, int sizeArr1, int *arr2, int sizeArr2, int *dest);

int main(int argc, char* argv[]) {

    int arr1[] = {1, 5 ,6};
    int arr1Size = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {1, 3, 5, 7, 8, 10, 14};
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]);

    int dest[10];
    int destSize = sizeof(dest) / sizeof(dest[0]);

    mergeSorted(arr1, arr1Size, arr2, arr2Size, dest);

    for(int i = 0; i < destSize ; i++) {
        printf(" %d ", dest[i]);
    }

    // printDestArr(dest, destSize);


    // second way to do it :


    int arr3[] = {1, 5, 8};
    int sizeArr3 = sizeof(arr3) / sizeof(arr3[0]);
    int arr4[] = {3, 5, 10, 14};
    int sizeArr4 = sizeof(arr4) / sizeof(arr4[0]);
    int dest2[20];

    merge(arr3, sizeArr3, arr4, sizeArr4, dest2);

    printf("\n\n");
    for(size_t i = 0; i < 7; i++) {
        printf(" %d ", dest2[i]);
    }


}



/*
int *arr1 - > first array
int *arr2 - > second array
int sizeArr1 - > size of arr1
int sizeArr2 - > size of arr2
int dest - > the end product of both arrays ( its also an array )
*/
// arr1 and arr2 are merged.

// void printDestArr(int *dest, int sizeOfDest) {

//     for(int i = 0; i < sizeOfDest ; i++) {
//         printf("%d", dest[i]);
//     }
// }

void mergeSorted(int *arr1, int sizeArr1, int *arr2, int sizeArr2, int *dest) {
    int i = 0, j = 0, k = 0;

    // Merge process similar to merge sort
    while(i < sizeArr1 && j < sizeArr2) {
        if(arr1[i] < arr2[j]) {
            dest[k++] = arr1[i++];
        } else {
            dest[k++] = arr2[j++];
        }
    }

    // If there are remaining elements in arr1
    while(i < sizeArr1) {
        dest[k++] = arr1[i++];
    }

    // If there are remaining elements in arr2
    while(j < sizeArr2) {
        dest[k++] = arr2[j++];
    }
}


void merge(int *arr1, int sizeArr1, int *arr2, int sizeArr2, int *dest) {

    size_t i1 = 0, i2  = 0;

    while(i1 < sizeArr1 && i2 < sizeArr2) {
        if(arr1[i1] < arr2[i2]) {
            *(dest++) = arr1[i1];
            i1++;
        } else {
            *(dest++) = arr2[i2];
            i2++;
        }
    }

   int *arr3;
   if(i1 < sizeArr1) {
    for(size_t i = i1; i < sizeArr1; i++) {
        *(dest++) = arr1[i];
    }

   } else {
    for(size_t i = i2; i< sizeArr2; i++) {
        *(dest++) = arr2[i];
    }

   }


}
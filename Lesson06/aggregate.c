#include <stdio.h>

int add(int a, int b) {
    return a + b;


}

int mult(int a, int b) {
    return a * b;
}

int addSquare(int sum, int a) {

    return sum += a*a;
}


int aggregate(int *arr, int n, int init, int  (*f)(int , int));

/*

int *arr1 - > first array
int *arr2 - > second array
int sizeArr1 - > size of arr1
int sizeArr2 - > size of arr2
int dest - > the end product of both arrays

*/
// arr1 and arr2 are merged.
void merge(int *arr1, int sizeArr1, int *arr2, int sizeArr2, int dest);
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    // ((((15 + 1) + 2) + 3) + 4) + 5
    printf("\n%d", aggregate(arr, 5, 15, add));
    // (9 * 1) *2) *3) *4) *5
    printf("\n%d", aggregate(arr, 5, 9, mult));

    printf("\n%d", aggregate(arr, 5, 0, addSquare));

    return 0;

}


/*
int *arr ->

int n - >

int init - >

I guess that the first int is for the pointer to point to the int Function. Since the other functions 
are returning an int type. The other 2 ints are for the data types inside the functions.
int (*f)(int, int)


inside  (*f)(int, int)  the first int - > what we have aggregated till now ( put in a cluster together )
                        the second int - > the element which we want to add to the first int.
*/

int aggregate(int *arr, int sizeArr, int init, int  (*f)(int, int)) {

    int res = init;

    //example with for :

    for (int i = 0; i < n; i++) {
        res = f(res, arr[i]);
    }
    return res;


// example without for

    // res = f(res, 1);
    // res = f(res, 2);
    // res = f(res, 3);
    // res = f(res, 4);
    // res = f(res, 5);

    // (f(f(f(f(init, 1), 2), 3), 4), 5);
    // f(f(res, 4), 5);


}


/*
int *arr1 - > first array
int *arr2 - > second array
int sizeArr1 - > size of arr1
int sizeArr2 - > size of arr2
int dest - > the end product of both arrays
*/
// arr1 and arr2 are merged.
void merge(int *arr1, int sizeArr1, int *arr2, int sizeArr2, int dest) {


}
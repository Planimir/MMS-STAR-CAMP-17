#include<stdio.h>

// Пример
// arr: 1 2 3 4 5 6 7 
// f == int addOne(int);
// myMap(arr, 7, addOne);
// arr: 2 3 4 5 6 7 8


void myMap(int arr[], int n, int (*f)(int)) {
    for(size_t i = 0; i < n; i++) {
        arr[i] = f(arr[i]);
    }
}

int scanEl(int a) {
    int temp;
    scanf("%d", &temp);
    return temp;
}
int printEl(int el) {
    printf("%d ", el);
    return el;
}
int square(int el) {
    return el*el;
}
// Направете извикване на myMap, което повдига всеки ел. на arr на квадрат
// Направете извикване на myMap, което въвежда всички ел на arr
// Направете извикване на myMap, което изпечатва arr

int main() {
    int arr[100];
    myMap(arr, 5, scanEl);
    myMap(arr, 3, square);
    myMap(arr, 5, printEl);
    return 0;
}
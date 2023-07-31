#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    unsigned int A = 128, B = 356;
    // случайни числа в интервала [A, B]
    // А = 100, B = 300
    // 100 + случайно число в диапазона [0, 200)
    // 100 + случайно число в диапазона от [0, 300-100)
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        printf("%d ", A + rand()%(B - A));
    }
}
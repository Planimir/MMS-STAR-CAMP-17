#include <stdio.h>

int arr[3] = {1, 2, 3};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutations(int size, int n) {
    int i;
    if (size == 1) {
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (i = 0; i < size; i++) {
        swap(&arr[i], &arr[size - 1]);
        permutations(size - 1, n);
        swap(&arr[i], &arr[size - 1]); // backtrack
    }
}

int main() {
    int n = sizeof(arr)/sizeof(arr[0]);
    permutations(n, n);
    return 0;
}

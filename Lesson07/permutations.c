// печати всички пермутации от масив с н елемент.
// връща броя на всички пермутации
#include <stdio.h>

int arr[10] = {1, 2, 3};


void permutations(size_t begin, size_t total_count);

void swap(int *a, int *b);

int main(int argc, char* argv[]) {

    // искаме края да е 1 индекс преди последния индекс.
    permutations(0, 3);

    // 1 2 3
    // 2 3 1
    // 3 1 2
    // 1 3 2
    // 2 1 3
    // 3 2 1

}

void permutations(size_t begin, size_t total_count) {

    int i;
    // base case ( дъно )
    if(begin == total_count) {
        for(size_t i = 0; i < total_count; i++) {
            printf("%d", arr[i]);
        }
    printf("\n");
    }

    for(size_t i = begin; i < total_count; i++) {
        swap(arr + begin, arr + i);
        permutations(begin + 1, total_count);
        swap(arr + begin, arr + i);
    }

}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


#include <stdio.h>

int binarySearch(int array[], int key, int low, int high) {

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == key)
      return mid;

    if (array[mid] < key)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(array) / sizeof(array[0]);
  int key = 4;
  int result = binarySearch(array, key, 0, n - 1);
  if (result == -1)
    printf("\nNot found\n");
  else
    printf("\nElement is found at index | %d |\n", result);
  return 0;
}
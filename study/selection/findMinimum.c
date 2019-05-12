#include <stdio.h>

int findMinimum (int arr[], int length) {
  int min = arr[0];

  for (int i = 1; i < length; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  return min;
}

int main() {
  int arr[5] = { 5, 1, 24, 35, 3};
  int minimum = findMinimum(arr, 5);

  printf("최솟값: %d\n", minimum);
}
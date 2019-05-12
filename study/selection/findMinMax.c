#include <stdio.h>

void findMinMax(int arr[], int length) {
  int min = arr[0];
  int max = arr[1];

  // arr[0]과 arr[1]을 사용하여 최솟값/최댓값 초기화.
  if (min > max) {
    max = arr[0];
    min = arr[1];
  }

  for(int i = 2; i < length; i += 2) {
    int small = 0, large = 0;

    // 두 데이터 중에서 작은 값과 큰 값을 결정.
    if (i < length && i + 1 < length && arr[i] < arr[i + 1]) {
      small = arr[i];
      large = arr[i + 1];
    } else {
      small = arr[i + 1];
      large = arr[i];
    }

    // 작은 값과 최솟 값을 비교.
    if (small < min) {
      min = small;
    }

    // 큰 값과 최댓 값을 비교.
    if (large > max) {
      max = large;
    }
  }

  printf("최댓값: %d, 최솟값: %d\n", max, min);
}

int main() {
  int arr[5] = {5, -1, 35, 0, 25};

  findMinMax(arr, 5);
}
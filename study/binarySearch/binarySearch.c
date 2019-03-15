#include <stdio.h>

int binarySearch(int arr[], int leftIndex, int rightIndex, int x) {
  // 탐색 실패
  if (leftIndex > rightIndex) {
    return -1;
  }

  int mid = (leftIndex + rightIndex) / 2;

  if (x == arr[mid]) {
    return mid;
  }

  if (x < arr[mid]) {
    // 왼족 배열 탐색
    return binarySearch(arr, leftIndex, mid - 1, x);
  } else {
    // 오른쪽 배열 탐색
    return binarySearch(arr, mid + 1, rightIndex, x);
  }
};

// int main() {
//   int arr[5] = {1,2,3,4,5};
//   int target = binarySearch(arr, 0, 4, 5);

//   printf("\nindex: %d\n", target);
// }
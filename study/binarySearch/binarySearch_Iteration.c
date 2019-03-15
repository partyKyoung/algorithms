#include <stdio.h>

int binarySearch_Iteration(int arr[], int index, int x) {
  int leftIndex = 0, rightIndex = index - 1;
  
  while(leftIndex <= rightIndex) {
    int mid = (leftIndex + rightIndex) / 2;

    if (x == arr[mid]) {
      return mid;
    }

    if (x < arr[mid]) {
      // 왼쪽 부분배열 탐색
      rightIndex = mid - 1;
    } else {
      // 오른쪽 부분배열 탐색
      leftIndex = mid + 1;
    }
  }

  // 탐색키가 존재하지 않을 경우
  return -1; 
};

int main() {
  int arr[5] = {1,2,3,4,5};
  int target = binarySearch_Iteration(arr, 5, 3);

  printf("\nindex: %d\n", target);
}
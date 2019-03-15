#include <stdio.h>

// 배열의 맨 오른쪽 index엔 무한대 값이 있다고 가정한다. 
int partition(int arr[], n) {
  // 맨 왼쪽을 피벗으로 잡기 때문에 left는 피벗의 위치 + 1, right는 배열의 마지막 index
  int leftIndex = 1, rightIndex = n - 1;

  while(leftIndex < rightIndex) {
    // leftIndex는 피벗보다 큰 값을 찾고 rightIndex는 피벗보다 작은 값을 찾음. 

    // leftIndex와 rightIndex를 찾으면 서로 바꿔준다. 
  }

  // rightIndex에 있는 데이터와 피벗 데이터를 바꿔줌.
}

void quickSort(arr, n) {
  if (n > 1) {
    int pivot = partition(arr, n); // 두 부분배열로 분할

    quickSort(arr, pivot) // 왼쪽 부분배열에 대해 순환호출
    quickSort(arr, n - pivot - 1) // 오른쪽 부분배열에 대해서 순환호출
  }
}
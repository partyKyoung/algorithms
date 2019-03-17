#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// 배열의 맨 오른쪽 index엔 무한대 값이 있다고 가정한다.
int partition(int arr[], int leftIndex, int rightIndex) {
// 맨 왼쪽을 피벗으로 잡기 때문에 l_hold는 피벗의 위치 + 1, r_hold는 배열의 마지막 index
  int pivot = arr[leftIndex], l_hold = leftIndex + 1, r_hold = rightIndex;

  while (l_hold <= r_hold) {
    // l_hold는 피벗보다 큰 값을 찾는다.
    while (l_hold <= rightIndex && arr[l_hold] < pivot) {
      l_hold++;
    }

    // r_hold는 피벗보다 작은 값을 찾는다.
    while (r_hold > leftIndex && arr[r_hold] >= pivot) {
      r_hold--;
    }
    
    if (l_hold < r_hold) {
      // arr[l_hold]와 arr[r_hold]의 값을 교환한다.
      swap(arr, l_hold, r_hold);
    }
  }

  // 피벗과 arr[r_hold]값을 교환한다. 
  swap(arr, leftIndex, r_hold);

  return r_hold;
}

void quickSort(int arr[], int leftIndex, int rightIndex) {
  if (leftIndex <= rightIndex) {
    int pivot = partition(arr, leftIndex, rightIndex); // 두 부분배열로 분할

    quickSort(arr, leftIndex, pivot - 1);  // 왼쪽 부분배열에 대해 순환호출
    quickSort(arr, pivot + 1, rightIndex); // 오른쪽 부분배열에 대해서 순환호출
  }
  
}

int main() {
  int arr[8] = {30, 45, 20, 15, 40, 25, 35, 10};
  int length = (int) (sizeof(arr) / sizeof(arr[0]));

  // 퀵 정렬 수행
  quickSort(arr, 0, length - 1);


  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
}
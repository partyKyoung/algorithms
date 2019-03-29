#include <stdio.h>

void merge(int arr[], int sorted[], int leftIndex, int mid, int rightIndex) {
  int l_hold = leftIndex, r_hold = mid + 1;
  int resultIndex = leftIndex; // 결과 배열의 index

  while(l_hold <= mid && r_hold <= rightIndex) {
    // 부분배열 두개를 비교하여 작은 값을 선택한다.
    if (arr[l_hold] < arr[r_hold]) {
      sorted[resultIndex] = arr[l_hold];

      l_hold++;
    } else {
      sorted[resultIndex] = arr[r_hold];

      r_hold++;
    }

    resultIndex++;
  }

  // 왼쪽 부분배열에 남아있는 모든 원소를 새로은 배열로 이동시킨다.
  while (l_hold <= mid) {
    sorted[resultIndex] = arr[l_hold];

    resultIndex ++;
    l_hold ++;
  }

  // 오른쪽 부분배열에 남아있는 모든 원소를 새로은 배열로 이동시킨다.
  while (r_hold <= rightIndex) {
    sorted[resultIndex] = arr[r_hold];

    resultIndex ++;
    r_hold ++;
  }


  // 원본 배열에 정렬된 배열을 이동 시킨다.
  for (int i = leftIndex; i <= rightIndex; i++) {
    arr[i] = sorted[i];
  }
}

void mergeSort (int arr[], int sorted[], int leftIndex, int rightIndex) {
  if (leftIndex < rightIndex) {
    // 각각 n/2크기를 가진 두 부분배열로 나누기 위해 가운데 값 정함.
    int mid = (leftIndex + rightIndex) / 2;

    // 왼쪽 부분배열의 순환호출
    mergeSort(arr, sorted, leftIndex, mid);

    // 오른쪽 부분배열의 순환호출
    mergeSort(arr, sorted, mid + 1, rightIndex);

    // 정렬된 두 부분배열의 합병
    merge(arr, sorted, leftIndex, mid, rightIndex);
  }
}

int main() {
  int arr[8] = { 20, 15, 35, 50, 40,  10, 30, 25 }, arr2[8] = {0};

  mergeSort(arr, arr2, 0, 7);

  for(int i=0; i < 8; i++){
    printf("%d ", arr[i]);
  }
}
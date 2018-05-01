
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge (int arr[], int mid, int left, int right) {
  int i = left;
  int j = mid + 1;
  int k = left;
  int temp[left + right];

  while (i <= mid && j <= right) {
    // 부분배열 arr1[j]와 arr2[j]를 비교해서 작은 값을 선택
    if (arr[i] < arr[j]) {
      temp[k++] = arr[i++]; // arr1[i] 선택 
    } else {
      temp[k++] = arr[j++]; //arr2[j] 선택
    }
  }

  while (i <= mid) {
    temp[k++] = arr[i++];
  }
    

  while (j <= right) {
    temp[k++] = arr[j++];
  }

  for (int m = left; m <= right; m ++) {
    arr[m] = temp[m];
  }
} 

void mergeSort (int arr[], int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, mid, left, right);
  }
}

int main () {
  int arr[5] = {6,3,8,4,1};

  mergeSort(arr, 0, 4);

  //출력
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}
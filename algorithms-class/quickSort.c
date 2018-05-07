#include <stdio.h>
#define length 12

void swap(int arr[], int index1, int index2) {
  int tmp = arr[index1];
  
  arr[index1] = arr[index2];
  arr[index2] = tmp;
}

int partition (int arr[], int left, int right) {
  int pivot = left;
  int j = pivot;
  int i = left + 1;

  for (; i <= right; i++) {
    if (arr[i] < arr[pivot]) {
      j++;
      swap(arr, j, i);
    }
  }

  swap(arr, left, j);
  pivot = j;  

  return pivot;
}

void quickSort (int arr[], int left, int right) {
  if (left < right) {
    int pivot = partition(arr, left, right);

    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
  }
}

int main () {
  int arr[length] = {30, 50, 17, 40, 88, 15, 44, 22, 11, 66, 13, 85};

  // 맨처음 피벗은 6이 되므로 6을 기준으로 6보다 작은 원소들로 이루어진 배열, 6보다 큰 원소들로 이루어진 배열로 나눈다
  quickSort(arr, 0, 11);

  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}
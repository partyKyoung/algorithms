#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

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

int selection (int arr[], int arrLength, int groupLength, int findIndex) {
  // 배열의 길이가 5보다 작거나 같으면 배열 A에서 i번째 원소를 찾아서 봔한한다. 
  if (arrLength <= 5) {
    return arr[findIndex];
  }

  int middleArr[groupLength];
  int j = 5 / 2;

  // 배열 A의 원소를 다섯 개 씩 묶어서 n/5개의 그룹을 만든 후 각 그룳에서 중간값을 구하고 이들을 모아서 배열 M을 구성한다.
  for (int i = 0; i < groupLength; i++) {
    if (j < arrLength) {
      middleArr[i] = arr[j];

      j += 5;
    }
  }

  // 중간값들의 중간값을 계산하기 위해 선택 함수를 순환호출 한다.
  int loopLength = groupLength / 5;
  int pivot = selection(middleArr, loopLength, loopLength/2, findIndex);
  int partitionPivot = partition(arr, 0, pivot);
  
  if (findIndex == partitionPivot + 1) {
    return arr[partitionPivot];
  }
}

int main () {
  int arr[38] = {9, 6, 35, 39, 15, 24, 70, 95, 50, 1, 97, 84, 77, 28, 10, 22, 27, 11, 31, 62, 54, 81, 5, 34, 4, 89, 60, 29, 2, 75, 18, 36, 80, 7, 53, 25, 66, 43};

  selection(arr, 38, 38/5, 5);
}
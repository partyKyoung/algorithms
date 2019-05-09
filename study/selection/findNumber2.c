#include <stdio.h>
#include <stdlib.h>

// 삽입 정렬 함수
void insertionSort(int arr[], int leftIndex, int rightIndex){
  int i, j, key;

  for(i = leftIndex + 1; i <= rightIndex; i++){
    key = arr[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

    // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
    // j 값은 음수가 아니어야 되고
    // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
    for(j=i-1; j>=0 && arr[j]>key; j--){
      arr[j+1] = arr[j]; // 레코드의 오른쪽으로 이동
    }

    arr[j+1] = key;
  }
}

// 분할 함수
int partition(int arr[], int leftIndex, int rightIndex, int pivot) {
  int swapIndex = leftIndex;

  for (int i = leftIndex; i <= rightIndex; i++) {
    if (arr[i] < pivot) {
      int temp = arr[i];
    
      arr[i] = arr[swapIndex];
      arr[swapIndex] = temp;

      swapIndex += 1;
    }
  }

  return swapIndex - 1;
}

int selection (int arr[], int leftIndex, int rightIndex, int findIndex) {
  int arrLength = rightIndex - leftIndex + 1;
  int medianNum = arrLength / 5;
  
  if (0 > findIndex && findIndex > arrLength) {
    return -1;
  }

  if (arrLength <= 5) {
    insertionSort(arr, leftIndex, rightIndex);

    return arr[findIndex - 1];
  }

  int *maidanArr = (int *) malloc(sizeof(int) * medianNum);

  for (int i = 0; i < medianNum; i++) {
    maidanArr[i] = selection(arr, leftIndex + (5 * i), (leftIndex + (5 * (i+1)-1)), leftIndex + (5 * i) + 2);
  }

  int pivot = selection(maidanArr, 0, medianNum - 1, (medianNum / 2) + 1);
  int pivotIndex = partition(arr, leftIndex, rightIndex, pivot);
  int rank = pivotIndex - leftIndex + 1;

  if (findIndex <= rank) {
      return selection(arr, leftIndex, pivotIndex, findIndex);
  } else {
      return selection(arr, pivotIndex + 1, rightIndex, findIndex);
  }
} 

int main () {
  int arr[38] = {9, 6, 35, 39, 15, 24, 70, 95, 50, 1, 97, 84, 77, 28, 10, 22, 27, 11, 31, 62, 54, 81, 5, 34, 4, 89, 60, 29, 2, 75, 18, 36, 80, 7, 53, 25, 66, 43};
  int index = 10;

  printf("%d번째로 작은 값: %d\n", index, selection(arr, 0, 37, index));
}
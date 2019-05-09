#include <stdio.h>
#include <stdlib.h>

// 삽입 정렬 함수
void insertionSort(int list[], int n){
  int i, j, key;

  // 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
  for(i=1; i<n; i++){
    key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

    // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
    // j 값은 음수가 아니어야 되고
    // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
    for(j=i-1; j>=0 && list[j]>key; j--){
      list[j+1] = list[j]; // 레코드의 오른쪽으로 이동
    }

    list[j+1] = key;
  }
}

// 분할 함수
int partition(int arr[], int leftIndex, int rightIndex, int pivot) {
  int swapIndex = leftIndex;

  for (int i = 0; i < rightIndex; i++) {
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
  
  if (1 > findIndex && findIndex > arrLength) {
    return -1;
  }

  if (arrLength <= 5) {
    insertionSort(arr, arrLength);

    return arr[findIndex];
  }

  int *maidanArr = (int *) malloc(sizeof(int) * medianNum);

  for (int i = 0; i < medianNum; i++) {
    int maidanLeft = leftIndex + (5 * i);
    int maidanRight = (leftIndex + 5 * (i+1)-1);
    int findMaidanIndex = (maidanRight - maidanLeft + 1) / 2;

    maidanArr[i] = selection(arr, leftIndex + (5 * i), (leftIndex + 5 * (i+1)-1), maidanLeft + 2); 
  }

  int pivot=selection(maidanArr, 0, medianNum - 1, (medianNum / 2+1));
  int pivotIndex=partition(arr, leftIndex, rightIndex, pivot);
  int rank = pivotIndex-leftIndex;

  if (findIndex <= rank) {
      return selection(arr, leftIndex, pivotIndex, findIndex);
  } else {
      return selection(arr, pivotIndex + 1, rightIndex, findIndex-rank);
  }
} 

int main () {
  int arr[15] = {5, 9, 2, 30, 1, 7, 12, 10, 22, 11, 6, 34, 66, 18, 33};
  int index = 10;

  /* 테스트 */
  insertionSort(arr, 15);

  for (int i = 0; i < 15; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  printf("%d번째로 작은 값: %d\n", index, selection(arr, 0, 14, index));
}
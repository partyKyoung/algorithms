#include <stdio.h>
#include <stdlib.h>

// 삽입 정렬
void insertion_sort(int list[], int n){
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

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int leftIndex, int rightIndex, int pivot) {
  int swapIndex = leftIndex;

  for (int i = 0; i < rightIndex; i++) {
    if (arr[i] < pivot) {
      swap(arr, i, swapIndex);
    }
  }

  return swapIndex;
}

int selection (int arr[], int leftIndex, int rightIndex, int groupLength, int findIndex) {
  if (leftIndex > rightIndex) {
    return -1;
  }

  int arrLength = rightIndex - (leftIndex + 1);
  
  // 배열의 길이가 5보다 작거나 같으면 배열 A에서 i번째 원소를 찾아서 봔한한다. 
  if (rightIndex <= 5) {
    insertion_sort(arr, arrLength);

    return arr[findIndex];
  }

  int groupArr[groupLength][5], middleArr[groupLength];
  int firstIndex = 0, lastIndex = 0;
 
  // arr을 다섯개씩 나누어 총 arrLength / 5 개의 그룹을 만든다. 그룹에 참여하지 못한 원소들은 피벗 선정에 사용하지 않는다. 
  for (int i = 0; i < arrLength; i++) {
    groupArr[firstIndex][lastIndex] = arr[i];
    lastIndex += 1;

    if (lastIndex % 5 == 0) {
      // 각 그룹의 다섯개 원소에 대해서 삽입정렬을 수행한 후 그룹의 중간값을 구한다.
      insertion_sort(groupArr[firstIndex], 5);

      middleArr[firstIndex] = groupArr[firstIndex][5/2];
      lastIndex = 0;
      firstIndex += 1;
    }

    if (firstIndex == groupLength) {
      break;
    }
  }

  // 중간값들의 중간값을 구한다.
  int middleValue = selection(middleArr, 0, groupLength, groupLength/5, ((groupLength/5) / 2));

  // 중간값을 피벗으로 사용하여 주어진 배열 A를 분할한다. 
  int pivot = partition(arr, leftIndex, rightIndex, middleValue);

  if (findIndex == pivot + 1) {
    return arr[findIndex];
  }

  if (findIndex < pivot + 1) {
    int rightIndex = pivot - 1;
    int arrLength = (rightIndex - (leftIndex + 1)) / 5;

    return selection(arr, leftIndex, pivot - 1, groupLength, findIndex);
  } else {
    int leftIndex = pivot + 1;
    int groupLength = (rightIndex - (leftIndex + 1)) / 5;

    return selection(arr, pivot + 1, rightIndex, groupLength, findIndex - rightIndex - (leftIndex + 1));

  }

  return -1;
}

int main () {
  int arr[15] = {5, 9, 2, 30, 1, 7, 12, 10, 22, 11, 6, 34, 66, 18, 33};
  int index = 10;

  /* 테스트 */
  insertion_sort(arr, 15);

  for (int i = 0; i < 15; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  printf("%d번 로 작은 값: %d\n", index, selection(arr, 0, 15, 15/5, index));
}
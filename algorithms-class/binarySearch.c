# include <stdio.h>
# define MAX 10

// 순환(재귀) 형태
int binarySearch (int arr[], int left, int right, int x) {
  int mid = 0;

  if (left > right) {
    return -1;
  }

  mid = (left + right) / 2;

  if (x == arr[mid]) {
    return mid;
  }

  if (x < arr[mid]) {
    return binarySearch(arr, left, mid - 1, x);
  } else {
    return binarySearch(arr, mid + 1, right, x);
  }
}

// 반복문 형태
int binarySearchIteration(int arr[], int arrLength, int x) {
  int left = 0, right = arrLength;
  int mid = 0;

  while (left <= right) {
    mid = (left + right) / 2;

    if (x == arr[mid]) {
      return mid;
    }

    if (x < mid) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}

int main () {
  int arr[MAX] = {0,1,2,3,4,5,6,7,8,9};
  int findNum = 9;
  int index = -1, index2 = -1;
  int min = 0, max = MAX - 1;

  index = binarySearch(arr, min, max, findNum);
  index2 = binarySearchIteration(arr, max, findNum);

  printf("순환: %d\n", index);
  printf("반복: %d\n", index2);
}
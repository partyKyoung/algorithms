#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE 9999999

int min (int a, int b) {
  if ( a < b ) {
    return a;
  } 

  return b;
}

/**
 * length: 행렬의 갯수
 * d[]: 정수 배열
*/
int minMatMult (int length, int d[]) {
  // n개의 행렬을 곱하는데 필요한 곱셈 횟수의 최솟값을 저장하는 배열.
  int **matrix =  malloc(sizeof(int) * length);

  for (int i = 0; i <= length; i++) {
    matrix[i] =  malloc(sizeof(int) * length);
  }


  // mtarix[i][i] 초기화.
  for (int i = 1; i <= length; i++) {
    matrix[i][i] = 0;
  }


  for (int f = 1; f <= length - 1; f++) {
    for (int n = 1; n <= length - f; n++) {
      int j = f + n;
      
      matrix[n][j] = MAX_VALUE;

      for (int k = n; k <= j - 1; k++) {
        matrix[n][j] = min(matrix[n][j], matrix[n][k] + matrix[k + 1][j] + d[n - 1] * d[k] * d[j]);
      }
    }
  }

  int value = matrix[1][length];

  free(matrix);

  return value;
} 

int main () {
  int n = 3;
  int d[6] = {3, 2, 4, 1};

  int minValue = minMatMult(n, d);

  printf("최소 수: %d\n", minValue);
}
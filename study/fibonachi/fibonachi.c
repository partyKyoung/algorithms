#include <stdio.h>
#include <stdlib.h>

// 50 이상의 수열에서는 int형 범위를 초과하기 때문에 double을 반환형으로 사용하였다.
double fibonachi (int num) {
  double *fiboArr = (double *) malloc(sizeof(double) * num);

  // f(0)과 f(1)을 테이블에 저장한다.
  fiboArr[0] = 0;
  fiboArr[1] = 1;

  // i를 2부터 1씩 증가시키며 f(i)의 해를 테이블에 저장된 f(i - 1)과 f(i - 2)의 합으로 계산하여 다시 테이블에 저장한다.
  for (int i = 2; i <= num; i++) {
    fiboArr[i] = fiboArr[i - 1] + fiboArr[i - 2];
  }

  return fiboArr[num];
}

int main () {
  int num = 40;

  printf("%f \n", fibonachi(num));
}
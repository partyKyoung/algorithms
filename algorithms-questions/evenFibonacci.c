/**
 * 피보나치 배열은 0과 1로 시작하며, 다음 피보나치 수는 바로 앞의 두 피보나치 수의 합이 된다. 
 * 정수 N이 주어지면, N보다 작은 모든 짝수 피보나치 수의 합을 구하여라.
 * 예제)
 * Input: N = 12
 * Output: 10 // 0, 1, 2, 3, 5, 8 중 짝수인 2 + 8 = 10.
*/

#include <stdio.h>
#define MAX 100

int getEvenSum (evenSum) {
  if ((evenSum % 2) == 0) {
    return evenSum;
  }

  return 0;
}

int fibonacci (num) {
  int i = 0;
  int sum = 0, evenSum = 0;
  int fibonacciArray[MAX] = {0, 1};

  for (i = 2; sum <= num; i++) {
    sum = fibonacciArray[i-2] + fibonacciArray[i - 1];
    fibonacciArray[i] = sum;

    evenSum += getEvenSum(sum);
  }

  return evenSum;
}

int main () {
  int num = 0;
  int value = 0;

  scanf("%d", &num);

  if (num > MAX) {
    printf("입력받을 수 있는 숫자값이 너무 큽니다.");

    return 0;
  }

  value = fibonacci(num);

  printf("%d\n", value);
}
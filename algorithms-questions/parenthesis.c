/**
 * 안녕하세요, 매일프로그래밍 이번주 문제입니다.
 * 정수 n이 주어지면, n개의 여는 괄호 "("와 n개의 닫는 괄호 ")"로 만들 수 있는 괄호 조합을 모두 구하시오. 
 * (시간 복잡도 제한 없습니다).
 * 
 * 예제)
 * Input: 1
 * Output: ["()"]
 * 
 * Input: 2
 * Output: ["(())", "()()"]
 * 
 * Input: 3
 * Output: ["((()))", "(()())", "()(())", "(())()", "()()()"]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact (int n) {
  int res, i;

  if (n == 1) {
    return n;
  }

  res = n;

  for (i = n - 1; i > 0; i--) {
    res *= i;
  }

  return res;
}

int getCatalanNumber (int num) {
  /** 
   * denominator 분모
   * numerator 분자
  */
  int denominator = 0, numerator = 0, catalanNumber = 0;

  numerator = fact(2 * num);
  denominator = fact(num + 1) * fact(num);
  catalanNumber = numerator / denominator;

  printf("%d\n", catalanNumber);

  return catalanNumber;
}

int main () {
  getCatalanNumber(5);
}

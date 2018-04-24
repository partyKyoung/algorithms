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


void recurse(char* parenthesisPairs, char cur, int open, int close, int num) {
  int size = num * 2;
  int i = 0;

  if (size == i) {
    parenthesisPairs[i] = cur;
  }

  if (open < num) {
    recurse(parenthesisPairs, '(', open + 1, close, num);
  }

  if (close < open) {

    recurse(parenthesisPairs, ')', open, close + 1, num);
  }
}

int main () {
  char* parenthesisList;
  int size = 0, num = 0;

  scanf("%d", &num);
  
  size = num * 2;
  parenthesisList = (char *) malloc (sizeof(char)* size);

  memset(parenthesisList, 0, sizeof(size));

  recurse(parenthesisList, '\n', 0, 0, num);

  free(parenthesisList);
}

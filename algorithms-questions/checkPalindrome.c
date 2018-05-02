#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * 안녕하세요, 매일프로그래밍 이번주 문제입니다.
 * 정수(int)가 주어지면, 팰린드롬(palindrome)인지 알아내시오. 
 * 팰린드롬이란, 앞에서부터 읽으나 뒤에서부터 읽으나 같은 단어를 말합니다. 단, 정수를 문자열로 바꾸면 안됩니다.
 * 
 * 예제)
 * Input: 12345
 * Output: False
 * 
 * Input: -101
 * Output: False
 * 
 * Input: 11111
 * Output: True
 * 
 * Input: 12421
 * Output: True
*/

/** 
 * 매일 프로그래밍 풀이
 * 이제 주어진 숫자를 전반과 후반으로 나누어 줍니다. 
 * 예를 들면 123321이 주어지면, 123이 전반이고 321이 후반입니다. 
 * 전반(123)이 거꾸로된 후반(123)과 값이 같다면 팰린드롬이겠죠. 
 * 정수를 전반과 거꾸로 된 후반으로 나누려면 while loop을 써서 정수의 일의 자리수를 뽑아낸후 정수를 10으로 나누면 정수의 각 숫자를 얻어낼수 있습니다.
 * 123321 -> 12332, 1 -> 1233, 2 -> 123, 3.
 * 이제 거꾸로 된 후반은 10으로 곱한뒤 뽑아낸 일의 자리 숫자를 더하면 됩니다.
 * 0 + 1 -> 10 + 2 -> 120 + 3 = 123.
 * ﻿이 방법을 거꾸로된 후반이 전반보다 크거나 같을때까지 반복하면 됩니다.
 * 만약 주어진 숫자의 길이가 홀수라면, 거꾸로된 후반에서 1의 자리수를 없애주면 됩니다.
 * 2321 -> 전반(12), 거꾸로된 후반(123)
*/
int getCheckPalindrome2 (int num) {
  bool isPalindrome = false;

  if (num < 0 || (num % 10 == 0 && num != 0)) {
    return isPalindrome;
  }

  int num2 = 0;

  while (num > num2) {
    num2 = (num2 * 10) + (num % 10);
    num = num / 10;
  }

  if (num == num2 || num == (num2/10)) {
    isPalindrome = true;
  }

  return isPalindrome;
}

/** 
 * 내 풀이
 * num 을 받으면 각각 자리수를 잘라 배열에 저장해서 배열의 앞부분과 뒷부분을 하나씩 비교해서 같은지 확인 
*/
int getCheckPalindrome (int num, int* numList, int length) {
  bool isPalindrome = true;

  if (num < 0) {
    isPalindrome = false;

    return isPalindrome;
  }

  for (int i = 0; i < length; i++) {
    if (numList[i] != numList[(length - 1) -i]) {
      isPalindrome = false;
    }
  }

  return isPalindrome;
}

void getNumList (int num, int* numList, int length) {
  numList = (int *)malloc(sizeof(int) * length);

  for (int i = 0; num > 0; i++) {
    numList[i] = (int) num % 10;
    num = num / 10;
    
    if (num > 0) {
      length += 1;
      numList = realloc(numList, sizeof(int) * length);
    }
  }
}

int main () {
  int num = 0, length = 1;
  int* numList;

  scanf("%d", &num);

  // if (getCheckPalindrome(num, numList, length) == true) {
  //   printf("True\n");
  // } else {
  //   printf("False\n");
  // }

  if (getCheckPalindrome2(num) == true) {
    printf("True2\n");
  } else {
    printf("False2\n");
  }
}
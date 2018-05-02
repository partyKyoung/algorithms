#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int getpositiveNum (int num) {
  if (num < 0) {
    num *= -1;
  }

  return num;
}

char* getCheckPalindrome (int* numList, int length) {
  char* isPalindrome = "True";

  for (int i = 0; i < length; i++) {
        printf("%d %d\n", numList[i], numList[(length - 1) -i]);
    if (numList[i] != numList[(length - 1) -i]) {
      isPalindrome = "False";
    }
  }


  return isPalindrome;
}

int main () {
  int num = 0, positiveNum = 0, length = 1;
  int* numList;

  scanf("%d", &num);

  positiveNum = getpositiveNum(num);
  numList = (int *)malloc(sizeof(int) * length);

  for (int i = 0; positiveNum > 0; i++) {
    numList[i] = (int) positiveNum % 10;
    positiveNum = positiveNum / 10;

    if (i == 0 && num < 0) {
      numList[i] *= -1;
    }

    if (positiveNum > 0) {
      length += 1;
      numList = realloc(numList, sizeof(int) * length);
    }
  }

  printf("%s\n", getCheckPalindrome(numList, length));
}
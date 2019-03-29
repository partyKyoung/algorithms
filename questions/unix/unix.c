#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getUrl(char* url, int urlLength) {
  char* str;

  str = (char *) malloc(sizeof(char));
  str = strtok(url, "/");

  // while (str != NULL){               // 자른 문자열이 나오지 않을 때까지 반복
  //   printf("%s\n", str);          // 자른 문자열 출력
       
  //   str = strtok(NULL, "/");      // 다음 문자열을 잘라서 포인터를 반환
  // }

  // return str;
}

int main() {
  char* str;

  str = (char *) malloc(sizeof(char));
  str = "/usr/./bin/./test/../";
 
 getUrl(str, 21);
}
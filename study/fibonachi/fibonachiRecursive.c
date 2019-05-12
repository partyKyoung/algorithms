#include <stdio.h>
#include <stdlib.h>

double fibonachi (int num) {
  if (num == 0) {
    return 0;
  }

  if (num == 1) {
    return 1;
  }

  return fibonachi(num - 1) + fibonachi(num - 2);
}

int main () {
  int num = 40;

  printf("%f \n", fibonachi(num));
}
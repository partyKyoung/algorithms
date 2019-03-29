#include <stdio.h>

int fibo (n) {
  if (n == 0) {
    return 0;
  }

  if (n == 1) {
    return 1;
  }

  return fibo(n - 1) + fibo(n - 2);
}

int main() {
  int n = fibo(10);

  printf("%d\n", n);
}
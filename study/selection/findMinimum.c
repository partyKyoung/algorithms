#include <stdio.h>

int findMinimum (int arr[], length) {
  int min = arr[0];

  for (i = 1; i < length; i++) {
    if (arr[i] < min ) {
      min = arr[i]
    }
  }

  return min;
}

int main() {

}
int findMinMax(int arr[], int length, int min, int max) {
  min = arr[0];
  max = arr[1];

  if (min > max]) {
    max = arr[0];
    min = arr[1];
  }

  for(int i = 2; i < length; i += 2) {
    int small, large;

    if (arr[i] < arr[i + 1]) {
      small = arr[i];
      large = arr[i + 1];
    } else {
      small = arr[i + 1];
      large = arr[i];
    }

    if (small < min) {
      min = small;
    }

    if (large > max) {
      max = large;
    }
  }
}
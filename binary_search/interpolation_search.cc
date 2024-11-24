

#include <cstdio>
#include <iostream>

using namespace std;
int interpolate_position(int arr[], int low, int high, int key) {
  return (low + (((key - arr[low]) / (arr[high] - arr[low])) * (high - low)));
}

int interpolation_search(int arr[], int n, int key) {
  int low = 0, high = n - 1;

  while (low <= high) {
    int pos = interpolate_position(arr, low, high, key);

    cout << "low: " << low << " high: " << high << " pos: " << pos << "\n";
    if (arr[pos] == key) {
      return pos;
    }

    if (arr[pos] < key) {
      low = pos + 1;
    } else {
      high = pos - 1;
    }
  }
  return -1;
}

int main() {

  int arr[] = {5, 32, 56, 104, 302, 1023, 2304, 13000, 4567302};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 2304;

  int index = interpolation_search(arr, n, key);

  if (index != -1) {
    printf("Element found at index %d", index);
  } else {
    printf("Element not found in the array");
  }

  printf("\n");

  return 0;
}

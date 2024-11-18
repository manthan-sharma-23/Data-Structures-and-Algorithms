#include <iostream>
void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    bool swapped{0};
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        swapped = 1;
      }
    }

    if (!swapped)
      break;
  }
}

int main() {
  int arr[] = {3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  bubble_sort(arr, n);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl;
  return 0;
}

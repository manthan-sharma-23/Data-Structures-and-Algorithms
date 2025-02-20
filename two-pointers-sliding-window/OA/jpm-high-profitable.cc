#include <iostream>
#include <vector>

using namespace std;

int countIncreasingSubarrays(const vector<int> &arr, int k) {
  int n = arr.size();
  if (n < k || k <= 0)
    return 0;
  int count = 0;
  int start = 0;
  for (int i = 1; i < n; ++i) {
    if (arr[i] <= arr[i - 1]) {
      int length = (i - 1) - start + 1;
      if (length >= k) {
        count += (length - k + 1);
      }
      start = i;
      continue;
    }
    if (i == n - 1) {
      int length = n - start;
      if (length >= k) {
        count += (length - k + 1);
      }
    }
  }
  return count;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  cout << countIncreasingSubarrays(arr, k) << endl;
  return 0;
}
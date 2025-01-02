#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

bool isSorted(vector<int> &arr) {
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] < arr[i - 1])
      return false;
  }
  return true;
}

int main() {
  int t;

  cin >> t;

  while (t--) {
    int n, k;
    cin >> n;
    cin >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
      cin >> arr[i];

    if (k == 1) {
      if (isSorted(arr)) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
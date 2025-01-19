#include <iostream>
#include <vector>
using namespace std;

bool canMakeNonDecreasing(int n, vector<int> &a) {

  for (int i = 1; i < n; i++) {
    int min__ = min(a[i], a[i - 1]);
    a[i] -= min__;
    a[i - 1] -= min__;
  }

  for (int i = 0; i < n - 1; i++) {
    if (a[i] != 0)
      return false;
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    if (canMakeNonDecreasing(n, arr)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
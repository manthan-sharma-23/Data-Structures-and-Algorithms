#include <iostream>

using namespace std;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n, k;
  cin >> n >> k;

  if (k & 1) {
    for (int i = 1; i < n; i++) {
      cout << n - 1 << " ";
    }
    cout << n - 2 << endl;
  } else {
    for (int i = 1; i <= n; i++) {
      cout << n - 1 << " ";
    }
    cout << endl;
  }
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();
  return 0;
}
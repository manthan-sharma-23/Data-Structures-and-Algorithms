#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;

  int avg = 0;

  for (int i = 1; i <= n; i++) {
    int m;
    cin >> m;
    avg += m;
  }

  if (avg % n != 0) {
    cout << "NO" << endl;
    return;
  }

  avg /= n;

  if (avg == x) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
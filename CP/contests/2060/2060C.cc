#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; ++i) {
      cin >> x[i];
      freq[x[i]]++;
    }

    int score = 0;

    for (int i = 0; i < n; ++i) {
      int a = x[i];
      int b = k - a;

      if (freq[a] > 0 && freq[b] > 0) {
        if (a == b && freq[a] < 2)
          continue;
        freq[a]--;
        freq[b]--;
        score++;
      }
    }

    cout << score << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}

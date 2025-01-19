#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve(unordered_map<int, vector<int>> &cows) {
  int n = cows.size();
  vector<pair<int, int>> cowMin;
  for (const auto &entry : cows) {
    int cowIndex = entry.first;
    const vector<int> &deck = entry.second;
    cowMin.push_back({deck[0], cowIndex});
  }

  sort(cowMin.begin(), cowMin.end());

  vector<int> permutation;
  for (const auto &p : cowMin) {
    permutation.push_back(p.second);
  }

  vector<int> indices(n + 1, 0);
  int topCard = -1;

  for (int round = 0; round < cows.begin()->second.size(); ++round) {
    for (int i = 0; i < n; ++i) {
      int cowIndex = permutation[i];
      if (indices[cowIndex] < cows[cowIndex].size() &&
          cows[cowIndex][indices[cowIndex]] > topCard) {
        topCard = cows[cowIndex][indices[cowIndex]];
        indices[cowIndex]++;
      } else {
        cout << -1 << endl;
        return;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << permutation[i] << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> cows;
    for (int i = 1; i <= n; ++i) {
      vector<int> deck(m);
      for (int j = 0; j < m; ++j) {
        cin >> deck[j];
      }
      sort(deck.begin(), deck.end());
      cows[i] = deck;
    }

    solve(cows);
  }

  return 0;
}

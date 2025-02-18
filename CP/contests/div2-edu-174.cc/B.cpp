#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  map<int, int> color_cost;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      color_cost[grid[i][j]] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int color = grid[i][j];
      for (auto [dx, dy] :
           vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
        int ni = i + dx, nj = j + dy;
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == color) {
          color_cost[color] = 2;
        }
      }
    }
  }

  int total_cost = 0, max_cost = 0;
  for (auto &[color, cost] : color_cost) {
    total_cost += cost;
    max_cost = max(max_cost, cost);
  }

  cout << total_cost - max_cost << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
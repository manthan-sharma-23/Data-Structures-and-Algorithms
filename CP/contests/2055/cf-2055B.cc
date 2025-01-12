#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> arr(n), need(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 0; i < n; i++)
    cin >> need[i];

  vector<int> diff(n);
  for (int i = 0; i < n; i++) {
    diff[i] = arr[i] - need[i];
  }

  bool possible = true;

  while (true) {

    long long min_surplus = 1e8;
    long long max_desire = 0;
    int deficit_idx = 0;
    for (int i = 0; i < n; i++) {
      if (diff[i] >= 0) {
        min_surplus = min(min_surplus, (long long)diff[i]);
      }
      if (diff[i] < 0) {
        if (abs(diff[i]) > max_desire) {
          max_desire = abs(diff[i]);
          deficit_idx = i;
        }
      }
    }

    if (min_surplus < max_desire || min_surplus == 1e8) {
      cout << "NO" << endl;
      return;
    }
    if (max_desire == 0) {
      cout << "YES" << endl;
      return;
    }

    for (int i = 0; i < n; i++) {
      diff[i] -= max_desire;
    }
    diff[deficit_idx] = 0;
  }
}

// int main() {
//   int t;
//   cin >> t;

//   while (t--) {
//     solve();
//   }

//   return 0;
// }

//

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define en "\n"
#define debug(x) cout << "x = " << x << en

void restoreGrid(vector<vector<long long>> &grid,
                 const vector<pair<int, int>> &path) {
  int n = grid.size();
  int m = grid[0].size();
  vector<long long> rowSum(n, 0), colSum(m, 0);
  long long totalSum = 0;

  // Calculate row sums and column sums for the given grid
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      rowSum[i] += grid[i][j];
      colSum[j] += grid[i][j];
      totalSum += grid[i][j];
    }
  }

  // Identify the correct row/column sum (sum for a complete row/column)
  long long expectedSum = 0;
  for (int i = 0; i < n; i++) {
    if (rowSum[i] > expectedSum) {
      expectedSum = rowSum[i];
    }
  }

  for (int i = 0; i < n; i++) {
    if (colSum[i] > expectedSum) {
      expectedSum = colSum[i];
    }
  }

  // Restore the grid along the given path
  for (auto &[x, y] : path) {
    grid[x][y] = expectedSum - rowSum[x];
    rowSum[x] += grid[x][y];
    colSum[y] += grid[x][y];
  }
}
void solve_() {
  ll n, m;
  cin >> n >> m;
  string _path;
  cin >> _path;
  vector<vector<ll>> grid(n, vector<ll>(m, 0));
  vector<ll> rows(n), cols(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      rows[i] += grid[i][j];
      cols[j] += grid[i][j];
    }
  }
  int x = 0, y = 0;
  for (char c : _path) {
    if (c == 'D') {
      grid[x][y] = -rows[x];
      rows[x] += grid[x][y];
      cols[y] += grid[x][y];
      x++;
    } else {
      grid[x][y] = -cols[y];
      rows[x] += grid[x][y];
      cols[y] += grid[x][y];
      y++;
    }
  }

  grid[x][y] = -rows[x];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t;
  cin >> t;
  while (t--) {
    solve_();
  }
}
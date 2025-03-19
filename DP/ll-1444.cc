#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  typedef long long ll;
  int m, n;
  vector<string> grid;
  vector<vector<vector<ll>>> memo;
  const int MOD = 1e9 + 7;

  bool hasApple(int r, int c, int er, int ec) {
    for (int i = r; i <= er; i++) {
      for (int j = c; j <= ec; j++) {
        if (grid[i][j] == 'A')
          return true;
      }
    }
    return false;
  }

  int f(int r, int c, int k) {
    if (k == 0) {
      return hasApple(r, c, m - 1, n - 1) ? 1 : 0;
    }

    if (memo[r][c][k] != -1LL)
      return memo[r][c][k];

    ll ways = 0LL;

    for (int i = r + 1; i < m; i++) {
      if (hasApple(r, c, i - 1, n - 1)) {
        ways = (ways + f(i, c, k - 1)) % MOD;
      }
    }

    for (int j = c + 1; j < n; j++) {
      if (hasApple(r, c, m - 1, j - 1)) {
        ways = (ways + f(r, j, k - 1)) % MOD;
      }
    }

    return memo[r][c][k] = ways % MOD;
  }

  int ways(vector<string> &pizza, int k) {
    m = pizza.size();
    n = pizza[0].size();
    grid = pizza;

    memo.resize(m + 1, vector<vector<ll>>(n + 1, vector<ll>(k + 1, -1LL)));
    return f(0, 0, k - 1);
  }
};

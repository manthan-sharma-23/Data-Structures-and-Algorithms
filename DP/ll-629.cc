#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  const int MOD = 1e9 + 7;

  int solve(int n, int k, vector<vector<int>> &memo) {

    if (n == 0)
      return 0;

    if (k == 0)
      return 1;

    if (memo[n][k] != -1)
      return memo[n][k];

    int ans = 0;

    for (int x = 0; x <= min(k, n - 1); x++) {
      ans += solve(n - 1, k - x, memo);
    }

    return memo[n][k] = ans;
  }

  int kInversePairs(int n, int k) {
    vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));

    return solve(n, k, memo);
  }
};

class TopDown {
private:
  const int MOD = 1e9 + 7;

public:
  int kInversePairs(int n, int k) {
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {   // size
      for (int j = 1; j <= k; j++) { // K

        for (int x = 0; x <= min(j, i - 1); x++) {
          dp[i][j] += dp[i - 1][j - x];
          dp[i][j] %= MOD;
        }
      }
    }

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        cout << dp[i][j] << " ";
      }

      cout << endl;
    }

    return dp[n][k];
  }
};

int main() {
  TopDown s;

  s.kInversePairs(4, 2);
}
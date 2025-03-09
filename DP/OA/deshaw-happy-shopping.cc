// Understanding :- You are given an array of size N name cost[i] ; you are also
// given happy[i] ; max[i] ; min[i] ; m-> total budget

// Do shopping in such a way such that you get maximum happiness in the given
// money

#include <vector>

using namespace std;

int maxHappiness(vector<int> &cost, vector<int> &happy, vector<int> &mini,
                 vector<int> &maxi, int m) {

  int n = cost.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      for (int k = mini[cost[i - 1]]; k <= maxi[cost[i - 1]]; k++) {
        int t = cost[i - 1] * k;
        if (t <= j) {
          dp[i][j] = max(dp[i][j], happy[i - 1] * k + dp[i - 1][j - t]);
        }
      }
    }
  }

  return dp[n][m];
}
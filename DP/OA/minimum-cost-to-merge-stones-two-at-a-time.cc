#include <vector>

using namespace std;

int minCostToMergeStonesTwoAtATime(vector<int> &stones) {
  int n = stones.size();

  vector<int> prefixSum(n, 0);

  prefixSum[0] = stones[0];
  for (int i = 1; i < n; i++) {
    prefixSum[i] = stones[i] + prefixSum[i - 1];
  }

  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int i = 0; i < n - 1; i++) {
    dp[i][i + 1] = stones[i] + stones[i + 1];
  }

  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;

      int psum = prefixSum[j] - prefixSum[i] + stones[i];

      dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + psum;
    }
  }

  return dp[0][n - 1];
}
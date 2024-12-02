#include <algorithm>
#include <vector>
using namespace std;

class MemoizedSolution {
  int maxProfit(vector<vector<int>> &memo, vector<int> &weights,
                vector<int> &val, int wt, int n) {
    if (n == 0 || wt == 0)
      return 0;

    if (memo[wt][n] != -1)
      return memo[wt][n];

    if (weights[n - 1] <= wt) {
      return memo[wt][n] =
                 max(val[n - 1] + maxProfit(memo, weights, val,
                                            wt - weights[n - 1], n - 1),
                     maxProfit(memo, weights, val, wt, n - 1));
    } else {

      return memo[wt][n] = maxProfit(memo, weights, val, wt, n - 1);
    }
  }

  int knapSack(int capacity, vector<int> &val, vector<int> &weights) {
    vector<vector<int>> memo(capacity + 1, vector<int>(val.size() + 1, -1));

    return maxProfit(memo, weights, val, capacity, val.size());
  }
};

class TopDownSolution {
  int knapSack(int capacity, vector<int> &val, vector<int> &weights) {
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
      for (int wt = 1; wt <= capacity; wt++) {
        if (weights[i - 1] <= wt) {
          dp[i][wt] =
              max(val[i - 1] + dp[i - 1][wt - weights[i - 1]], dp[i - 1][wt]);
        } else {
          dp[i][wt] = dp[i - 1][wt];
        }
      }
    }
    return dp[n][capacity];
  }
};

#include <climits>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> val;
  int memo[102][102];

  int f(int i, int j) {
    if (i == j)
      return memo[i][j] = 0;

    if (memo[i][j] != -1) {
      return memo[i][j];
    }

    int minCost = INT_MAX;
    for (int k = i; k < j; k++) {
      int cost = val[i - 1] * val[k] * val[j];
      minCost = min(minCost, cost + f(i, k) + f(k + 1, j));
    }

    return memo[i][j] = minCost;
  }

  int matrixMultiplication(vector<int> &arr) {
    memset(memo, -1, sizeof(memo));
    val = arr;

    return f(0, arr.size() - 1);
  }
};

class TopDown {
public:
  int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int i = n - 1; i >= 1; i--) {
      for (int j = i + 1; j < n; j++) {
        dp[i][j] = 1e9;

        for (int k = i; k < j; k++) {
          int cost = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[i + 1][j];
          dp[i][j] = min(dp[i][j], cost);
        }
      }
    }

    return dp[1][n - 1];
  }
};

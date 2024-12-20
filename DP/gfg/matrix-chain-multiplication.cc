#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  int memo[102][102];

  int solve(vector<int> arr, int i, int j, int n) {

    if (memo[i][j] != -1)
      return memo[i][j];
    if (i == j)
      return memo[i][j] = 0;

    int mini = 1e9;

    for (int k = i; k < j; k++) {
      int cost = arr[i - 1] * arr[k] * arr[j];
      int min_cost = cost + solve(arr, i, k, n) + solve(arr, k + 1, j, n);
      mini = min(min_cost, mini);
    }
    return memo[i][j] = mini;
  }

  int matrixMultiplication(vector<int> &arr) {
    memset(memo, -1, sizeof(memo));
    return solve(arr, 1, arr.size() - 1, arr.size());
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

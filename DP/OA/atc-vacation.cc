// link -> https://atcoder.jp/contests/dp/tasks/dp_c

#include <vector>

using namespace std;

int maxPoints(vector<vector<int>> &points) {
  int n = points.size();
  vector<vector<int>> dp(n, vector<int>(3, 0));

  dp[0][0] = points[0][0];
  dp[0][1] = points[0][1];
  dp[0][2] = points[0][2];

  for (int i = 1; i < n; i++) {
    for (int p = 0; p < 3; p++) {
      if (p == 0) {
        dp[i][p] += points[i][p] + max(dp[i - 1][1], dp[i - 1][2]);
      } else if (p == 1) {
        dp[i][p] += points[i][p] + max(dp[i - 1][0], dp[i - 1][2]);
      } else {
        dp[i][p] += points[i][p] + max(dp[i - 1][1], dp[i - 1][0]);
      }
    }
  }

  return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}
#include <climits>
#include <cstring>
#include <vector>

using namespace std;
class Solution {
public:
  int solve(int e, int f, vector<vector<int>> &dp) {
    if (f == 0 || f == 1)
      return f;
    if (e == 1)
      return f;

    if (dp[e][f] != -1)
      return dp[e][f];

    int mn = 1e9;
    for (int k = 1; k <= f; k++) {
      int breakCase = solve(e - 1, k - 1, dp);
      int noBreakCase = solve(e, f - k, dp);
      int temp = 1 + max(breakCase, noBreakCase);
      mn = min(mn, temp);
    }

    return dp[e][f] = mn;
  }

  int superEggDrop(int k, int n) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    return solve(k, n, dp);
  }
};

class Tabulation_solution {
public:
  int superEggDrop(int k, int n) {
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= k; i++) {
      dp[i][0] = 0;
      dp[i][1] = 1;
    }

    for (int i = 0; i <= n; i++) {
      dp[0][i] = 1e9 + 7;
      dp[1][i] = i;
    }

    for (int egg = 2; egg <= k; egg++) {
      for (int N = 2; N <= n; N++) {
        dp[egg][N] = INT_MAX;

        for (int floor = 2; floor <= N; floor++) {
          int temp = 1 + max(dp[egg - 1][floor - 1], dp[egg][N - floor]);
          dp[egg][N] = min(dp[egg][N], temp);
        }
      }
    }

    return dp[k][n];
  }
};
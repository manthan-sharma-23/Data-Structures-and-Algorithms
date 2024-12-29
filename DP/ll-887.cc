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
        int ans = 1e9;
        int l = 1;
        int r = N;

        while (l <= r) {
          int mid = (l + r) / 2;
          int breaks = 1 + dp[egg - 1][mid - 1];
          int not_break = 1 + dp[egg][N - mid];

          ans = min(ans, max(breaks, not_break));

          if (breaks == not_break)
            break;

          if (breaks > not_break) {
            r = mid - 1;
          }
          if (not_break > breaks) {
            l = mid + 1;
          }
        }

        dp[egg][N] = ans;
      }
    }

    return dp[k][n];
  }
};
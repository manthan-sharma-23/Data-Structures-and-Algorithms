
#include <string>
#include <vector>

using namespace std;

//  recurse dfs
class Solution {
public:
  vector<vector<int>> memo;
  int solve(string m, string n, int i, int j) {
    if (i < 0 || j < 0)
      return 0;

    string key = to_string(i) + "_" + to_string(j);

    if (memo[i][j] != -1)
      return memo[i][j];

    if (m[i] == n[j]) {
      return 1 + solve(m, n, i - 1, j - 1);
    }

    return memo[i][j] = max(solve(m, n, i - 1, j), solve(m, n, i, j - 1));
  }

  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
    return solve(text1, text2, m - 1, n - 1);
  }
};

class TopDownDP {
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[m][n];
  }
};
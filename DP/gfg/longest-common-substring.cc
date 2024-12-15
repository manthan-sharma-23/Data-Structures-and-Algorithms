
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> memo;

  int solve(string &s1, string &s2, int m, int n, int count) {
    if (m == 0 || n == 0)
      return count;

    if (memo[m][n] != -1)
      return memo[m][n];

    if (s1[m - 1] == s2[n - 1]) {
      count = solve(s1, s2, m - 1, n - 1, count + 1);
    }

    int count1 = solve(s1, s2, m, n - 1, 0);
    int count2 = solve(s1, s2, m - 1, n, 0);

    return memo[m][n] = max(count, max(count1, count2));
  }

  int longestCommonSubstr(string &s1, string &s2) {
    memo =
        vector<vector<int>>(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    return solve(s1, s2, s1.length(), s2.length(), 0);
  }
};

class TopDownDP {
public:
  int longestCommonSubstr(string &s1, string &s2) {
    int n = s1.length(), m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLen = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          maxLen = max(maxLen, dp[i][j]);
        } else {
          dp[i][j] = 0;
        }
      }
    }

    return maxLen;
  }
};

#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

class Recurse {
public:
  int memo[501][501];
  int solve(string &s, int i, int j) {
    if (memo[i][j] != -1)
      return memo[i][j];

    if (i >= j)
      return 0;

    if (s[i] == s[j])
      return memo[i][j] = solve(s, i + 1, j - 1);

    return memo[i][j] = 1 + min(solve(s, i + 1, j), solve(s, i, j - 1));
  }

  int minInsertions(string &s) {
    memset(memo, -1, sizeof(memo));
    return solve(s, 0, s.length() - 1);
  }
};

class Solution {
public:
  int minInsertions(string s) {
    int n = s.length();
    string t = s;
    reverse(t.begin(), t.end());

    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = i + j;
        } else if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[n][n];
  }
};
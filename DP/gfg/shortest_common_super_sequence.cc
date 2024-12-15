#include <string>
#include <vector>

using namespace std;

class RecursionMemoSolution {
public:
  vector<vector<int>> memo;
  int solve(string s1, string s2, int i, int j) {
    if (memo[i][j] != -1)
      return memo[i][j];

    if (i == s1.length() || j == s2.length()) {
      return s1.substr(i).length() + s2.substr(j).length();
    }

    if (s1[i] == s2[j]) {
      return memo[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
    }

    int plus_i = 1 + solve(s1, s2, i + 1, j);
    int plus_j = 1 + solve(s1, s2, i, j + 1);

    return memo[i][j] = min(plus_i, plus_j);
  }

  int shortestCommonSupersequence(string &s1, string &s2) {
    memo =
        vector<vector<int>>(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    return solve(s1, s2, 0, 0);
  }
};

class TopDown {
public:
  int shortestCommonSupersequence(string &s1, string &s2) {
    int n = s1.length(), m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = i + j;
        } else if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }

    return dp[n][m];
  }
};
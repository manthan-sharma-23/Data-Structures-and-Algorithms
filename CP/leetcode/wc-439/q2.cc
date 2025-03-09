#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int canBeConverted(char a, char b) {
    int d = abs(a - b);
    return min(d, 26 - d);
  }

  int longestPalindromicSubsequence(string s, int k) {
    int n = s.length();

    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(n, vector<int>(k + 1, 0)));

    for (int i = 0; i < n; i++) {
      for (int c = 0; c <= k; c++) {
        dp[i][i][c] = 1;
      }
    }

    for (int len = 2; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;

        for (int c = 0; c <= k; c++) {
          if (s[i] == s[j]) {
            dp[i][j][c] = 2 + dp[i + 1][j - 1][c];
          } else {

            int cost = canBeConverted(s[i], s[j]);

            int t = (cost <= c) ? (2 + dp[i + 1][j - 1][c - cost]) : 0;

            dp[i][j][c] = max(max(dp[i][j - 1][c], dp[i + 1][j][c]), t);
          }
        }
      }
    }

    return dp[0][n - 1][k];
  }
};
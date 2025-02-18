#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
  int countPS(string &s) {
    int n = s.length();

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
    }

    for (int length = 2; length <= n; length++) {
      for (int i = 0; i <= n - length; i++) {
        int j = i + length - 1;

        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
        } else {
          dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
      }
    }

    return dp[0][n - 1];
  }
};

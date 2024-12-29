#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
  int countPalindromicSubsequences(string s) {
    int n = s.length();
    const int MOD = 1e9 + 7;

    long long int dp[n + 1][n + 1];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
      dp[i][i] = 1;

    for (int i = n - 1; i > 0; i--) {
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j]) {
          dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] + 1) % MOD;
        } else {
          dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]) % MOD;
        }
      }
    }

    return (dp[0][n - 1]) % MOD;
  }
};
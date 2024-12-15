#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minOperations(string &s1, string &s2) {
    int n = s1.length(), m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxLen = INT_MIN;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          maxLen = max(maxLen, dp[i][j]);
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return (s1.length() - maxLen) + (s2.length() - maxLen);
  }
};
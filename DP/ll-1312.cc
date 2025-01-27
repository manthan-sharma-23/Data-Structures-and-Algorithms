#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

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
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return n - dp[n][n];
  }
};
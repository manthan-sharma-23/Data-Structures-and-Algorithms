
#include <cstring>
#include <string>

using namespace std;

// O(n)
class Solution {
public:
  bool isSubsequence(string s, string t) {
    int i = s.length() - 1, j = t.length() - 1;

    while (i >= 0 && j >= 0) {
      if (s[i] == t[j]) {
        i--;
        j--;
      } else {
        j--;
      }
    }

    return i < 0;
  }
};

// O(n^2)
class TopDown {
public:
  bool isSubsequence(string s, string t) {
    int n = s.length();
    int m = t.length();

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[n][n] == s.length();
  }
};
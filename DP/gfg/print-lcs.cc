#include <string>
#include <vector>

using namespace std;
string print_lc(string s1, string s2) {
  int n = s1.length(), m = s2.length();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  string s = "";
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      s.push_back(s1[i - 1]);
      i--;
      j--;
    } else {
      if (dp[i - 1][j] > dp[i][j - 1]) {
        i--;
      } else {
        j--;
      }
    }
  }

  string res = "";

  for (int i = s.length() - 1; i > 0; i--) {
    res.push_back(s[i]);
  }

  return res;
}
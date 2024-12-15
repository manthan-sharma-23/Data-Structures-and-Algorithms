#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  unordered_map<string, int> memo;

  int dfs(string s) {
    if (memo.find(s) != memo.end())
      return memo[s];
    if (s.length() == 1) {
      return memo[s] = 1;
    }
    if (s.empty()) {
      return memo[s] = 0;
    }

    if (s[0] == s[s.length() - 1]) {

      return memo[s] = 2 + dfs(s.substr(1, s.length() - 2));
    } else {
      return memo[s] = max(dfs(s.substr(1)), dfs(s.substr(0, s.length() - 1)));
    }
  }

public:
  int longestPalindromeSubseq(string s) { return dfs(s); }
};

class TopDownSolution {
public:
  int longestPalindromeSubseq(string s) {
    int n = s.length();
    string a = s;
    string b = s;

    reverse(b.begin(), b.end());

    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    int maxLen = -1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i - 1] == b[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          maxLen = max(maxLen, dp[i][j]);
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return maxLen;
  }
};

#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int memo[1002][1002];
  bool isPalindrome(string &s, int i, int j) {
    while (i <= j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }

  int solve(string &s, int i, int j) {
    if (memo[i][j] != -1)
      return memo[i][j];
    if (i > j)
      return 0;

    if (isPalindrome(s, i, j)) {
      return 1;
    }

    int min_ = 1e9;
    for (int k = i; k < j; k++) {
      int temp = solve(s, i, k) + solve(s, k + 1, j);
      min_ = min(min_, temp);
    }

    return memo[i][j] = min_;
  }

  int palindromicPartition(string &s) {
    memset(memo, -1, sizeof(memo));
    return solve(s, 0, s.length() - 1) - 1;
  }
};

class TDSolution {
public:
  int palindromicPartition(string s) {
    int n = s.length();
    if (n <= 1)
      return 0;

    // Precompute palindromic substrings
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    for (int len = 1; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        if (s[i] == s[j] && (len <= 2 || isPal[i + 1][j - 1])) {
          isPal[i][j] = true;
        }
      }
    }

    // Min cuts DP array
    vector<int> dp(n, 1e9);
    for (int i = 0; i < n; i++) {
      if (isPal[0][i]) {
        dp[i] = 0; // No cuts needed if s[0:i] is a palindrome
      } else {
        for (int j = 0; j < i; j++) {
          if (isPal[j + 1][i]) {
            dp[i] = min(dp[i], dp[j] + 1);
          }
        }
      }
    }

    return dp[n - 1];
  }
};

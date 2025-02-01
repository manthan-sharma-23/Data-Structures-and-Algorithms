#include <climits>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int memo[2001][2001];

  bool isPalindrome(string &s, int i, int j) {
    while (i <= j)
      if (s[i++] != s[j--])
        return 0;
    return 1;
  }

  int f(string &s, int i, int j) {
    if (isPalindrome(s, i, j)) {
      return 0;
    }

    if (memo[i][j] != -1) {
      return memo[i][j];
    }

    int minCuts = INT_MAX;

    for (int k = i; k < j; k++) {
      int cuts = 1 + f(s, i, k) + f(s, k + 1, j);
      minCuts = min(minCuts, cuts);
    }

    return memo[i][j] = minCuts;
  }

  int minCut(string s) {
    memset(memo, -1, sizeof(memo));
    if (s.length() <= 1)
      return 0;

    return f(s, 0, s.length() - 1);
  }
};

class TDSolution {
public:
  int minCut(string s) {
    int n = s.length();

    bool isPalindrome[n][n];
    memset(isPalindrome, false, sizeof(isPalindrome));

    for (int i = 0; i < n; i++)
      isPalindrome[i][i] = true;

    for (int i = 0; i < n - 1; i++)
      isPalindrome[i][i + 1] = (s[i] == s[i + 1]);

    for (int len = 3; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
      }
    }

    int dp[n];
    memset(dp, INT_MAX, sizeof(dp));

    for (int i = 0; i < n; i++) {
      if (isPalindrome[0][i]) {
        dp[i] = 0;
      } else {
        dp[i] = 1e9;
        for (int j = 0; j < i; j++) {
          if (isPalindrome[j + 1][i] && 1 + dp[j] < dp[i]) {
            dp[i] = 1 + dp[j];
          }
        }
      }
    }

    return dp[n];
  }
};
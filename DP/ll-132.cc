#include <climits>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isPalindrome(const string &s, int i, int j) {
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }

  int solve(const string &s, int i, int n, vector<int> &dp) {
    if (i == n) {
      return 0;
    }

    if (dp[i] != -1) {
      return dp[i];
    }

    int min_cost = INT_MAX;

    for (int k = i; k < n; k++) {
      if (isPalindrome(s, i, k)) {
        int cost = 1 + solve(s, k + 1, n, dp);
        min_cost = min(min_cost, cost);
      }
    }

    return dp[i] = min_cost;
  }

  int minCut(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    return solve(s, 0, n, dp) - 1;
  }
};

class TDSolution {
public:
  int minCut(string s) {
    int n = s.length();
    bool palindrome[n + 1][n + 1];
    memset(palindrome, false, sizeof(palindrome));

    for (int i = 0; i <= n; i++)
      palindrome[i][i] = true;

    for (int L = 2; L <= n; L++) {
      for (int i = 0; i < n - L + 1; i++) {
        int j = i + L - 1;

        if (L == 2) {
          palindrome[i][j] = (s[i] == s[j]);
        } else {
          palindrome[i][j] = ((s[i] == s[j]) && palindrome[i + 1][j - 1]);
        }
      }
    }

    int dp[n];
    memset(dp, 1e9, sizeof(dp));

    for (int i = 0; i < n; i++) {
      if (palindrome[0][i]) {
        dp[i] = 0;
      } else {
        dp[i] = 1e9;
        for (int j = 0; j < i; j++) {
          if (palindrome[j + 1][i] && (1 + dp[j] < dp[i])) {
            dp[i] = 1 + dp[n];
          }
        }
      }
    }

    return dp[n];
  }
};
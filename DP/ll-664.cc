#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  typedef long long ll;
  int strangePrinter(string s) {
    int n = s.length();

    vector<vector<ll>> dp(n, vector<ll>(n, INT_MAX));

    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;

        for (int k = i; k < j; k++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
        if (s[i] == s[j])
          dp[i][j]--;
      }
    }

    return dp[0][n - 1];
  }
};
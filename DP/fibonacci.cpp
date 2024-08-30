#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
  int solve(int n, vector<int> &dp) {
    if (n <= 1) {
      return n;
    }
    if (dp[n] != -1) {
      return dp[n];
    }

    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
  }

  int fib(int n) {
    if (n <= 1) {
      return n;
    }

    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    dp[1] = 1;
    return solve(n, dp);
  }
};

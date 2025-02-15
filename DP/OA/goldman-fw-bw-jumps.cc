//  link -> https://www.desiqna.in/13008/goldman-sachs-sde-oa-ctc-30-lac-2023-dp
#include <bits/stdc++.h>

using namespace std;

/*
    we can only make a one backword move

*/

int minCost(vector<int> &nums) {
  int n = nums.size();
  const int fw = 1, bw = 0;

  vector<vector<int>> dp(n, vector<int>(2, INT_MAX));

  dp[0][fw] = nums[0];
  dp[0][bw] = INT_MAX;

  for (int i = 1; i < n; i++) {
    if (i > 1) {
      dp[i][fw] = nums[i] + min(dp[i - 1][bw], dp[i - 1][fw]);
    }

    dp[i][bw] = nums[i] + dp[i - 1][fw] + nums[i + 1];
  }

  return min(dp[n - 1][fw], min(dp[n - 2][fw], dp[n - 2][bw]));
}
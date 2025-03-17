// link ->
// https://drive.google.com/file/d/1lPahwo4e6R5nB8w5au0gb9AAiqpcRyNh/view

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int minSum(vector<int> &nums, int k) {
  int n = nums.size();

  if (n < k)
    return -1;

  vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));

  for (int i = 1; i <= n; i++) {
    int maxi = *max_element(nums.begin(), nums.begin() + i);
    dp[i][1] = maxi;
  }

  for (int part = 2; part <= k; part++) {
    for (int i = part; i <= n; i++) {
      int maxi = nums[i - 1];
      for (int cut = i - 1; cut >= part - 1; cut--) {
        dp[i][part] = max(dp[i][part], maxi + dp[cut][part - 1]);
        maxi = max(maxi, nums[cut - 1]);
      }
    }
  } 

  return dp[n][k];
}
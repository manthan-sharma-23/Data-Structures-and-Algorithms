#include <climits>
#include <vector>

using namespace std;

/*
Given an array of size ‘N’; find the number of ways to partition it such that
the sum of each part is <=M ; but you should only make k partitions!
*/

int numWays(vector<int> &nums, int M, int k) {
  int n = nums.size();

  vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MIN));
  vector<int> prefix(n + 1, 0);

  prefix[0] = nums[0];

  for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + nums[i - 1];
  }

  dp[0][0] = 1;

  for (int parts = 1; parts <= k; parts++) {
    for (int i = parts; i <= n; i++) {
      for (int j = i - 1; j >= parts - 1; j--) {
        if (prefix[i] - prefix[j] <= M) {
          dp[i][parts] += dp[j - 1][parts - 1];
        }
      }
    }
  }

  return dp[n][k];
}

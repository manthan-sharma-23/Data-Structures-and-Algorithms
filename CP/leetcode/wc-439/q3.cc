#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSum(vector<int> &nums, int k, int m) {
    int n = nums.size();

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + nums[i - 1];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1e5));

    for (int i = 0; i <= n; i++)
      dp[i][0] = 0;

    for (int part = 1; part <= k; part++) {
      int b = -1e7;
      for (int i = 1; i <= n; i++) {
        dp[i][part] = dp[i - 1][part];

        if (i - m >= 0)
          b = max(b, pref[i] - pref[i - m] + dp[i - m][part - 1]);

        dp[i][part] = max(dp[i + 1][part], b);
      }
    }

    return dp[n][k];
  }
};
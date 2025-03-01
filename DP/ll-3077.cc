#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  typedef long long ll;
  long long maximumStrength(vector<int> &nums, int k) {
    int n = nums.size();
    vector<vector<vector<ll>>> dp(
        n + 1, vector<vector<ll>>(k + 1, vector<ll>(2, INT_MIN)));

    dp[0][0][0] = 0;

    for (int part = 0; part <= k; part++) {
      ll y = (k - part + 1) * (part % 2 == 0 ? -1LL : 1LL);

      for (int i = 1; i <= n; i++) {

        dp[i][part][0] = max(dp[i - 1][part][1], dp[i - 1][part][0]);

        dp[i][part][1] =
            max(dp[i][part][1], y * nums[i - 1] + dp[i - 1][part][1]);

        if (part > 0) {
          ll t = y * nums[i - 1] +
                 max(dp[i - 1][part - 1][1], dp[i - 1][part - 1][0]);
          dp[i][part][1] = max(dp[i][part][1], t);
        }
      }
    }

    return max(dp[n][k][1], dp[n][k][0]);
  }
};
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int dp[n + 1][2];

    memset(dp, 0, sizeof(dp));

    for (int i = n - 1; i >= 0; i--) {

      for (int buy = 0; buy <= 1; buy++) {
        int profit;
        if (buy) {
          int take = -prices[i] + dp[i + 1][!buy];
          int notTake = dp[i + 1][buy];
          profit = max(take, notTake);
        } else {
          int take = prices[i] + i < n - 1 ? dp[i + 2][!buy] : 0;
          int notTake = dp[i + 1][buy];
          profit = max(take, notTake);
        }

        dp[i][buy] = profit;
      }
    }

    return dp[0][1];
  }
};
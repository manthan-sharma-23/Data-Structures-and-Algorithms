#include "vector"
#include <cstring>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int dp[n];

    memset(dp, 0, sizeof(dp));

    int minPrice = prices[0];

    for (int i = 1; i < n; i++) {

      minPrice = min(minPrice, prices[i]);
      dp[i] = max(dp[i - 1], prices[i] - minPrice);
    }

    return dp[n - 1];
  }
};
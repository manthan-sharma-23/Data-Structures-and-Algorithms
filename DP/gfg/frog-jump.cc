#include <climits>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
  int minCost(vector<int> &height) {
    int n = height.size();
    if (n <= 1)
      return 0;

    vector<int> dp(n, 1e7);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
      dp[i] = min(dp[i], dp[i - 1] + abs(height[i] - height[i - 1]));

      if (i > 1)
        dp[i] = min(dp[i], dp[i - 2] + abs(height[i] - height[i - 2]));
    }

    return dp[n-1];
  }
};
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int solve(vector<int> price, int index, int profit) {
    if (index == price.size())
      return profit;

    return max(solve(price, index + 1, profit + price[index]),
               solve(price, index + 1, profit));
  }

  int cutRod(vector<int> &price) {
    int n = price.size();
    int maxProfit = accumulate(price.begin(), price.end(), 0);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i <= j) {
          dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i][j - i]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n][n];
  }
};
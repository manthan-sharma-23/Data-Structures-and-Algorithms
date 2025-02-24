#include <climits>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
  double largestSumOfAverages(vector<int> &nums, int k) {
    int n = nums.size();

    vector<double> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    vector<vector<double>> dp(n + 1, vector<double>(k + 1, -1e8));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      dp[i][1] = prefix[i] / i;
    }

    for (int parts = 2; parts <= k; parts++) {
      for (int i = parts; i <= n; i++) {

        for (int c = i - 1; c >= parts - 1; c--) {
          dp[i][parts] =
              max(dp[i][parts],
                  dp[c][parts - 1] + (prefix[i] - prefix[c]) / abs(i - c));
        }
      }
    }

    return dp[n][k];
  }
};
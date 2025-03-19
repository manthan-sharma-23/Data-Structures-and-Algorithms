#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int maxTotalReward(vector<int> &rewardValues) {

    sort(rewardValues.begin(), rewardValues.end());
    int n = rewardValues.size();
    int tSum = 4000;

    vector<vector<bool>> dp(n + 1, vector<bool>(tSum + 1, 0));

    int res = 0;

    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= tSum; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j - rewardValues[i - 1] >= 0 &&
            j - rewardValues[i - 1] < rewardValues[i - 1]) {
          dp[i][j] = dp[i][j] || dp[i - 1][j - rewardValues[i - 1]];
        }

        if (dp[i][j])
          res = max(res, j);
      }
    }

    return res;
  }
};  
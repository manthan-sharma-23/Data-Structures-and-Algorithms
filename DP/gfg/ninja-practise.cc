#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumPoints(vector<vector<int>> &arr) {
    int days = arr.size();

    vector<vector<int>> dp(days, vector<int>(3, INT_MIN));

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for (int i = 1; i < days; i++) {

      dp[i][0] = arr[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
      dp[i][1] = arr[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
      dp[i][2] = arr[i][2] + max(dp[i - 1][1], dp[i - 1][0]);
    }

    return max(dp[days - 1][0], max(dp[days - 1][1], dp[days - 1][2]));
  }
};


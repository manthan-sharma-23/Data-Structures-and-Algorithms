#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maximumSubarrayXor(vector<int> &nums,
                                 vector<vector<int>> &queries) {
    int n = nums.size();

    int xorScore[n][n];
    int dp[n][n];

    memset(xorScore, 0, sizeof(xorScore));
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
      dp[i][i] = xorScore[i][i] = nums[i];

    for (int len = 2; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;

        xorScore[i][j] = xorScore[i][j - 1] ^ xorScore[i + 1][j];
        dp[i][j] = max(xorScore[i][j], max(dp[i][j - 1], dp[i + 1][j]));
      }
    }

    vector<int> ans;
    for (auto &query : queries) {
      int l = query[0], r = query[1];

      ans.push_back(dp[l][r]);
    }

    return ans;
  }
};
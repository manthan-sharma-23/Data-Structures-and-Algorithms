#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {

    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(queries.size() + 1, 0));

    for (int k = 0; k < queries.size(); k++) {
      int l = queries[k][0];
      int r = queries[k][1];
      int val = queries[k][2];

      for (int i = 0; i < n; i++) {
        int num = nums[i];

        if (i >= l && i <= r) {
          dp[i][k] = min(dp[i][k], dp[i][k - num]);
        }
      }
    }
  }
};
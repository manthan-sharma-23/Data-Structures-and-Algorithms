#include <vector>

using namespace std;

class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int t = 1; t <= target; t++) {
      for (int num : nums) {
        if (t >= num) {
          dp[t] += dp[t - num];
        }
      }
    }

    return dp[target];
  }
};

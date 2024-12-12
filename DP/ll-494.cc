#include <cstdlib>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  unordered_map<string, int> memo;

  int solve(vector<int> nums, int target, int index) {
    string key = to_string(index) + "_" + to_string(target);

    if (memo.find(key) != memo.end())
      return memo[key];
    if (target == 0 && index == nums.size())
      return 1;

    if (index == nums.size())
      return 0;

    return memo[key] = solve(nums, target - nums[index], index + 1) +
                       solve(nums, target + nums[index], index + 1);
  }

  int findTargetSumWays(vector<int> &nums, int target) {

    return solve(nums, target, 0);
  }
};

class BottomUpSolution {

  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2 != 0 || sum < abs(target)) {
      return 0;
    }

    int find = (sum + target) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(find + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= find; j++) {
        if (nums[i - 1] <= j) {
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n][find];
  }
};

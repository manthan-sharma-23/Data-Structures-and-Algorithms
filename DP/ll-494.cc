#include <cstdlib>
#include <cstring>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  const int static offset = 1002;
  int memo[1002][1002 + offset];
  int f(vector<int> &nums, int target, int index, int currSum) {

    if (index == nums.size())
      return target == currSum;

    if (memo[index][currSum + offset] != -1)
      return memo[index][currSum + offset];

    return memo[index][currSum + offset] =
               f(nums, target, index + 1, currSum + nums[index]) +
               f(nums, target, index + 1, currSum - nums[index]);
  }
  int findTargetSumWays(vector<int> &nums, int target) {
    memset(memo, -1, sizeof(memo));
    return f(nums, target, 0, 0);
  }
};

class TopDown {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);

    if ((target + sum) % 2)
      return 0;

    int subset_sum = (target + sum) / 2;

    int dp[n + 1][subset_sum + 1];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++)
      dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= subset_sum; j++) {
        if (nums[i - 1] <= j) {
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n][subset_sum];
  }
};

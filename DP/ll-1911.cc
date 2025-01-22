#include <vector>

using namespace std;

class Solution {
public:
  typedef long long ll;
  vector<vector<ll>> memo;

  ll f(vector<int> &nums, int isEven, int index) {
    if (index >= nums.size()) {
      return 0;
    }

    if (memo[isEven][index] != -1)
      return memo[isEven][index];

    ll pick =
        (isEven ? nums[index] : -nums[index]) + f(nums, 1 - isEven, index + 1);
    ll nonPick = f(nums, isEven, index + 1);

    return memo[isEven][index] = max(pick, nonPick);
  }

  long long maxAlternatingSum(vector<int> &nums) {
    int n = nums.size();
    memo.resize(2, vector<ll>(n, -1));
    return f(nums, 1, 0);
  }
};

class TopDown {
public:
  typedef long long ll;
  long long maxAlternatingSum(vector<int> &nums) {
    int n = nums.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    dp[1][0] = 0;
    dp[1][1] = nums[0];
    for (int i = 2; i < n; i++) {
      dp[i][0] = max(dp[i - 1][1] - nums[i - 1], dp[i - 1][0]);
      dp[i][1] = max(dp[i - 1][0] + nums[i - 1], dp[i - 1][1]);
    }

    return max(dp[n][0], dp[n][1]);
  }
};
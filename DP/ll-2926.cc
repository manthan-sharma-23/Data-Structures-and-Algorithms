#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  long long maxBalancedSubsequenceSum(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    long long ele = *max_element(nums.begin(), nums.end());
    if (ele <= 0)
      return ele;

    vector<long long> dp(n);
    long long max_sum = LLONG_MIN;

    for (int i = 0; i < n; i++) {
      dp[i] = nums[i];
    }

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] - i >= nums[j] - j) {
          dp[i] = max(dp[i], dp[j] + nums[i]);
        }
      }
      max_sum = max(max_sum, dp[i]);
    }

    return max_sum;
  }
};

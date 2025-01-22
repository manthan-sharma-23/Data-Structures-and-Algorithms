#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {

    int n = nums.size();
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[i - 1] + 1);
        }
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};
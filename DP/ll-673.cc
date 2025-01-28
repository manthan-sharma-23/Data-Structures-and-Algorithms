#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {

    int n = nums.size();

    if (n == 0)
      return 0;

    vector<int> dp(n, 1);
    vector<int> count(n, 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            count[i] = count[j];
          } else if (dp[j] + 1 == dp[i]) {
            count[i]++;
          }
        }
      }
    }

    int maxLength = *max_element(dp.begin(), dp.end());

    int num = 0;

    for (int i = 0; i < n; i++) {
      if (dp[i] == maxLength) {
        num += count[i];
      }
    }

    return num;
  }
};
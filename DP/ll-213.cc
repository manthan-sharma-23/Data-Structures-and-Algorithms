#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();

    int dp1_0 = 0;
    int dp1_1 = 0;

    for (int i = 2; i <= n; i++) {
      int temp = dp1_1;
      dp1_1 = max(dp1_0 + nums[i - 1], dp1_1);
      dp1_0 = temp;
    }

    vector<int> dp2(n, 0);

    int dp2_0 = 0;
    int dp2_1 = nums[0];

    for (int i = 2; i < n; i++) {
      int temp = dp2_1;
      dp2_1 = max(dp2_0 + nums[i - 1], dp2_1);
      dp2_0 = temp;
    }

    return max(dp2_1, dp1_1);
  }
};
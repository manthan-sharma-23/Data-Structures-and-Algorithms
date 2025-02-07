#include <vector>

using namespace std;

//  kadane's algorithm
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();

    int maxSum = nums[0];
    int current = nums[0];

    for (int i = 1; i < n; i++) {
      current = max(current + nums[i], max(nums[i], 0));
      maxSum = max(maxSum, current);
    }

    return maxSum;
  }
};
#include <climits>
#include <vector>

using namespace std;

// Amazon OA -> Given an array find two subarrays of maximum sum which are not
// intersecting

int maxSum(vector<int> nums) {
  int n = nums.size();

  vector<int> maxPrefix(n, 0);
  vector<int> maxSuffix(n, 0);

  maxPrefix[0] = nums[0];
  int current = nums[0];
  for (int i = 1; i < n; i++) {
    current = max(nums[i], current + nums[i]);
    maxPrefix[i] = max(maxPrefix[i - 1], current);
  }

  maxSuffix[n - 1] = nums[n - 1];
  current = nums[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    current = max(nums[i], current + nums[i]);
    maxSuffix[i] = max(maxSuffix[i + 1], current);
  }

  int gSum = INT_MIN;

  for (int i = 0; i < n - 1; i++) {
    gSum = max(gSum, maxPrefix[i] + maxSuffix[i + 1]);
  }

  return gSum;
}
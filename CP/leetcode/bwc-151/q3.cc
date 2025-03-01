#include <climits>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> memo;
  int f(vector<int> nums, int i, int prev) {
    int n = nums.size();

    if (i == n) {
      return memo[i][prev] = nums[prev];
    }

    if (i + 1 == n) {
      return memo[i][prev] = max(nums[n - 1], nums[prev]);
    }

    if (memo[i][prev] != -1)
      return memo[i][prev];

    int a1 = max(nums[i], nums[i + 1]) + f(nums, i + 2, prev);
    int a2 = max(nums[i], nums[prev]) + f(nums, i + 2, i + 1);
    int a3 = max(nums[i + 1], nums[prev]) + f(nums, i + 2, i);

    return memo[i][prev] = min(a1, min(a2, a3));
  }

  int minCost(vector<int> &nums) {
    int n = nums.size();

    if (n == 1)
      return nums[0];

    if (n == 2) {
      return max(nums[0], nums[1]);
    }

    memo.resize(n + 1, vector<int>(n + 1, -1));
    int minC = INT_MAX;

    minC = min(minC, max(nums[0], nums[1]) + f(nums, 3, 2));
    minC = min(minC, max(nums[0], nums[2]) + f(nums, 3, 1));
    minC = min(minC, max(nums[2], nums[1]) + f(nums, 3, 0));

    return minC;
  }
};
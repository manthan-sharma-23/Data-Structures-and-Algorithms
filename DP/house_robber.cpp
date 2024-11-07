#include <algorithm>
#include <climits>
#include <vector>

// [2,5,3,7]

class Solution {
  int global_max = INT_MIN;

  int recurse(std::vector<int> nums, int it) {
    int in_take, not_take;

    if (it >= nums.size()) {
      return 0;
    }

    in_take = nums[it] + recurse(nums, it + 2);

    not_take = recurse(nums, it + 1);

    return std::max(in_take, not_take);
  }

public:
  int rob(vector<int> &nums) { std::vector<int> res; }
};

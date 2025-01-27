#include <climits>
#include <cstdlib>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int Range;

  int f(vector<int> &nums, int sum, int count, int index) {
    if (index == nums.size()) {
      if (count >= nums.size()) {
        return INT_MAX;
      }
      int mindiff = abs(Range - 2 * sum);

      return mindiff;
    }

    int take = f(nums, sum + nums[index], count + 1, index + 1);

    int notTake = f(nums, sum, count, index + 1);

    return min(take, take);
  }

  int minimumDifference(vector<int> &nums) {
    int n = nums.size();
    Range = accumulate(nums.begin(), nums.end(), 0);

    return f(nums, 0, 0, 0);
  }
};

#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int waysToSplitArray(vector<int> &nums) {
    int n = nums.size();
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);

    int split{0};
    long long left = 0;
    long long right = sum;
    for (int i = 0; i < n - 1; i++) {
      left += nums[i];
      right -= nums[i];

      if (left >= right) {
        split++;
      }
    }

    return split;
  }
};

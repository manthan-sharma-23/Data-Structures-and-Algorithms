#include <vector>

using namespace std;

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int n = nums.size();

    int count = 0, i = 0;
    long long prod = 1;

    for (int j = 0; j < n; j++) {
      prod *= nums[j];

      while (prod >= k && i < n)
        prod /= nums[i++];

      if (i <= j && prod < k)
        count += j - i + 1;
      else {
        prod = 1;
        i = j--;
      }
    }

    return max(count, 0);
  }
};
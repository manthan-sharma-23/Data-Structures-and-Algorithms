#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    int n = nums.size();

    int maxi = *max_element(nums.begin(), nums.end());

    int countMaxi = 0, count = 0, i = 0;

    for (int j = 0; j < n; j++) {
      if (nums[j] == maxi)
        countMaxi++;

      while (countMaxi > k) {
        if (nums[i] == maxi) {
          countMaxi--;
        }
        i++;
      }

      if (countMaxi == k) {
        count += n - j;
      }
    }

    return count;
  }
};
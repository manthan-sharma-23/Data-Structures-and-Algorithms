#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();
    int maxP = INT_MIN;

    int pref = 1, suff = 1;

    for (int i = 0; i < n; i++) {
      int j = n - i - 1;

      if (nums[i] == 0)
        pref = 1;
      if (nums[j] == 0)
        suff = 1;

      pref *= nums[i];
      suff *= nums[j];

      maxP = max(maxP, max(pref, suff));
    }

    return maxP;
  }
};
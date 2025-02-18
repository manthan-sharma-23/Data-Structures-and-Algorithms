#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubarrayLength(vector<int> &nums, int k) {
    int n = nums.size();

    //  num , freq
    unordered_map<int, int> mp;

    int len = 0;
    int i = 0;
    for (int j = 0; j < n; j++) {
      mp[nums[j]]++;

      while (mp[nums[j]] > k)
        mp[nums[i--]]--;

      len = max(len, j - i + 1);
    }

    return len;
  }
};
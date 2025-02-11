#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int atMostK(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;

    int i = 0;
    int count = 0;

    for (int j = 0; j < n; j++) {
      mp[nums[j]]++;

      int d = mp.size();
      while (d > k) {
        mp[nums[i]]--;
        if (mp[nums[i]] == 0)
          mp.erase(nums[i]);

        d = mp.size();
        i++;
      }

      count += (j - i + 1);
    }

    return count;
  }

  int subarraysWithKDistinct(vector<int> &nums, int k) {

    return atMostK(nums, k) - atMostK(nums, k - 1);
  }
};
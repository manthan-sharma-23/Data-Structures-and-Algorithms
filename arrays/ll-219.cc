#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> hash;

    for (int i = 0; i <= k; i++) {
      if (hash[nums[i]] == 1)
        return true;

      hash[nums[i]]++;
    }

    int j = k;
    for (int i = 1; i < n - k; i++) {
      hash[nums[i - 1]]--;
      j += 1;

      if (hash[nums[j]] == 1)
        return true;

      hash[nums[j]]++;
    }

    return false;
  }
};
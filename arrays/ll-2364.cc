#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  long long countBadPairs(vector<int> &nums) {
    unordered_map<int, int> mp;
    int n = nums.size();

    for (int i = 0; i < nums.size(); i++) {
      mp[nums[i] - i]++;
    }

    int goodPairs = 0;

    for (auto [u, f] : mp) {
      goodPairs += f * (f - 1) / 2;
    }

    int allPairs = n * (n - 1) / 2;

    return allPairs - goodPairs;
  }
};
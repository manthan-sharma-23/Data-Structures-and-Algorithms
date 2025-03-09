#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int findLargestUnique(vector<int> &nums, int k){
    unordered_map<int, int> freq;
    int n = nums.size();

    for (int i = 0; i <= n - k; ++i) {
      unordered_set<int> uniqueSet(nums.begin() + i,
                                   nums.begin() + i + k);
      for (int num : uniqueSet) {
        freq[num]++;
      }
    }

    int maxUnique = -1;
    for (const auto &entry : freq) {
      if (entry.second == 1) {
        maxUnique = max(maxUnique, entry.first);
      }
    }

    return maxUnique;
  }
};

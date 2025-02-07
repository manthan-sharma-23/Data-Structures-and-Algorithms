#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int countKDifference(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> freq;

    int count = 0;

    for (int num : nums) {
      count += freq[num - k] + freq[num + k];
      freq[num]++;

      return count;
    }

    return count;
  }
};
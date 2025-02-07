#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> freq;
    int goal = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] != 0)
        nums[i] = 1;
    }

    freq[0] = 1;

    int sum = 0, count = 0;
    for (int n : nums) {
      sum += n;

      if (freq.find(sum - goal) != freq.end()) {
        count += freq[sum - goal];
      }

      freq[sum]++;
    }

    return count;
  }
};
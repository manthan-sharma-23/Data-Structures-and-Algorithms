#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    unordered_map<int, int> freq;

    int n = nums.size();
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

//   two pointers
int numSubarraysWithSum(vector<int> &nums, int goal) {
  int n = nums.size();

  int sum = 0, count = 0, left = 0;
  for (int right = 0; right < n; right++) {
    sum += nums[right];

    while (sum > goal) {
      sum -= nums[left++];
    }

    if (sum == goal)
      count++;
  }

  return count;
}
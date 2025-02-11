#include <vector>

using namespace std;

class Solution {
public:
  int atMost(vector<int> &nums, int goal) {

    int i = 0, sum = 0;

    int count = 0;

    for (int j = 0; j < nums.size(); j++) {
      sum += nums[j];

      while (sum > goal) {
        sum -= nums[i];
        i++;
      }

      count += (j - i + 1);
    }

    return count;
  }

  int numSubarraysWithSum(vector<int> &nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
  }
};
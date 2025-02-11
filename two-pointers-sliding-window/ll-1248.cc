#include <vector>

using namespace std;

class Solution {
public:
  int atMost(vector<int> &nums, int k) {

    int count = 0;
    int freq = 0, i = 0;

    for (int j = 0; j < nums.size(); j++) {
      freq += (nums[j] % 2 > 0);

      while (freq > k)
        freq -= (nums[i++] % 2 > 0);

      count += (j - i + 1);
    }
  }

  int numberOfSubarrays(vector<int> &nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
  }
};
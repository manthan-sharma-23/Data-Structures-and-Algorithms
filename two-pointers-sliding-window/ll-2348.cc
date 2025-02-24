#include <vector>
using namespace std;

class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    int n = nums.size();

    int count = 0, prev = 0;

    for (int j = 0; j < n; j++) {
      if (nums[j] == 0) {
        prev++;
      } else {
        count += (prev * (prev + 1) / 2);
      }
    }
    count += (prev * (prev + 1) / 2);

    return count;
  }
};
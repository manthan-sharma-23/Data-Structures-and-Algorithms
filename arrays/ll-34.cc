#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int index = -1;
    int n = nums.size();

    int left = 0, right = n - 1;

    while (left <= right) {
      int mid = (left + right) / 2;

      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        index = mid;
        break;
      }
    }

    left = index, right = index;

    while (left > 0) {
      if (nums[left - 1] == target)
        left--;
      else
        break;
    }

    while (right < n - 1) {
      if (nums[right + 1] == target)
        right++;
      else
        break;
    }

    return {left, right};
  }
};
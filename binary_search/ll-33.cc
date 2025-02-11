#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] == target)
        return mid;

      if (nums[mid] >= nums[0]) {
        if (target > nums[mid] || target < nums[0])
          low = mid + 1;
        else
          high = mid - 1;
      } else {
        if (target < nums[mid] || target > nums[n - 1])
          high = mid - 1;
        else
          low = mid + 1;
      }
    }

    return -1;
  }
};
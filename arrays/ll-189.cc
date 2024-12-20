#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int j = 0;
    int n = nums.size();
    k = k % n;
    vector<int> arr(k + 1, 0);

    for (int i = k + 1; i < n; i++) {
      arr[j] = nums[i];
      j++;
    }

    for (int i = 0; i < (n - k); i++) {
      nums[i + k] = nums[i];
    }

    for (int i = 0; i < k; i++) {
      nums[i] = arr[i];
    }
  }
};
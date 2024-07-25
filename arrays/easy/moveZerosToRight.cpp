#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
      int el = nums[i];
      if (el == 0) {
        j++;
      } else {
        nums[i] = 0;
        nums[i - j] = el;
      }
    }
  }
};

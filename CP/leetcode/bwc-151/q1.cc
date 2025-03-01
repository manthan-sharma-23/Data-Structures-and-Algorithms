#include <vector>

using namespace std;

class Solution {
public:
  vector<int> transformArray(vector<int> &nums) {
    int oddCount = 0, evenCount = 0;
    for (int i = 0; i < nums.size(); i++) {
      if ((nums[i] & 1) == 0) {
        evenCount++;
      } else {
        oddCount++;
      }
    }

    vector<int> res;

    while (evenCount--) {
      res.push_back(0);
    }

    while (oddCount--) {
      res.push_back(1);
    }

    return res;
  }
};
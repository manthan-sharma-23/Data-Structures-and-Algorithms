#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSum(vector<int> &nums) {
    int n = nums.size();

    int countNeg = 0;
    map<int, int> mp;

    for (auto num : nums) {
      mp[num]++;
    }

    int posSum = 0;

    for (auto it : mp) {
      if (it.first < 0)
        countNeg++;
      else {
        posSum += it.first;
      }
    }

    if (countNeg < mp.size()) {
      return posSum;
    } else {

      return mp.rbegin()->first;
    }
  }
};
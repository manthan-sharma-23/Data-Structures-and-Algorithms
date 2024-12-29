
#include <climits>
#include <vector>

using namespace std;

class Obvious_Solution {
public:
  void solve(vector<int> &subarray, int count, int index, int k,
             vector<int> &result) {
    if (count == 0)
      return;

    if (index >= subarray.size()) {
      return;
    }

    int take_i=subarray[index]+
  }

  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    vector<int> subarray;

    int i = 0, j = 0;
    int windowSum = 0;

    while (j < nums.size()) {
      windowSum += nums[i];

      if (j - i + 1 == k) {
        subarray.push_back(windowSum);
        windowSum -= nums[i];
        i++;
      }
      j++;
    }

    vector<int> result;
    // solve();

    return result;
  }
};
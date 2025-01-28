#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return {};

    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    vector<int> parent(n, -1);

    int maxSize = 1, maxIndx = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          parent[i] = j;
        }
      }

      if (dp[i] > maxSize) {
        maxSize = dp[i];
        maxIndx = i;
      }
    }

    vector<int> res;
    int curr = maxIndx;
    while (parent[curr] != -1) {
      res.push_back(nums[curr]);
      curr = parent[curr];
    }

    reverse(res.begin(), res.end());

    return res;
  }
};
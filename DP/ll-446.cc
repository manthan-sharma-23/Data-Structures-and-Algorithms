#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  typedef long long ll;
  const int MOD = 1e9 + 7;
  int numberOfArithmeticSlices(vector<int> &nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int maxDiff = nums[n - 1] - nums[0];

    vector<vector<ll>> dp(n, vector<ll>(maxDiff + 1, 0));

    ll ans = 0;
    for (int i = 1; i < n; i++) {
      for (int cut = i - 1; cut >= 0; cut--) {
        int diff = nums[i] - nums[cut];
        dp[nums[i]][diff] += (dp[cut][diff] + 1);
      }
    }

    return ans;
  }
};
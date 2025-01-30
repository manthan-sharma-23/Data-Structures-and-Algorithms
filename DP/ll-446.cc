#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &nums) {
    typedef long long ll;
    int n = nums.size();

    vector<unordered_map<ll, ll>> dp(n);

    ll result = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        ll diff = (ll)(nums[i] - nums[j]);

        ll count = dp[j].count(diff) ? dp[j][diff] : 0;

        dp[i][diff] += dp[j][diff] + 1;
        result += dp[j][diff];
      }
    }
    return result;
  }
};
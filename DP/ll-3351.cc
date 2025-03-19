#include <cstdlib>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  typedef long long ll;
  const int MOD = 1e9 + 7;
  int sumOfGoodSubsequences(vector<int> &nums) {
    int n = nums.size();
    //  tsum , n subsqs
    unordered_map<int, pair<ll, ll>> mp;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
      int n1 = nums[i] + 1, n2 = nums[i] - 1;

      ll tSums = 0LL, tNs = 0LL;

      if (mp.find(n1) != mp.end()) {
        tSums += (mp[n1].first + mp[n1].second * nums[i]);
        tNs += mp[n1].second;
      }
      if (mp.find(n2) != mp.end()) {
        tSums += (mp[n2].first + mp[n2].second * nums[i]);
        tNs += mp[n2].second;
      }

      tSums += nums[i];
      tNs += 1;

      tSums %= MOD, tNs %= MOD;

      if (mp.find(nums[i]) == mp.end()) {
        mp[nums[i]] = {tSums, tNs};
      } else {
        mp[nums[i]].first = (mp[nums[i]].first + tSums) % MOD;
        mp[nums[i]].second = (mp[nums[i]].second + tNs) % MOD;
      }
      ans = (ans + tSums) % MOD;
    }

    return ans % MOD;
  }
};
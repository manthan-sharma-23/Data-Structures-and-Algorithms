#include <algorithm>
#include <bitset>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int n;
  static constexpr int maxBits = 5e4 + 1;
  bitset<maxBits> allVisited;
  typedef long long ll;

  ll f(bitset<maxBits> mask, ll reward, const vector<int> &rewards,
       unordered_map<bitset<maxBits>, ll> &memo) {

    if (mask == allVisited)
      return reward;

    if (memo.find(mask) != memo.end())
      return memo[mask];

    ll R = reward;
    for (int i = 0; i < n; i++) {
      if (mask.)
        continue;
      if (rewards[i] > reward)
        R = max<ll>(R, f(mask.set(i), reward + rewards[i], rewards, memo));
    }

    return memo[mask] = R;
  }

  int maxTotalReward(vector<int> &rewardValues) {
    sort(rewardValues.begin(), rewardValues.end());
    n = rewardValues.size();
    bitset<maxBits> bs;
    unordered_map<bitset<maxBits>, ll> memo;

    int tSum = accumulate(rewardValues.begin(), rewardValues.end(), 0);
    bs.reset();
    return f(bs, 0, rewardValues, memo);
  }
};
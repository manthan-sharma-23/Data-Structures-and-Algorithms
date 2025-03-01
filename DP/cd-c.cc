#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
long long maximumStrength(vector<int> &nums, int m, int k) {
  int n = nums.size();

  vector<int> pref(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + nums[i - 1];
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int part = 1; part <= k; part++) {
      if (i >= m) {
        dp[i][part] =
            max((pref[i] - pref[i - m]) + dp[i - m][part - 1], dp[i - 1][part]);
      } else {
        dp[i][part] = dp[i - 1][part];
      }
    }
  }

  return dp[n][k];
}

int main() {
  int n, m, k;

  cin >> n >> m >> k;

  vector<int> nums(n);

  for (int i = 0; i < n; i++)
    cin >> nums[i];

  cout << maximumStrength(nums, m, k) << endl;
}
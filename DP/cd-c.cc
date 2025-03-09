#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef long long ll;
class Solution {
public:
  ll maxSum(vector<int> &nums, int k, int m) {
    int n = nums.size();
    vector<ll> prefix(n + 1, 0);

    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);

    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, -1e9));

    for (int j = 0; j <= n; j++) {
      dp[0][j] = 0;
    }

    for (int i = 0; i < k; i++) {
      ll best = -1e9;
      for (int j = 0; j <= n; j++) {
        if (j > 0)
          dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - 1]);

        if (j - m >= 0)
          best = max(best, dp[i][j - m] - prefix[j - m]);

        if (best != -1e9)
          dp[i + 1][j] = max(dp[i + 1][j], prefix[j] + best);
      }
    }

    return dp[k][n];
  }
};

int main() {
  int n, m, k;

  cin >> n >> m >> k;

  vector<int> nums(n);

  for (int i = 0; i < n; i++)
    cin >> nums[i];

  Solution s;

  cout << s.maxSum(nums, k, m) << endl;
}
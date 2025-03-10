#include <vector>

using namespace std;

int largestModuloSubsequence(vector<int> &nums, int modulo) {
  int n = nums.size();

  vector<int> dp(n + 1, 1);

  dp[0] = 0;
  dp[1] = 1;

  int maxi = 0;

  for (int k = 0; k < modulo; k++) {
    for (int i = 2; i <= n; i++) {
      for (int j = i - 1; j > 0; j--) {
        if ((nums[j - 1] + nums[i - 1]) % modulo == k) {
          dp[i] = max(dp[i], 1 + dp[j]);
        }
      }
      maxi = max(dp[i], maxi);
    }
  }

  return maxi;
}
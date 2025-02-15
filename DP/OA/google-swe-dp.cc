/*
Find the number of journeys where you start from index 1 and end at index ‘n’
and the sum of every journey should be odd..

-> Similarly find for even.

Allowed to make jumps of size 1 or 2 */

#include <vector>

using namespace std;

//  odd ans , even ans
pair<int, int> countOdd(vector<int> &nums) {
  int n = nums.size();
  int odd = 0, even = 1;

  vector<vector<int>> dp(n, vector<int>(2, 0));

  if (nums[0] % 2 == 0) {
    dp[0][even] = 1;
  } else {
    dp[0][odd] = 1;
  }

  if ((nums[1] + nums[0]) % 2 == 0) {
    dp[1][even] = 1;
    dp[1][odd] = 0;
  } else {
    dp[1][odd] = 1;
    dp[1][even] = 0;
  }

  for (int i = 2; i < n; i++) {
    dp[i][even] = 0, dp[i][odd] = 0;

    if (nums[i] % 2 == 0) {
      dp[i][odd] = dp[i - 2][odd] + dp[i - 1][odd];
      dp[i][even] = dp[i - 1][even] + dp[i - 2][even];
    } else {
      dp[i][odd] = dp[i - 1][even] + dp[i - 2][even];
      dp[i][even] = dp[i - 1][odd] + dp[i - 2][odd];
    }
  }

  return {dp[n - 1][odd], dp[n - 1][even]};
}
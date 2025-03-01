
/*
Find the number of partitions of an array such that each contiguous partition
consists of at least one negative number.

eg. [-2,1,-3] has 3 possible partitions :

-> [-2,1][-3]
-> [-2][1 -3]
->[-2 1 -3]

*/

#include <iostream>
#include <vector>

using namespace std;

int numWays(vector<int> &nums) {
  int n = nums.size();

  nums.insert(nums.begin(), 0);

  vector<int> dp(n + 1, 0);

  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    bool gotNegative = nums[i] < 0 ? 1 : 0;

    for (int cut = i - 1; cut >= 0; cut--) {
      if (gotNegative) {
        dp[i] += dp[cut];
      }

      if (nums[cut] < 0)
        gotNegative = true;
    }
  }

  return dp[n];
}

int numWays_O_n_(vector<int> &nums) {
  int n = nums.size();

  nums.insert(nums.begin(), 0);

  vector<int> dp(n + 1, 0);

  dp[0] = 0;

  int prev = -1;

  for (int i = 1; i <= n; i++) {
    if (nums[i] >= 0) {
      dp[i] = dp[i - 1];
    } else {
      if (prev == -1) {
        prev = i;
        dp[i] = 1;
      } else {
        dp[i] = dp[i - 1] * (i - prev + 1);
        prev = i;
      }
    }
  }

  return dp[n];
}

int main() {
  vector<int> arr = {1, -2, 3, 4, 5, -3, 2};

  cout << numWays(arr) << endl;
}
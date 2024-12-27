#include <cstring>
#include <vector>

using namespace std;

class Recursion_Solution {
public:
  int burst(vector<int> &nums, vector<bool> &bursted) {

    int max_coins{0};
    for (int i = 0; i < nums.size(); i++) {
      if (bursted[i])
        continue;

      int left;
      int ptr = i - 1;
      while (ptr >= -1) {
        if (ptr == -1) {
          left = 1;
          break;
        }
        if (bursted[ptr]) {
          ptr--;
          continue;
        }

        if (nums[ptr] && !bursted[ptr]) {
          left = nums[ptr];
          break;
        } else {
          ptr--;
        }
      }

      int right;
      ptr = i + 1;
      while (ptr <= nums.size()) {
        if (ptr == nums.size()) {
          right = 1;
          break;
        }

        if (bursted[ptr]) {
          ptr++;
          continue;
        }
        if (nums[ptr] && !bursted[ptr]) {
          right = nums[ptr];
          break;
        } else {
          ptr++;
        }
      }

      bursted[i] = true;
      int coin = left * nums[i] * right;
      int coins = coin + burst(nums, bursted);
      max_coins = max(coins, max_coins);
      bursted[i] = false;
    }

    return max_coins;
  }

  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    vector<bool> bursted(n, false);
    return burst(nums, bursted);
  }
};

class BetterSolution {
public:
  vector<vector<int>> memo;
  int f(vector<int> &nums, int i, int j) {
    if (j < i)
      return 0;
    if (memo[i][j] != -1)
      return memo[i][j];

    int maxCoins = 0;
    for (int k = i; k <= j; k++) {
      int coins = (nums[i - 1] * nums[k] * nums[j + 1]) + f(nums, i, k - 1) +
                  f(nums, k + 1, j);

      maxCoins = max(maxCoins, coins);
    }

    return memo[i][j] = maxCoins;
  }

  int maxCoins(vector<int> &nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int n = nums.size();
    memo = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));

    return f(nums, 1, n - 2);
  }
};

class BottomUpSolution {
public:
  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int dp[n + 2][n + 2];
    memset(dp, 0, sizeof(dp));

    for (int i = n; i > 0; i--) {
      for (int j = 1; j <= n; j++) {
        if (j < i) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = 0;

          for (int k = i; k <= j; k++) {
            int cost = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] +
                       dp[k + 1][j];

            dp[i][j] = max(dp[i][j], cost);
          }
        }
      }
    }

    return dp[1][n];
  }
};

class TopDownSolution {
public:
  int maxCoins(vector<int> &nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int len = 1; len <= n - 2; len++) {
      for (int i = 1; i <= n - len - 1; i++) {
        int j = i + len - 1;
        dp[i][j] = 0;
        for (int k = i; k <= j; k++) {
          int coins =
              nums[i - 1] * nums[j + 1] * nums[k] + dp[i][k - 1] + dp[k + 1][j];

          dp[i][j] = max(dp[i][j], coins);
        }
      }
    }

    return dp[1][n - 2];
  }
};
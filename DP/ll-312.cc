#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

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

class Solution {
public:
  int maxCoins(vector<int> &nums) {
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int len = 1; len <= n; len++) {
      for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;
        for (int k = i; k <= j; k++) {
          int cost =
              nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];

          dp[i][j] = max(dp[i][j], cost);
        }
      }
    }

    for (auto D : dp) {
      for (auto it : D) {
        cout << it << " ";
      }
      cout << endl;
    }

    return dp[1][n];
  }
};

#include <algorithm>
#include <climits>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// recursion -- dfs
class DFS_Solution {
public:
  unordered_map<string, int> memo;
  int solve(vector<int> &coins, int index, int amount, int step) {
    string key = to_string(index) + "_" + to_string(amount);

    if (memo.find(key) != memo.end())
      return memo[key];

    if (amount == 0) {
      return step;
    }

    if (index >= coins.size() || amount < 0) {
      return -1;
    }

    int sameCoin = solve(coins, index, amount - coins[index], step + 1);

    int differentCoin = solve(coins, index + 1, amount, step);

    if (sameCoin == -1 && differentCoin == -1) {
      return -1;
    }

    if (sameCoin == -1) {
      return differentCoin;
    }

    if (differentCoin == -1) {
      return sameCoin;
    }

    return memo[key] = min(sameCoin, differentCoin);
  }

  int coinChange(vector<int> &coins, int amount) {
    sort(coins.begin(), coins.end(), greater<int>());
    return solve(coins, 0, amount, 0);
  }
};

//  2d DP array
class Solution {
public:
  int MAX = INT_MAX - 1;

  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    int sum = accumulate(coins.begin(), coins.end(), 0);

    if (amount == 0)
      return 0;

    for (int i = 0; i <= amount; i++)
      dp[0][i] = MAX;

    for (int i = 1; i <= amount; i++) {
      int coin = coins[0];
      if (i % coin == 0)
        dp[0][i] = coin;
      else
        dp[0][i] = MAX;
    }

    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= amount; j++) {
        if (coins[i - 1] <= j) {
          dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n][n] == MAX ? -1 : dp[n][n];
  }
};

// 1D DP array
class One_D_Solution {

public:
  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    vector<int> min_coins(amount + 1, amount + 1);
    min_coins[0] = 0;

    for (auto coin : coins) {
      for (int i = 1; i <= amount && i >= coin; i++) {
        min_coins[i] = min(min_coins[i], 1 + min_coins[i - coin]);
      }
    }

    return min_coins[amount] == amount + 1 ? -1 : min_coins[amount];
  }
};
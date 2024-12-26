#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool isSubsetSum(vector<int> &arr, int target) {
    int n = arr.size();
    bool dp[n + 1][target + 1];
    memset(dp, false, sizeof(dp));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= target; j++) {
        if (arr[i - 1] <= j) {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n][target];
  }
};

class Recurse {
public:
  vector<vector<int>> memo;
  bool f(vector<int> &arr, int target, int index) {
    if (memo[index][target] != -1)
      return memo[index][target];
    if (target == 0)
      return true;
    if (index == arr.size() || target < 0) {
      return false;
    }

    if (arr[index] <= target) {
      return memo[index][target] = f(arr, target - arr[index], index + 1) ||
                                   f(arr, target, index + 1);
    } else {
      return memo[index][target] = f(arr, target, index + 1);
    }
  }

  bool isSubsetSum(vector<int> &arr, int target) {
    int n = arr.size();
    memo = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
    return f(arr, target, 0);
  }
};
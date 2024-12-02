

#include <vector>

using namespace std;

class MemoizedSolution {
public:
  int count{0};

  bool memo_knapsack(vector<vector<bool>> &memo, vector<int> &arr, int target,
                     int n) {
    if (target == 0) {
      count++;
      return true;
    }
    if (n == 0)
      return false;

    if (memo[target][n] != 0)
      return memo[target][n];

    if (arr[n - 1] <= target)
      return memo[target][n] =
                 memo_knapsack(memo, arr, target - arr[n - 1], n - 1) ||
                 memo_knapsack(memo, arr, target, n - 1);
    else
      return memo[target][n] = memo_knapsack(memo, arr, target, n - 1);
  }

  bool isSubsetSum(vector<int> &arr, int target) {
    int n = arr.size();
    vector<vector<bool>> memo(target + 1, vector<bool>(n + 1, 0));

    return memo_knapsack(memo, arr, target, n);
  }
};

class TopDownSolution {
public:
  bool isSubsetSum(vector<int> &arr, int target) {
    int n = arr.size();
    vector<vector<bool>> memo(n + 1, vector<bool>(target + 1, false));

    for (int i = 0; i <= n; i++) {
      memo[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= target; j++) {
        if (arr[i - 1] <= j) {
          memo[i][j] = memo[i - 1][j - arr[i - 1]] || memo[i - 1][j];
        } else {
          memo[i][j] = memo[i - 1][j];
        }
      }
    }

    return memo[n][target];
  }
};

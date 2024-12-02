#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  bool memo_knapsack(vector<vector<bool>> &memo, vector<int> &arr, int target,
                     int n) {
    if (target == 0)
      return true;
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

  bool equalPartition(vector<int> &arr) {
    int sum{0};
    for (int i = 0; i < arr.size(); i++) {
      sum += arr[i];
    }

    if (sum % 2 != 0) {
      return false;
    } else {
      return isSubsetSum(arr, sum / 2);
    }
  }
};

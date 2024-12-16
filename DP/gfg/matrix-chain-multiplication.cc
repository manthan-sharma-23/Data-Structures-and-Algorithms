#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  int static memo[101][101];

  int solve(vector<int> arr, int i, int j) {
    if (memo[i][j] != -1)
      return memo[i][j];

    if (i >= j)
      return 0;

    int min_ = 1e9;
    for (int k = i; k < j; k++) {
      int temp = solve(arr, i, k) + solve(arr, k + 1, j) +
                 (arr[i - 1] * arr[k] * arr[j]);

      min_ = min(min_, temp);
    }

    return memo[i][j] = min_;
  }

  int matrixMultiplication(vector<int> &arr) {
    memset(memo, -1, sizeof(memo));
    return solve(arr, 1, arr.size() - 1);
  }
};
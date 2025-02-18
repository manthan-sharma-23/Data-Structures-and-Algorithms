#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  int mergeStones(vector<int> &stones, int k) {
    int n = stones.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    vector<int> prefixSum(n, 0);

    prefixSum[0] = stones[0];
    for (int i = 1; i < n; i++) {
      prefixSum[i] = stones[i] + prefixSum[i - 1];
    }

    function<int(int, int)> findSubArraySum = [&prefixSum,
                                               &stones](int i, int j) -> int {
      return prefixSum[j] - (i > 0 ? prefixSum[i - 1] : 0);
      ;
    };

    //  for base length k
    for (int i = 0; i <= n - k; i++) {
      int sum = findSubArraySum(i, i + k - 1);
      dp[i][i + k - 1] = sum;
    }

    for (int len = k + 1; len <= n; len++) {
      for (int i = 0; i <= n - k; i++) {
        int j = i + len - 1;

        int psum = findSubArraySum(i, j);
        int left = (i + 1 <= j) ? dp[i + 1][j] : 0;
        int right = (i <= j - 1) ? dp[i][j - 1] : 0;
        dp[i][j] = min(left, right) + psum;
      }
    }

    return dp[0][n - 1];
  }
};
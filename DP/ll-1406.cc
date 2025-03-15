#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string stoneGameIII(vector<int> &stones) {
    int n = stones.size();

    vector<int> dp(n + 1, INT_MIN);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {

      dp[i] = max(dp[i], stones[i] - dp[i + 1]);
      if (i + 1 < n)
        dp[i] = max(dp[i], stones[i] + stones[i + 1] - dp[i + 2]);
      if (i + 2 < n)
        dp[i] =
            max(dp[i], stones[i] + stones[i + 1] + stones[i + 2] - dp[i + 3]);
    }

    if (dp[0] == 0)
      return "Tie";
    if (dp[0] > 0)
      return "Alice";
    else
      return "Bob";
  }
};

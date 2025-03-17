#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<int> dp(amount + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= amount; i++) {
      for (const int &c : coins) {
        if (c <= i)
          dp[i] += dp[i - c];
      }
    }

    return dp[amount];
  }
};
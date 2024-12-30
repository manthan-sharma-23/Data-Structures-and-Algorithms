
#include <cstring>
#include <vector>

using namespace std;
class Solution {
public:
  const int MOD = 1e9 + 7;
  int f(int low, int high, int zero, int one, int size, vector<int> &memo) {
    if (size > high) {
      return 0;
    }
    if (memo[size] != -1)
      return memo[size];

    int count{0};
    if (size >= low && size <= high)
      count++;

    if (zero) {
      count += (f(low, high, zero, one, size + zero, memo) % MOD);
    }

    if (one) {
      count += (f(low, high, zero, one, size + one, memo) % MOD);
    }

    return memo[size] = count % MOD;
  }
  int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> memo(high + 2, -1);
    return f(low, high, zero, one, 0, memo);
  }
};

class TopDown_Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    int dp[high + 1];
    const int MOD = 1e9 + 7;

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= high; i++) {
      if (i >= zero) {
        dp[i] = (dp[i] + dp[i - zero]) % MOD;
      }
      if (i >= one) {
        dp[i] = (dp[i] + dp[i - one]) % MOD;
      }
    }

    int count = 0;
    for (int i = low; i <= high; i++) {
      count = (count + dp[i]) % MOD;
    }

    return count;
  }
};

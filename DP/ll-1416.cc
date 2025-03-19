#include <atomic>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  typedef uint64_t u64;
  const int MOD = 1e9 + 7;

  int numberOfArrays(string s, int k) {
    int n = s.length();
    vector<u64> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
      u64 num = 0;
      u64 multi = 1;

      int maxDigits = log10(k) + 1;
      for (int cut = i - 1; cut >= max(0, i - maxDigits); cut--) {
        int digit = s[cut] - '0';

        num = digit * multi + num;
        multi *= 10;
        if (s[cut] == '0')
          continue;
        dp[i] = (dp[i] + dp[cut]) % MOD;
      }
    }

    return dp[n];
  }
};
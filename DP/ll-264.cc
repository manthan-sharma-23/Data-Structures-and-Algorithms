#include <vector>
using namespace std;

class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> dp(n + 1, 0);

    dp[0] = dp[1] = 1;
    int i2, i3, i5;
    i2 = i3 = i5 = 1;

    for (int i = 2; i <= n; i++) {
      int i2u = dp[i2] * 2;
      int i3u = dp[i3] * 3;
      int i5u = dp[i5] * 5;

      int ugly = min(i2u, min(i3u, i5u));
      dp[i] = ugly;

      if (ugly == i2u)
        i2++;
      if (ugly == i3u)
        i3++;
      if (ugly == i5u)
        i5++;
    }

    return dp[n];
  }
};
#include <climits>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int numSquares(int n) {

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0, dp[1] = 1;

    vector<int> squares;
    for (int i = 1; i * i <= n; i++) {
      squares.push_back(i * i);
    }

    for (int i = 2; i <= n; i++) {
      for (const int &sq : squares) {
        if (sq > i)
          break;
        dp[i] = min(dp[i], 1 + dp[i - sq]);
      }
    }

    return dp[n];
  }
};
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    vector<int> squares;

    dp[0] = 0;

    for (int i = 1; i * i <= n; i++) {
      squares.push_back(i * i);
    }

    for (int i = 1; i < n; i++) {
      for (auto square : squares) {
        if (square <= i) {
          dp[i] = min(dp[i], dp[i - square] + 1);
        }
      }
    }

    return dp[n];
  }
};
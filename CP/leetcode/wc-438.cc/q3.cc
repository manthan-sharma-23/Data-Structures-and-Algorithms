#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool hasSameDigits(string s) {
    int n = s.length();

    vector<vector<int>> memo(n, vector<int>(n, 0));

    //  len=2
    for (int i = 0; i + 2 - 1 < n; i++) {
      int j = i + 2 - 1;

      memo[i][j] = ((s[i] - '0') + (s[j] - '0')) % 10;
    }

    for (int len = 3; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;

        memo[i][j] = (memo[i][j - 1] + memo[i + 1][j]) % 10;
      }
    }

    return memo[0][n - 2] == memo[1][n - 1];
  }
};
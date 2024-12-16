
#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
  int memo[1002][1002];
  bool isPalindrome(string &s, int i, int j) {
    while (i <= j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++;
      j--;
    }

    return true;
  }

  int solve(string &s, int i, int j) {
    if (memo[i][j] != -1)
      return memo[i][j];
    if (i > j)
      return 0;

    if (isPalindrome(s, i, j)) {
      return 1;
    }

    int min_ = 1e9;
    for (int k = i; k < j; k++) {
      int temp = solve(s, i, k) + solve(s, k + 1, j);
      min_ = min(min_, temp);
    }

    return memo[i][j] = min_;
  }

  int palindromicPartition(string &s) {
    memset(memo, -1, sizeof(memo));
    return solve(s, 0, s.length() - 1) - 1;
  }
};
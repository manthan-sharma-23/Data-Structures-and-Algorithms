#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int n, k = 3;
  int memo[2002][4];
  unordered_map<int, unordered_map<int, bool>> isPalindrome;

  bool f(int i, int count) {
    if (i == n) {
      return count == k;
    }

    if (memo[i][count] != -1)
      return memo[i][count];

    bool possible = false;
    if (count < k - 1) {
      for (int cut = i; cut < n - (k - count - 1); cut++) {
        possible |= f(cut + 1, count + 1);
      }

    } else {
      possible = isPalindrome[i][n - 1];
    }

    return memo[i][count] = possible;
  }

  bool checkPartitioning(string s) {
    n = s.length();

    for (int i = 0; i < n; i++)
      isPalindrome[i][i] = true;

    for (int i = 0; i < n - 1; i++)
      isPalindrome[i][i + 1] = (s[i] == s[i + 1]);

    for (int len = 3; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
      }
    }

    memset(memo, -1, sizeof(memo));

    return f(0, 3);
  }
};
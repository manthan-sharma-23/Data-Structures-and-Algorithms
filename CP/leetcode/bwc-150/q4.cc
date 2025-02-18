#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<vector<int>>> memo;

  int solve(string s, string p, int start, int i, int j) {

    if (j == p.length())
      return memo[i][j][start] = i - start;

    if (i == s.length()) {
      for (int k = j; k < p.length(); k++) {
        if (p[k] != '*')
          return INT_MAX;
      }

      return memo[i][j][start] = i - start;
    }

    int result = INT_MAX;
    if (p[j] == '*') {
      for (int k = i; k < s.length(); k++) {
        result = min(result, solve(s, p, start, k, j + 1));
      }
    } else {
      if (s[i] != p[j]) {
        result = min(result, solve(s, p, i + 1, i + 1, 0));
      } else {
        result = min(result, solve(s, p, start, i + 1, j + 1));
      }
    }

    return memo[i][j][start] = result;
  }

  int shortestMatchingSubstring(string s, string p) {
    memo.resize(
        s.length() + 2,
        vector<vector<int>>(p.length() + 2, vector<int>(s.length() + 1, -1)));

    if (p.length() == 0)
      return 0;

    int ans = solve(s, p, 0, 0, 0);

    return ans > 1e5 ? -1 : ans;
  }
};
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  int dfs(string s, int idx, vector<int> &memo) {
    if (idx == s.length()) {
      return 1;
    }

    if (memo[idx] != -1) {
      return memo[idx];
    }

    if (s[idx] == '0') {
      return 0;
    }

    int result = dfs(s, idx + 1, memo);

    if (idx + 1 < s.length() && stoi(s.substr(idx, 2)) >= 10 &&
        stoi(s.substr(idx, 2)) <= 26) {
      result += dfs(s, idx + 2, memo);
    }
    memo[idx] = result;
    return result;
  }

  int numDecodings(string s) {
    vector<int> memo(s.length(), -1);
    return dfs(s, 0, memo);
  }
};

class OptimalSolution {
public:
  int numDecodings(string s) {
    int n = s.length();
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    if (s[0] != '0')
      dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      int opt1 = s[i - 1] - '0';
      int opt2 = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
      if (opt1 >= 1) {
        dp[i] += dp[i - 1];
      }
      if (opt2 >= 10 && opt2 <= 26) {
        dp[i] += dp[i - 2];
      }
    }

    return dp[n];
  }
};

int main() {
  OptimalSolution os1;
  string s = "121031";
  auto count = os1.numDecodings(s);

  cout << count << endl;

  return 0;
}

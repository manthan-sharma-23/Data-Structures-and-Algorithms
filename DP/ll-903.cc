#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  const int MOD = 1e9 + 7;
  int f(string &s, int index, vector<int> decreasing, vector<int> increasing) {
    if (decreasing.size() == 0 && increasing.size() == 0)
      return 1;

    if (s.length() == 0)
      return 0;

    int ways{0};
    if (s[index] == 'D') {
      for (int i = 0; i < decreasing.size(); i++) {
        vector<int> d2;
        for (int j = 0; j < i; j++) {
          d2.push_back(decreasing[j]);
        }
        vector<int> i2;
        for (int j = 0; j < increasing.size(); j++) {
          i2.push_back(increasing[j]);
        }
        for (int j = i + 1; j < decreasing.size(); j++) {
          i2.push_back(decreasing[j]);
        }

        ways += f(s, index + 1, d2, i2);
        ways %= MOD;
      }
    } else {
      for (int i = 0; i < increasing.size(); i++) {
        vector<int> d2;
        for (int j = 0; j < decreasing.size(); j++) {
          d2.push_back(decreasing[j]);
        }
        for (int j = 0; j < i; j++) {
          d2.push_back(increasing[j]);
        }
        vector<int> i2;

        for (int j = i + 1; j < increasing.size(); j++) {
          i2.push_back(increasing[j]);
        }

        ways += f(s, index + 1, d2, i2);
        ways %= MOD;
      }
    }

    return ways % MOD;
  }

  int numPermsDISequence(string s) {
    int n = s.length();

    vector<int> nums;

    for (int i = 0; i <= n; i++) {
      nums.push_back(i);
    }
    int ways = 0;
    for (int i = 0; i <= n; i++) {
      vector<int> d2;
      vector<int> i2;
      for (int j = 0; j < i; j++) {
        d2.push_back(nums[j]);
      }

      for (int j = i + 1; j < nums.size(); j++) {
        i2.push_back(nums[j]);
      }
      ways += f(s, 0, d2, i2);
      ways %= MOD;
    }
    return ways;
  }
};

class MEMO_2_Solution {
public:
  const int MOD = 1e9 + 7;
  bool visited[201];
  typedef long long int ll;
  int dp[203][203];

  int f(string &s, int index, int prev) {
    if (index == s.length())
      return 1;

    if (dp[index][prev] != -1)
      return dp[index][prev];

    ll count{0};

    if (s[index] == 'D') {
      for (int i = 0; i < prev; i++) {
        if (!visited[i]) {
          visited[i] = true;
          count += (f(s, index + 1, i) % MOD);
          visited[i] = false;
        }
      }
    } else {
      for (int i = prev + 1; i <= s.size(); i++) {
        if (!visited[i]) {
          visited[i] = true;
          count += (f(s, index + 1, i) % MOD);
          visited[i] = false;
        }
      }
    }

    return dp[index][prev] = count % MOD;
  }

  int numPermsDISequence(string s) {
    int n = s.length();
    memset(visited, false, sizeof(visited));
    memset(dp, -1, sizeof(dp));

    ll ways{0};
    for (int i = 0; i <= n; i++) {
      visited[i] = true;
      ways += (f(s, 0, i) % MOD);
      visited[i] = false;
    }

    return ways;
  }
};

class TOPDOWN_Solution {
public:
  const int MOD = 1e9 + 7;

  int numPermsDISequence(string s) {
    int n = s.length();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int j = 0; j <= n; j++) {
      dp[0][j] = 1;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        if (s[i - 1] == 'D') {
          for (int k = j; k < i; ++k) {
            dp[i][j] += dp[i - 1][k];
            dp[i][j] %= MOD;
          }
        } else {
          for (int k = 0; k < j; ++k) {
            dp[i][j] += dp[i - 1][k];
            dp[i][j] %= MOD;
          }
        }
      }
    }

    int ans = 0;

    for (int j = 0; j <= n; j++) {
      ans = (ans + dp[n][j]) % MOD;
    }

    return ans;
  }
};
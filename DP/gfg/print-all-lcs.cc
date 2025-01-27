#include <set>
#include <unordered_map>
#include <vector>

#include <string>

using namespace std;

class Solution {
public:
  int lcs = 0;

  void findLCS(const string &s, const string &t, int i1, int i2,
               string &current, vector<vector<int>> &dp, set<string> &result,
               unordered_map<string, bool> &visited) {
    string state = to_string(i1) + "," + to_string(i2) + "," + current;
    if (visited[state])
      return;
    visited[state] = true;

    if (i1 == s.size() || i2 == t.size()) {
      if (current.size() == lcs) {
        result.insert(current);
      }
      return;
    }

    if (s[i1] == t[i2]) {

      current.push_back(s[i1]);
      findLCS(s, t, i1 + 1, i2 + 1, current, dp, result, visited);
      current.pop_back();
    } else {
      if (dp[i1 + 1][i2] == dp[i1][i2]) {
        findLCS(s, t, i1 + 1, i2, current, dp, result, visited);
      }
      if (dp[i1][i2 + 1] == dp[i1][i2]) {
        findLCS(s, t, i1, i2 + 1, current, dp, result, visited);
      }
    }
  }

  vector<string> all_longest_common_subsequences(string s, string t) {
    int n1 = s.size(), n2 = t.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++) {
      for (int j = 1; j <= n2; j++) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    lcs = dp[n1][n2];
    set<string> result;
    string current;
    unordered_map<string, bool> visited;

    // Start DFS to find all LCS
    findLCS(s, t, 0, 0, current, dp, result, visited);

    return vector<string>(result.begin(), result.end());
  }
};

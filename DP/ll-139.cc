#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.length();

    vector<bool> dp(n + 1, false);
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    dp[0] = true;

    for (int i = 1; i <= n; i++) {
      for (int cut = i - 1; cut >= 0; cut--) {
        string W = s.substr(cut, i - cut);
        if (dp[cut] && dict.find(W) != dict.end()) {
          dp[i] = true;
          break;
        }
      }
      cout << endl;
    }

    return dp[n];
  }
};
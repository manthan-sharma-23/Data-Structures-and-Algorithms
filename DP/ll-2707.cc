#include <climits>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minExtraChar(string s, vector<string> &dictionary) {
    int n = s.length();

    set<string> dict(dictionary.begin(), dictionary.end());
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
      for (int cut = i - 1; cut >= 0; cut--) {
        string word = s.substr(cut, i - cut);
        if (dict.find(word) != dict.end()) {
          dp[i] = min(dp[i], dp[cut]);
        } else {
          dp[i] = min(dp[i], (int)word.length() + dp[cut]);
        }
      }
    }

    return dp[n];
  }
};
#include <climits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  typedef long long ll;
  int minimumCost(string target, vector<string> &words, vector<int> &costs) {

    int n = target.length() + 1;

    unordered_map<string, int> dict;

    for (int i = 0; i < words.size(); i++) {
      if (dict.find(words[i]) != dict.end())
        dict[words[i]] = min(dict[words[i]], costs[i]);
      else
        dict[words[i]] = costs[i];
    }

    vector<ll> dp(n + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
      for (int cut = i - 1; cut >= 0; cut--) {
        string w = target.substr(cut, i - cut);

        if (dict.find(w) != dict.end()) {
          dp[i] = min(dp[i], dict[w] + dp[cut]);
        }
      }
    }

    return dp[n] == INT_MAX ? -1 : dp[n];
  }
};
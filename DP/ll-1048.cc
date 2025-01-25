#include "vector"
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  bool isSuccesor(const string &a, const string &b) {
    if (a.length() + 1 != b.length())
      return false;

    int i = 0, j = 0;
    bool inserted = false;

    while (i < a.length() && j < b.length()) {
      if (a[i] == b[j]) {
        i++;
      } else if (!inserted) {
        inserted = true;
      } else {
        return false;
      }
      j++;
    }

    return true;
  }

  int longestStrChain(vector<string> &words) {
    int n = words.size();
    if (n == 1)
      return 1;

    sort(words.begin(), words.end(), [](const string &a, const string &b) {
      return a.length() < b.length();
    });

    vector<int> dp(n, 1);
    int maxL = 1;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (isSuccesor(words[j], words[i])) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }

      maxL = max(maxL, dp[i]);
    }

    return maxL;
  }
};

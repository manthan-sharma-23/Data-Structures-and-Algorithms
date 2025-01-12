#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isSame(string pre, string s) {
    int i = 0;

    if (pre.length() > s.length())
      return false;

    while (i < pre.length()) {
      if (pre[i] != s[i])
        return false;
      i++;
    }
    return true;
  }

  int prefixCount(vector<string> &words, string pref) {
    int count = 0;
    for (auto word : words) {
      if (isSame(pref, word)) {
        count++;
      }
    }
    return count;
  }
};
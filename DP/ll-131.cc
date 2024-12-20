#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> res;

  void solve(int i, vector<string> &path, string s) {
    if (i == s.size()) {
      res.push_back(path);
      return;
    }

    for (int k = i; k < s.size(); k++) {
      if (isPalindrome(s, i, k)) {
        path.push_back(s.substr(i, k - i + 1));
        solve(i + 1, path, s);
        path.pop_back();
      }
    }
  } 

  bool isPalindrome(string s, int i, int j) {
    while (i <= j) {
      if (s[i++] != s[j--])
        return 0;
    }

    return 1;
  }

  vector<vector<string>> partition(string s) {
    vector<string> path;
    solve(0, path, s);

    return res;
  }
};
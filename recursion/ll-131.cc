#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int n;
  vector<vector<string>> res;

  void f(vector<string> &path, string &s, int i) {
    if (i == s.length()) {
      res.push_back(path);
      return;
    }

    for (int k = i; k < n; k++) {
      if (isPalindrome(s, i, k)) {
        path.push_back(s.substr(i, k - i + 1));
        f(path, s, k + 1);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(string s, int i, int j) {
    while (i <= j)
      if (s[i++] != s[j--])
        return 0;

    return 1;
  }

  vector<vector<string>> partition(string s) {
    n = s.length();

    vector<string> path;
    f(path, s, 0);

    return res;
  }
};
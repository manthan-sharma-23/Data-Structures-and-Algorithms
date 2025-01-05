
#include <cstring>
#include <set>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int memo[4][100002];
  void dfs(string &s, set<string> &st, string s1, int index) {
    if (s1.length() == 3) {
      if (s1[0] == s1[2]) {
        st.insert(s1);
      }
      return;
    }

    if (index == s.length())
      return;
    s1.push_back(s[index]);
    dfs(s, st, s1, index + 1);
    s1.pop_back();
    dfs(s, st, s1, index + 1);
  }

  int countPalindromicSubsequence(string s) {
    memset(memo, -1, sizeof(memo));
    int n = s.length();
    set<string> st;
    string s1 = "";
    dfs(s, st, s1, 0);

    return st.size();
  }
};

class S_Solution {
public:
  int countPalindromicSubsequence(string s) {
    int n = s.length();

    unordered_set<char> letters;

    for (int i = 0; i < n; i++)
      letters.insert(s[i]);

    int result = 0;
    for (char letter : letters) {
      int leftIdx = -1, rightIdx = -1;

      for (int i = 0; i < n; i++) {
        if (s[i] == letter) {
          if (leftIdx == -1) {
            leftIdx = i;
          }

          rightIdx = i;
        }
      }

      if (leftIdx == rightIdx)
        continue;

      unordered_set<char> st1;

      for (int i = leftIdx + 1; i < rightIdx; i++) {
        st1.insert(s[i]);
      }

      result += st1.size();
    }

    return result;
  }
};
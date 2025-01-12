#include <string>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s, int i, int len) {
    int start = i;
    int end = i + len - 1;

    if (end >= s.length() || start < 0) {
      return false;
    }

    while (start < end) {
      if (s[start] != s[end]) {
        return false;
      }
      start++;
      end--;
    }

    return true;
  }

  bool canConstruct(string s, int k) {
    int n = s.length();
    int steps = k;

    if (s.length() == k)
      return true;

    if (s.length() < k)
      return false;

    int i = 0;
    while (i < n && steps > 0) {

      for (int len = 2; len < n; len++) {
      }
      steps--;
    }
  }
};
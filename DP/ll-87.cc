#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int n;
  string r;

  bool f(int mask, string s) {

    if (s.compare(r) == 0)
      return true;

    for (int i = 0; i < n; i++) {
      if (!(mask & (1 << i))) {
        if (f(mask | (1 << i), s) ||
            f(mask | (1 << (n - i + 1)), s.substr(i + 1) + s.substr(0, i + 1)))
          return true;
      }
    }

    return false;
  }

  bool isScramble(string s1, string s2) {
    r = s2;
    n = s1.length();

    if (s1.length() != s2.length())
      return false;

    return f(0, s1);
  }
};
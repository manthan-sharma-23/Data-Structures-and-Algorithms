#include <string>

using namespace std;

class Solution {
public:
  bool canBeValid(string s, string locked) {
    int n = s.length();

    int i = 0;
    int canChange = 0;
    int open = 0;
    int close = 0;

    while (i < n) {
      char paran = s[i], code = locked[i];

      if (code == '0') {
        canChange++;
        if (paran == '(') {
          open++;
        } else if (paran == ')') {
          close++;
        }
      }

      i++;
    }
  }
};
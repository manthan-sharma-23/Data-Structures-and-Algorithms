#include <climits>
#include <string>

using namespace std;

class Solution {
public:
  int maxScore(string s) {
    int n = s.length();
    int zeros = 0, ones = 0;

    for (auto &c : s) {
      if (c == '1') {
        ones++;
      }
    }

    int max_sum = 0;

    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        zeros++;
      } else {
        ones--;
      }

      int new_sum = zeros + ones;

      max_sum = max(max_sum, new_sum);
    }

    return max_sum;
  }
};
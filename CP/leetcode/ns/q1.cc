#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int maxDifference(string s) {
    unordered_map<int, int> freq;

    for (auto c : s) {
      freq[c - 'a']++;
    }

    int sE = INT_MAX, lE = INT_MIN, so = INT_MAX, lo = INT_MIN;

    for (auto [c, f] : freq) {
      if (f % 2 == 0) {
        sE = min(sE, f);
        lE = max(lE, f);
      } else {
        so = min(so, f);
        lo = max(lo, f);
      }
    }

    return max(abs(lo - sE), abs(lE - so));
  }
};
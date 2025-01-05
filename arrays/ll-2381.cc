#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  char shift_letter(char letter, int shift) {
    shift = (shift % 26 + 26) % 26;
    return (letter - 'a' + shift) % 26 + 'a';
  }

  string shiftingLetters(string s, vector<vector<int>> &shifts) {
    int n = s.length();
    vector<int> shift_prefix(n, 0);

    for (auto &query : shifts) {
      shift_prefix[query[0]] += query[2] ? 1 : -1;
      if (query[1] + 1 < n) {
        shift_prefix[query[1] + 1] += query[2] ? -1 : 1;
      }
    }

    for (int i = 1; i < n; i++) {
      shift_prefix[i] += shift_prefix[i - 1];
    }

    for (int i = 0; i < n; i++) {
      s[i] = shift_letter(s[i], shift_prefix[i]);
    }

    return s;
  }
};

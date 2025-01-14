#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumLength(string s) {
    int n = s.length();

    int freq[26];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++) {
      int ch = s[i] - 'a';
      freq[ch]++;
    }
    int len = 0;

    for (int i = 0; i < 26; i++) {
      int v = freq[i];

      if (v >= 3) {
        len += (((v - 1) % 2) + 1);
      } else {
        len += v;
      }
    }

    return len;
  }
};
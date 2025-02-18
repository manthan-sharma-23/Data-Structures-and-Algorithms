#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool hasSpecialSubstring(string s, int k) {
    unordered_map<int, int> mp;

    for (int i = 0; i < k; i++) {
      mp[s[i]]++;
    }

    if (mp.size() == 1 && s[k] != s[k - 1])
      return true;

    int i = 0;
    for (int j = k; j < s.length(); j++, i++) {
    }
  }
};
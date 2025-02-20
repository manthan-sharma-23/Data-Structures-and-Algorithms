#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int atMostK(string &s, int k) {
    int n = s.length();

    if (k <= 0)
      return 0;

    unordered_map<char, int> mp;

    int len = 0;
    int i = 0;

    for (int j = 0; j < n; j++) {
      mp[s[j]]++;

      while (mp.size() > k) {
        mp[s[i]]--;
        if (mp[s[i]] == 0)
          mp.erase(s[i]);
        i++;
      }
      if (mp.size() == k)
        len = max(len, j - i + 1);
    }

    return len;
  }

  int longestKSubstr(string &s, int k) {

    int ans = atMostK(s, k);
    return ans == 0 ? -1 : ans;
  }
};
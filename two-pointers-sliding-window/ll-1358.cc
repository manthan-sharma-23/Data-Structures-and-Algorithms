#include <map>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
    int n = s.length();

    set<int> st;

    for (auto c : s) {
      st.insert(c);
    }

    int k = st.size();

    map<int, int> mp;

    int i = 0;

    for (int j = 0; j < s.length(); j++) {
      mp[s[j]]++;

      if (mp.size() == k) {
        i = j;
        break;
      }
    }

    int count = 0;

    for (int j = i; j < n; j++) {
      count += (j - i + 1);
    }

    return count;
  }
};
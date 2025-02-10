// Find the largest valid substring - Valid string is a string where any pair of
// characters have diff<=k

#include <set>
#include <string>

using namespace std;

int longestValidSubstringWithDistanceLesstThanK(string &s, int k) {
  int n = s.length();

  multiset<int> st;

  int i = 0, len = 0;

  for (int j = 0; j < n && j >= i; j++) {
    st.insert(s[j]);

    long maxC = *st.rbegin(), minC = *st.begin();

    while ((long)(maxC - minC) > k) {
      st.erase(st.find(s[i]));
      maxC = *st.rbegin(), minC = *st.begin();

      i++;
    }

    len = max(j - i + 1, len);
  }

  return len;
}
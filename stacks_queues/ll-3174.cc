#include <algorithm>
#include <string>

#include <stack>

using namespace std;

class Solution {
public:
  string clearDigits(string s) {
    stack<char> st;

    int i = 0;
    int n = s.length();

    while (i < n) {
      char c = s[i];

      if (c >= '0' && c <= '9') {
        st.pop();
      } else {
        st.push(c);
      }

      i++;
    }

    string s1 = "";

    while (!st.empty()) {

      char c = st.top();
      st.pop();
      s1.push_back(c);
    }

    reverse(s1.begin(), s1.end());

    return s1;
  }
};
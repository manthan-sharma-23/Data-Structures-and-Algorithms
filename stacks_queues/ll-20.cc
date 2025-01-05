#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (char &ch : s) {
      if (ch == '(' || ch == '{' || ch == '[') {
        st.push(ch);
      } else {
        if (st.empty())
          return false;

        char top = st.top();
        if ((ch == ')' && top != '(') || (ch == '}' && top != '{') ||
            (ch == ']' && top != '[')) {
          return false;
        }
        st.pop();
      }
    }

    return st.empty();
  }
};
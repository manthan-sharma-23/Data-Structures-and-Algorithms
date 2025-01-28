#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool parseBoolExpr(string expression) {
    int n = expression.length();

    stack<char> s;

    for (int i = 0; i < n; i++) {
      if (expression[i] == ',')
        continue;

      if (expression[i] == ')') {
        string values;

        while (s.top() != '(') {
          auto t = s.top();
          s.pop();

          values.push_back(t);
        }
        s.pop();
        char opr = s.top();
        s.pop();
        char res = 'f';
        switch (opr) {
        case '!':
          res = values[0] == 't' ? 'f' : 't';
          break;

        case '|':
          res = values.find('t') != string::npos ? 't' : 'f';
          break;

        case '&':
          res = values.find('f') != string::npos ? 'f' : 't';
          break;
        }

        s.push(res);
      } else {
        s.push(expression[i]);
      }
    }

    return s.top() == 't' ? 1 : 0;
  }
};
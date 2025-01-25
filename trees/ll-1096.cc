#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> braceExpansionII(string expression) {
    set<string> result;
    dfs(expression, result);

    return vector<string>(result.begin(), result.end());
  }

private:
  void dfs(const string &expr, set<string> &result) {
    if (expr.find('{') == string::npos) {
      result.insert(expr);
      return;
    }

    int first = expr.find('{');
    int last = findOtherBrace(expr, first);

    string prefix = expr.substr(0, first);
    string suffix = expr.substr(last + 1, expr.length());

    auto groupedInner =
        createInnerGroups(expr.substr(first + 1, last - first - 1));

    for (const auto &it : groupedInner) {
      dfs(prefix + it + suffix, result);
    }
  }

  int findOtherBrace(const string &expr, int open) {
    int depth = 1;

    for (int i = open + 1; i < expr.length(); i++) {
      if (expr[i] == '{')
        depth++;
      if (expr[i] == '}')
        depth++;

      if (depth == 0)
        return i;
    }

    return -1;
  }

  vector<string> createInnerGroups(const string &expr) {
    int n = expr.length();
    int depth = 0;
    vector<string> res;

    int start = 0;

    for (int i = 0; i < n; i++) {
      if (i == n || (expr[i] == ',' && depth == 0)) {
        res.push_back(expr.substr(start, i - start));
        start = i + 1;
      }

      if (expr[i] == '{')
        depth++;
      if (expr[i] == '}')
        depth++;
    }

    return res;
  }
};
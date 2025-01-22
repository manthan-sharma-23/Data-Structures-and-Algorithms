#include <functional>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  string crackSafe(int n, int k) {
    string result = string(n - 1, '0');
    unordered_set<string> visited;
    visited.insert(result);

    function<void(string)> dfs = [&](string node) {
      for (char digit = '0'; digit < '0' + k; ++digit) {
        string nextNode = node.substr(1) + digit;
        if (visited.count(nextNode) == 0) {
          visited.insert(nextNode);
          dfs(nextNode);
          result += digit;
        }
      }
    };

    dfs(result);

    return result;
  }
};

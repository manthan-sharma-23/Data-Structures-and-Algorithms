#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int n;
  vector<vector<int>> adj;
  vector<bool> result;
  string s;

  bool isPalindrome(const string &s) {
    int i = 0, j = s.length() - 1;
    while (i <= j)
      if (s[i++] != s[j--])
        return false;

    return true;
  }

  string f(int u, int parent) {
    string res = "";

    for (auto node : adj[u]) {
      if (node == parent)
        continue;

      res += f(node, u);
    }

    res += s[u];
    result[u] = isPalindrome(res);

    return res;
  }

  vector<bool> findAnswer(vector<int> &parent, string s) {
    n = s.length();
    adj.resize(n);
    result.resize(n, false);
    this->s = s;

    for (int i = 0; i < parent.size(); i++) {
      if (parent[i] == -1)
        continue;

      adj[parent[i]].push_back(i);
      adj[i].push_back(parent[i]);
    }

    for (int i = 0; i < parent.size(); i++) {
      sort(adj[i].begin(), adj[i].end());
    }

    f(0, -1);

    return result;
  }
};
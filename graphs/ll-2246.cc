#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int MAX = 0;
  string s;
  int dfs(vector<vector<int>> &adj, int u, int parent) {
    int largest_subtree = 0;
    int second_largest_subtree = 0;

    for (auto &node : adj[u]) {
      if (node == parent)
        continue;

      int maxPath = dfs(adj, node, u);

      if (s[node] != s[u]) {
        if (maxPath > largest_subtree) {
          second_largest_subtree = largest_subtree;
          largest_subtree = maxPath;
        } else if (maxPath > second_largest_subtree) {
          second_largest_subtree = maxPath;
        }
      }
    }

    MAX = max(MAX, largest_subtree + second_largest_subtree + 1);

    return largest_subtree + 1;
  }

  int longestPath(vector<int> &parent, string s_) {
    int n = parent.size();
    s = s_;
    vector<vector<int>> adj(n);

    for (int i = 1; i < n; i++) {
      int u = i;
      int v = parent[i];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(adj, 0, -1);

    return MAX;
  }
};
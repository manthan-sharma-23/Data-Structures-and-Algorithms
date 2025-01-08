#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int dfs(vector<vector<int>> &adj, string &labels, int u, int parent,
          vector<int> &result, vector<int> &count) {

    char c = labels[u];

    int before_curr = count[c - 'a'];
    count[c - 'a']++;
    for (auto &node : adj[u]) {
      if (node == parent)
        continue;
      dfs(adj, labels, node, u, result, count);
    }
    int countAfter = count[c - 'a'];
    return result[u] = countAfter - before_curr;
  }

  vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
    vector<vector<int>> adj(n);

    for (const auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    vector<int> result(n, 0);
    vector<int> count(26, 0);

    dfs(adj, labels, 0, -1, result, count);

    return result;
  }
};
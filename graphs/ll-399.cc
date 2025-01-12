#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  void dfs(unordered_map<string, vector<pair<string, double>>> &adj,
           unordered_set<string> &visited, string src, string dst,
           double product, double &ans) {

    visited.insert(src);

    if (src == dst) {
      ans = product;
      return;
    }

    for (auto &[node, wt] : adj[src]) {
      if (visited.find(node) == visited.end()) {
        dfs(adj, visited, node, dst, product * wt, ans);
      }
    }
  }

  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {

    int n = queries.size();

    unordered_map<string, vector<pair<string, double>>> adj(n);

    for (int i = 0; i < equations.size(); i++) {
      auto &eqn = equations[i];
      string u = eqn[0];
      string v = eqn[1];
      double wt = values[i];

      adj[u].push_back({v, wt});
      adj[v].push_back({u, 1.0 / wt});
    }

    vector<double> result;

    unordered_set<string> visited;
    for (auto query : queries) {
      string source = query[0];
      string dest = query[1];

      double ans = -1.0;
      double product = 1.0;

      if (adj.find(source) != adj.end()) {
        visited.clear();
        dfs(adj, visited, source, dest, product, ans);
      }

      result.push_back(ans);
    }

    return result;
  }
};
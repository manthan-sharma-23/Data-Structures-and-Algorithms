#include <climits>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<pair<int, int>>> adj;
  vector<int> value;
  int longest_path = 0;
  int minimum_nodes = INT_MAX;

  pair<int, int> dfs(int u, int parent, unordered_set<int> &valueTaken) {
    int max_path = 0, min_count = 1;

    valueTaken.insert(value[u]);

    for (auto [node, wt] : adj[u]) {
      if (node == parent)
        continue;

      if (valueTaken.find(value[node]) == valueTaken.end()) {
        auto [child_path, child_count] = dfs(node, u, valueTaken);
        child_path += wt;
        child_count += 1;

        if (child_path > max_path) {
          max_path = child_path;
          min_count = child_count;
        } else if (child_path == max_path) {
          min_count = min(min_count, child_count);
        }
      }
    }

    valueTaken.erase(value[u]);

    if (max_path > longest_path) {
      longest_path = max_path;
      minimum_nodes = min_count;
    } else if (max_path == longest_path) {
      minimum_nodes = min(minimum_nodes, min_count);
    }

    return {max_path, min_count};
  }

  vector<int> longestSpecialPath(vector<vector<int>> &edges,
                                 vector<int> &nums) {
    int n = nums.size();
    adj.resize(n);
    value = nums;

    for (auto edge : edges) {
      int u = edge[0];
      int v = edge[1];
      int wt = edge[2];
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }

    unordered_set<int> valueTaken;

    for (int i = 0; i < n; i++) {
      dfs(i, -1, valueTaken);
    }

    return {longest_path, minimum_nodes};
  }
};

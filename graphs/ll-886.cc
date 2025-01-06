

#include <vector>

using namespace std;

class Solution {
  int blue = 1, red = 2, none = 0;
  bool dfs(vector<vector<int>> &adj, int u, vector<int> &visited, int color) {

    visited[u] = color;
    int nextColor = color == blue ? red : blue;

    for (const int &node : adj[u]) {
      if (visited[node] == none) {
        if (!dfs(adj, node, visited, nextColor))
          return false;
      } else if (visited[node] != nextColor) {
        return false;
      }
    }

    return true;
  }

public:
  bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
    vector<vector<int>> adj(n + 1);
    vector<int> visited(n + 1, none);

    for (const auto &dislike : dislikes) {
      adj[dislike[0]].push_back(dislike[1]);
      adj[dislike[1]].push_back(dislike[0]);
    }

    for (int i = 0; i <= n; i++) {
      if (visited[i] == none) {
        if (!dfs(adj, i, visited, blue))
          return false;
      }
    }

    return true;
  }
};
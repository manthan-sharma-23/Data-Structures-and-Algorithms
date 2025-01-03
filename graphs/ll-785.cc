#include <vector>

using namespace std;

class Solution {
public:
  const int red = 1, green = 2, no_color = 0;

  bool dfs(vector<vector<int>> &graph, vector<int> &visited, int color,
           int node) {
    visited[node] = color;

    int nextColor = color == red ? green : red;

    for (auto &num : graph[node]) {
      if (visited[num] == no_color) {
        return dfs(graph, visited, nextColor, num);
      } else if (visited[num] != nextColor) {
        return false;
      }
    }

    return true;
  }

  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();

    vector<int> visited(n, no_color);

    for (int i = 0; i < n; i++) {
      if (visited[i] == no_color) {
        if (!dfs(graph, visited, red, i)) {
          return false;
        }
      }
    }

    return true;
  }
};
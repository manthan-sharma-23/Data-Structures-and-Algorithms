#include <vector>

using namespace std;
class Solution {
private:
  vector<bool> visited, inStack;
  vector<int> count;
  int MAX = -1;
  void dfs(vector<int> &edges, int u) {
    visited[u] = 1;
    inStack[u] = 1;

    auto toNode = edges[u];
    if (toNode != -1) {

      if (!visited[toNode]) {
        count[toNode] = count[u] + 1;
        dfs(edges, toNode);
      } else if (inStack[toNode]) {
        int n_nodes = count[u] - count[toNode] + 1;
        MAX = max(MAX, n_nodes);
      }
    }

    inStack[u] = 0;
  }

public:
  int longestCycle(vector<int> &edges) {
    int n = edges.size();

    visited.resize(n, 0), inStack.resize(n, 0);
    count.resize(n, 1);

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(edges, i);
      }
    }

    return MAX;
  }
};
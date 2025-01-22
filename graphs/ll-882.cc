#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int N;
  int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {
    N = n;

    unordered_map<int, vector<int>> adj;

    for (auto edge : edges) {
      int u = edge[0];
      int v = edge[1];
      int ae = edge[2];

      vector<pair<int, int>> aritficialEdges;
      int lastNode = u;
      for (int i = 1; i <= ae; i++) {
        int nextNewNode = N++;

        adj[lastNode].push_back(nextNewNode);
        adj[nextNewNode].push_back(lastNode);

        lastNode = nextNewNode;
      }
      adj[lastNode].push_back(v);
      adj[v].push_back(lastNode);
    }
    int nodes = 0;
    queue<int> q;
    vector<bool> visited(N + 1, false);
    q.push(0);
    int levels = 0;
    visited[0] = 0;

    while (!q.empty()) {

      int size = q.size();

      if (levels > maxMoves)
        return nodes;
      while (size--) {
        auto u = q.front();
        q.pop();
        nodes++;

        for (int node : adj[u]) {
          if (node != u && !visited[node]) {
            visited[node] = true;
            q.push(node);
          }
        }
      }

      if (!q.empty()) {
        levels++;
      }
    }

    return nodes;
  }
};
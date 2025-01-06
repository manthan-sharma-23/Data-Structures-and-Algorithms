#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    if (source == destination)
      return true;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    for (const auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    queue<int> q;

    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
      int top = q.front();
      visited[top] = true;
      q.pop();

      for (const auto &node : adj[top]) {
        if (node == destination) {
          return true;
        }
        if (!visited[node]) {
          q.push(visited[node]);
        }
      }
    }

    return false;
  }
};
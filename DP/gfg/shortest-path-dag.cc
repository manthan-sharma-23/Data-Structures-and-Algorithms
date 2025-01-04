#include "vector"
#include <climits>
#include <queue>

using namespace std;

class Solution {
public:
  vector<int> shortestPath(int V, int E, vector<vector<int>> &edges) {
    vector<vector<pair<int, int>>> adj(V);

    for (auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      int dist = edge[2];

      adj[u].push_back({v, dist});
    }
    vector<int> dist(V, INT_MAX);
    queue<int> q;

    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
      int curNode = q.front();
      q.pop();

      for (auto &pair : adj[curNode]) {
        int neighbor = pair.first;
        int weight = pair.second;
        if (dist[neighbor] > dist[curNode] + weight) {
          dist[neighbor] = dist[curNode] + weight;
          q.push(neighbor);
        }
      }
    }

    for (int i = 0; i < V; i++)
      if (dist[i] == INT_MAX)
        dist[i] = -1;

    return dist;
  }
};

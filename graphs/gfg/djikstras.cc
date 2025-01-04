#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  typedef pair<int, int> Node;
  vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    int n = adj.size();
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    vector<int> dist(n, INT_MAX);

    dist[src] = 0;

    pq.push({0, src});

    while (!pq.empty()) {
      Node level = pq.top();

      int currNode = level.second;
      int distance = level.first;

      pq.pop();

      for (auto &node_pair : adj[currNode]) {
        int node = node_pair.first;
        int wt = node_pair.second;
        if (distance + wt < dist[node]) {
          dist[node] = distance + wt;
          pq.push({dist[node], node});
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (dist[i] == INT_MAX) {
        dist[i] = -1;
      }
    }

    return dist;
  }
};
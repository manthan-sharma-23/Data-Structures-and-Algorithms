#include <climits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Graph {
  typedef pair<int, int> Node;
  vector<vector<Node>> adj;
  int N;

public:
  Graph(int n, vector<vector<int>> &edges) {
    adj.resize(n);
    N = n;
    for (auto &edge : edges) {
      adj[edge[0]].push_back({edge[1], edge[2]});
    }
  }

  void addEdge(vector<int> edge) { adj[edge[0]].push_back({edge[1], edge[2]}); }

  int shortestPath(int node1, int node2) {

    vector<int> dist(N, INT_MAX);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, node1});
    dist[node1] = 0;

    while (!pq.empty()) {
      auto [currDist, currNode] = pq.top();
      pq.pop();

      if (currDist > dist[currNode])
        continue;

      if (currNode == node2) {
        return currDist;
      }

      for (auto [neighbor, wt] : adj[currNode]) {
        int new_dist = currDist + wt;
        if (new_dist < dist[neighbor]) {
          dist[neighbor] = new_dist;
          pq.push({new_dist, neighbor});
        }
      }
    }

    return -1;
  }
};

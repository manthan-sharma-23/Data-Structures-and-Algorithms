#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<int> djikstra_s(int src, vector<pair<int, int>> adj[], int V) {

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  vector<int> dist(V, INT_MAX);
  dist[src] = 0;
  pq.push({0, src});

  while (!pq.empty()) {
    int distance = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (auto &edge : adj[node]) {
      int next = edge.first;
      int weight = edge.second;

      if (dist[next] > distance + weight) {
        dist[next] = distance + weight;
        pq.push({dist[next], next});
      }
    }
  }

  return dist;
}

int main() {
  int V = 5;                     // Number of vertices
  vector<pair<int, int>> adj[5]; // Adjacency list

  // Add edges: adj[node] = {neighbor, weight}
  adj[0].push_back({1, 2});
  adj[0].push_back({3, 6});
  adj[1].push_back({2, 3});
  adj[1].push_back({3, 8});
  adj[1].push_back({4, 5});
  adj[2].push_back({4, 7});
  adj[3].push_back({4, 9});

  auto distance = djikstra_s(0, adj, V);

  for (int i = 0; i < V; i++) {
    cout << "Node " << i << ": " << distance[i] << "\n";
  }

  cout << endl;

  return 0;
}

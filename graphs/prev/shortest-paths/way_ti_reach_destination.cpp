#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;


class Solution {
public:
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<vector<pair<int, int>>> adj(
        n); // Initialize the adjacency list for n nodes
    vector<int> dist(n, INT_MAX);
    vector<int> ways(n, 0);
    int mod = (int)(1e9 + 7);

    for (int i = 0; i < roads.size(); i++) {
      adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
      adj[roads[i][1]].push_back(
          {roads[i][0], roads[i][2]}); // Since the graph is undirected
    }

    int src = 0, dest = n - 1;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    dist[src] = 0;
    ways[src] = 1; // Start with one way to reach the source node
    pq.push({0, src});

    while (!pq.empty()) {
      auto it = pq.top();
      pq.pop();
      int distance = it.first;
      int city = it.second;

      for (auto nb : adj[city]) {
        int n_d = nb.second;
        int nextCity = nb.first;
        int newTotalDistance = n_d + distance;

        if (newTotalDistance < dist[nextCity]) {
          dist[nextCity] = newTotalDistance;
          ways[nextCity] = ways[city];
          pq.push({newTotalDistance, nextCity});
        } else if (newTotalDistance == dist[nextCity]) {
          ways[nextCity] = (ways[nextCity] + ways[city]) % mod;
        }
      }
    }

    return ways[n - 1];
  }
};

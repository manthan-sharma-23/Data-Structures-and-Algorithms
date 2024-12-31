// question (GFG)
// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  /*  Function to implement Bellman Ford
   *   edges: vector of vectors which represents the graph
   *   S: source vertex to start traversing graph with
   *   V: number of vertices
   */
  vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {
    int infinite = INT_MAX;
    vector<int> dist(V, infinite);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++) {
      for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != infinite && dist[u] + wt < dist[v]) {
          dist[v] = dist[u] + wt;
        }
      }
    }

    for (auto it : edges) {
      int u = it[0];
      int v = it[1];
      int wt = it[2];
      if (dist[u] != infinite && dist[u] + wt < dist[v]) {
        return {-1};
      }
    }

    return dist;
  }
};

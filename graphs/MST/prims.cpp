#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  typedef pair<int, int> P;
  int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<bool> inMST(V, false);
    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty()) {
      auto top = pq.top();
      int wt = top.first;
      int node = top.second;

      pq.pop();

      if (inMST[node]) {
        continue;
      }

      inMST[node] = true;
      sum += wt;

      for (auto tmp : adj[node]) {
        int adjnode = tmp[0];
        int adjwt = tmp[1];
        if (!inMST[adjnode]) {
          pq.push({adjwt, adjnode});
        }
      }
    }

    return sum;
  }
};

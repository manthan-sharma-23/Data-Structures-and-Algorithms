#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  // Function to find the shortest distance of all the vertices
  // from the source vertex S.
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    vector<int> dist(V, INT_MAX);

    pq.push({0, S});

    while (!pq.empty()) {
      auto front = pq.top();
      int distance = front.first;
      int node = front.second;

      pq.pop();

      for (auto it : adj[node]) {
        int newNode = it[0];
        int wt = it[1];

        if (distance + wt < dist[newNode]) {
          dist[newNode] = distance + wt;
          pq.push({distance + wt, newNode});
        }
      }
    }

    return dist;
  }

  vector<int> djikstras_using_ordered_set(int V, vector<vector<int>> adj[],
                                          int S) {

    set<pair<int, int>> st;
    vector<int> dist(V, INT_MAX);

    st.insert({0, S});
    dist[S] = 0;

    while (!st.empty()) {
      auto &front = *st.begin();
      int node = front.second;
      int d = front.first;

      st.erase(st.begin());

      for (auto it : adj[node]) {
        int newc = it[0];
        int wt = it[1];

        st.erase({dist[newc], newc});
        if (wt + d < dist[newc]) {

          if (dist[newc] != INT_MAX) {
            st.erase({dist[newc], newc});
          }

          dist[newc] = wt + d;
          st.insert({wt + d, newc});
        }
      }
    }
    return dist;
  };
}

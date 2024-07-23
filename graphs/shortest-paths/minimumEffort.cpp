#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    typedef pair<int, pair<int, int>> node;
    int n = heights.size(), m = heights[0].size();
    const vector<pair<int, int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<node, vector<node>, greater<node>> pq;

    pq.push({0, {0, 0}});

    while (!pq.empty()) {
      auto front = pq.top();
      int distance = front.first;
      int row = front.second.first;
      int col = front.second.second;

      pq.pop();

      for (auto it : directions) {
        int nrow = row + it.first;
        int ncol = col + it.second;

        if (dist[row][col] != INT_MAX) {
          if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
            int dis = distance + (heights[nrow][ncol] - heights[row][col]);

            if (dis < dist[nrow][ncol]) {
              dist[nrow][ncol] = dis;
              pq.push({dis, {nrow, ncol}});
            }
          }
        }
      }
    }

    return dist[n - 1][m - 1];
  }
};

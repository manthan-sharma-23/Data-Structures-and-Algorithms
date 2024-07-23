#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    if (grid[0][0] || grid[n - 1][n - 1])
      return -1;

    typedef pair<int, pair<int, int>> node;

    const vector<pair<int, int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    priority_queue<node, vector<node>, greater<node>> pq;

    pq.push({1, {0, 0}});
    dist[0][0] = 1;

    while (!pq.empty()) {
      auto front = pq.top();
      int distance = front.first;
      int row = front.second.first;
      int col = front.second.second;

      pq.pop();

      if (row == n - 1 && col == n - 1)
        return distance;

      for (auto dir : directions) {
        int nrow = row + dir.first;
        int ncol = col + dir.second;

        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n &&
            grid[nrow][ncol] == 0 && distance + 1 < dist[nrow][ncol]) {
          dist[nrow][ncol] = distance + 1;
          pq.push({distance + 1, {nrow, ncol}});
        }
      }
    }

    return -1;
  }
};

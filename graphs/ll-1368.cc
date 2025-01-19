#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int M, N;
  typedef pair<int, pair<int, int>> Node;
  vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool isValid(int row, int col) {
    return row >= 0 && col >= 0 && row < M && col < N;
  }

  int minCost(vector<vector<int>> &grid) {
    M = grid.size(), N = grid[0].size();
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<vector<int>> dist(M, vector<int>(N, INT_MAX));
    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    while (!pq.empty()) {
      auto [currCost, currCoords] = pq.top();
      auto [currRow, currCol] = currCoords;
      pq.pop();

      if (currRow == M - 1 && currCol == N - 1) {
        return currCost;
      }

      if (currCost > dist[currRow][currCol])
        continue;

      for (int i = 0; i < 4; i++) {
        auto [dr, dc] = directions[i];
        int nR = currRow + dr;
        int nC = currCol + dc;

        if (isValid(nR, nC)) {
          int newCost = currCost + (grid[currRow][currCol] - 1 != i);
          if (newCost < dist[nR][nC]) {
            dist[nR][nC] = newCost;
            pq.push({newCost, {nR, nC}});
          }
        }
      }
    }

    return -1;
  }
};

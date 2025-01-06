#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  typedef pair<int, pair<int, int>> Node;
  const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  bool isValid(int nx, int ny, int m, int n) {
    return nx >= 0 && nx < m && ny >= 0 && ny < n;
  }

  bool isBorder(int nx, int ny, int m, int n) {
    return nx == 0 || ny == 0 || nx == m - 1 || ny == n - 1;
  }

  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    int m = maze.size(), n = maze[0].size(), ex = entrance[0], ey = entrance[1];

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    pq.push({0, {ex, ey}});

    maze[ex][ey] = '+';

    while (!pq.empty()) {
      auto top = pq.top();
      int distance = top.first;
      int x = top.second.first;
      int y = top.second.second;
      pq.pop();

      for (const auto &[dx, dy] : directions) {
        int nx = x + dx, ny = y + dy, ndist = distance + 1;

        if (isValid(nx, ny, m, n) && maze[nx][ny] != '+') {

          if (isBorder(nx, ny, m, n)) {
            return ndist;
          }
          maze[nx][ny] = '+';
          pq.push({ndist, {nx, ny}});
        }
      }
    }

    return -1;
  }
};
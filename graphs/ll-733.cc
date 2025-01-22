#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  typedef pair<int, int> coordinates;
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    int rows = image.size(), columns = image[0].size();

    int base = image[sr][sc];

    if (base == color)
      return image;

    queue<coordinates> q;

    vector<coordinates> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    q.push({sr, sc});

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      image[x][y] = color;

      for (auto &[dx, dy] : directions) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < rows && ny >= 0 && ny < columns &&
            (image[nx][ny] == base)) {
          q.push({nx, ny});
        }
      }
    }

    return image;
  }
};
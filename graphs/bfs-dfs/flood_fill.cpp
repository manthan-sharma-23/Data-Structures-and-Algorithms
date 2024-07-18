#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    int pix_color = image[sr][sc];

    if (pix_color == color) {
      return image;
    }

    queue<pair<int, int>> q;
    q.push({sr, sc});
    int m = image.size(), n = image[0].size();

    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      image[row][col] = color;

      for (auto dir : directions) {
        int nrow = row + dir.first;
        int ncol = col + dir.second;
        if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
            image[nrow][ncol] == pix_color) {
          q.push({nrow, ncol});
        }
      }
    }

    return image;
  }
};

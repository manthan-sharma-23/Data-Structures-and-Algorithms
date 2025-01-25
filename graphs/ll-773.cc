#include "vector"
#include <queue>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
  string VectorToString(vector<vector<int>> &v) {
    string result = "";
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        result += to_string(v[i][j]);
      }
    }
    return result;
  }

  vector<vector<int>> stringToVector(string &s) {
    vector<vector<int>> v(2, vector<int>(3, 0));
    int index = 0;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        v[i][j] = s[index++] - '0';
      }
    }
    return v;
  }

  bool isValid(int r, int c) { return r >= 0 && c >= 0 && r < 2 && c < 3; }
  vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  int slidingPuzzle(vector<vector<int>> &board) {
    set<string> visited;

    queue<string> q;
    string start = VectorToString(board);
    vector<vector<int>> end_ = {{1, 2, 3}, {4, 5, 0}};
    string end = VectorToString(end_);
    q.push(start);
    visited.insert(start);
    int level = 0;
    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        auto top = q.front();
        q.pop();

        if (top == end) {
          return level;
        }

        auto vec = stringToVector(top);

        int row = 0, col = 0;

        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 3; j++) {
            if (vec[i][j] == 0) {
              row = i, col = j;
              break;
            }
          }
        }

        for (auto [dr, dc] : directions) {
          int nr = row + dr;
          int nc = col + dc;

          if (isValid(nr, nc)) {
            swap(vec[row][col], vec[nr][nc]);
            auto newBoard = VectorToString(vec);
            if (visited.find(newBoard) == visited.end()) {
              visited.insert(newBoard);
              q.push(newBoard);
            }
            swap(vec[row][col], vec[nr][nc]);
          }
        }
      }

      if (!q.empty())
        level++;
    }

    return -1;
  }
};
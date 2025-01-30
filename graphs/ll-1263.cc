#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int minPushBox(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    pair<int, int> target, box, person;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 'T') {
          target = {i, j};
        } else if (grid[i][j] == 'B') {
          box = {i, j};
        } else if (grid[i][j] == 'S') {
          person = {i, j};
        }
      }
    }

    auto valid = [&](int x, int y) -> bool {
      return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#';
    };

    auto check = [&](pair<int, int> curr, pair<int, int> dest,
                     pair<int, int> box) -> bool {
      queue<pair<int, int>> q;
      set<pair<int, int>> visited;

      q.push(curr);
      visited.insert(curr);

      while (!q.empty()) {
        auto pos = q.front();
        q.pop();

        if (pos == dest) {
          return true;
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto &dir : directions) {
          int x = pos.first + dir.first;
          int y = pos.second + dir.second;

          if (valid(x, y) && visited.find({x, y}) == visited.end() &&
              make_pair(x, y) != box) {
            visited.insert({x, y});
            q.push({x, y});
          }
        }
      }
      return false;
    };

    queue<tuple<int, pair<int, int>, pair<int, int>>> q;
    set<tuple<pair<int, int>, pair<int, int>>> vis;

    q.push({0, box, person});
    vis.insert({box, person});

    while (!q.empty()) {
      auto [dist, current_box, current_person] = q.front();
      q.pop();

      if (current_box == target) {
        return dist;
      }

      vector<pair<int, int>> b_coord = {
          {current_box.first + 1, current_box.second},
          {current_box.first - 1, current_box.second},
          {current_box.first, current_box.second + 1},
          {current_box.first, current_box.second - 1}};

      vector<pair<int, int>> p_coord = {
          {current_box.first - 1, current_box.second},
          {current_box.first + 1, current_box.second},
          {current_box.first, current_box.second - 1},
          {current_box.first, current_box.second + 1}};

      for (int i = 0; i < 4; i++) {
        auto new_box = b_coord[i];
        auto new_person = p_coord[i];

        if (valid(new_box.first, new_box.second) &&
            vis.find({new_box, current_box}) == vis.end()) {
          if (valid(new_person.first, new_person.second) &&
              check(current_person, new_person, current_box)) {
            vis.insert({new_box, current_box});
            q.push({dist + 1, new_box, current_box});
          }
        }
      }
    }

    return -1;
  }
};
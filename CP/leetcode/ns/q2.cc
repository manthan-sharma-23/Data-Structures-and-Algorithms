#include <cmath>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int maxDistance(string s, int k) {
    unordered_map<char, pair<int, int>> directions = {
        {'N', {0, 1}}, {'E', {1, 0}}, {'S', {0, -1}}, {'W', {-1, 0}}};

    int n = s.length();
    queue<tuple<int, int, int, int>> q;
    unordered_set<string> visited;

    q.push({0, k, 0, 0});
    visited.insert(to_string(0) + "_" + to_string(k) + "_0_0");

    int maxDist = 0;

    while (!q.empty()) {
      auto [i, remainingK, r, c] = q.front();
      q.pop();

      maxDist = max(maxDist, abs(r) + abs(c));

      if (i == n) {
        continue;
      }

      for (auto &[move, dir] : directions) {
        string stateKey;

        if (move == s[i]) {
          stateKey = to_string(i + 1) + "_" + to_string(remainingK) + "_" +
                     to_string(r + dir.first) + "_" + to_string(c + dir.second);
          if (visited.find(stateKey) == visited.end()) {
            q.push({i + 1, remainingK, r + dir.first, c + dir.second});
            visited.insert(stateKey);
          }
        } else if (remainingK > 0) {
          stateKey = to_string(i + 1) + "_" + to_string(remainingK - 1) + "_" +
                     to_string(r + dir.first) + "_" + to_string(c + dir.second);
          if (visited.find(stateKey) == visited.end()) {
            q.push({i + 1, remainingK - 1, r + dir.first, c + dir.second});
            visited.insert(stateKey);
          }
        }
      }
    }

    return maxDist;
  }
};

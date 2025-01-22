#include <vector>
using namespace std;

class Solution {
public:
  int waysToBuildRooms(vector<int> &prevRoom) {
    vector<vector<int>> edges;
    int n = prevRoom.size();
    int root = 0;
    for (int i = 0; i < n; i++) {
      if (prevRoom[i] != -1)
        edges.push_back({prevRoom[i], i});
    }
  }
};
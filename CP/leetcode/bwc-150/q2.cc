#include <algorithm>
#include <climits>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  double separateSquares(vector<vector<int>> &squares) {
    map<int, int> mp;
    int minY = 0, maxY = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    int totalArea = 0;

    for (auto &square : squares) {
      int xi = square[0], yi = square[1], leni = square[2];

      totalArea += (leni * leni);

      minY = min(minY, yi);
      maxY = max(maxY, yi + leni);

      for (int i = 1; i <= leni; i++) {
        pq.push({yi + i, xi});
      }
    }

    while (!pq.empty()) {
    
    

    
    }
  }
};
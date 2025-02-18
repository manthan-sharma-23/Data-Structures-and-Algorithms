#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool isWhole(double n) { return n == floor(n); }
  double separateSquares(vector<vector<int>> &squares) {
    int minY = 0, maxY = 0;
    double totalArea = 0;

    // {leni,yi}
    vector<pair<int, int>> newSquares;

    for (auto square : squares) {
      int xi = square[0], yi = square[1], leni = square[2];

      totalArea += (double)(leni * leni);

      minY = min(minY, yi);
      maxY = max(maxY, yi + leni);

      for (int i = 0; i < leni; i++) {
        newSquares.push_back({leni, yi + i});
      }
    }
    sort(newSquares.begin(), newSquares.end(),
         [](pair<int, int> &a, pair<int, int> &b) {
           return a.second < b.second;
         });
    int n = newSquares.size();

    int currY = minY, i = 0;

    unordered_map<int, int> areaBelow;
    areaBelow[minY] = 0;
    while (currY < maxY) {
      int area = 0;

      while (i < n && newSquares[i].second == currY) {
        area += newSquares[i].first;
        i++;
      }

      areaBelow[currY + 1] = areaBelow[currY] + area;
      currY++;
    }

    double low = minY, high = maxY;
    double target = totalArea / 2.0;

    double possibelAns = -1, pwt = 0;

    while (low <= high) {
      double mid = (double)high + (double)((double)(low - high) / 2.0);

      double fract = mid - floor(mid);
      double areaB =
          (double)areaBelow[floor(mid)] +
          (double)((double)(areaBelow[floor(mid) + 1] - areaBelow[floor(mid)]) *
                   fract);

      if (areaB == target) {
        possibelAns = mid;
        pwt = areaB;
        break;
      }

      if (areaB < target) {
        low = mid;
      } else {
        high = mid;
      }
    }

    if (isWhole(pwt)) {
      int ans = floor(possibelAns);
      while (areaBelow[ans] == areaBelow[ans - 1]) {
        ans--;
      }

      return ans;
    }

    return possibelAns;
  }
};
#include <iostream>
#include <vector>

using namespace std;

int findOverlapPerimeter(int x1, int y1, int x2, int y2, int n) {
  int overlapX1 = max(x1, x2);
  int overlapY1 = max(y1, y2);
  int overlapX2 = min(x1 + n, x2 + n);
  int overlapY2 = min(y1 + n, y2 + n);

  if (overlapX1 < overlapX2 && overlapY1 < overlapY2) {
    int overlapWidth = overlapX2 - overlapX1;
    int overlapHeight = overlapY2 - overlapY1;

    int perimeter = 2 * (overlapWidth + overlapHeight);
    return perimeter;
  }

  return 0;
}

void findTotalPerimeter(int side, int n, vector<pair<int, int>> &moves) {
  int temp = n * 4 * side;
  int prevX = moves[0].first, prevY = moves[0].second;
  for (int i = 1; i < n; i++) {
    int newX = prevX + moves[i].first, newY = prevY + moves[i].second;
    temp -= findOverlapPerimeter(prevX, prevY, newX, newY, side);
    prevX = newX;
    prevY = newY;
  }

  cout << temp << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> operations(n);

    for (int i = 0; i < n; i++) {
      cin >> operations[i].first >> operations[i].second;
    }

    findTotalPerimeter(m, n, operations);
  }

  return 0;
}
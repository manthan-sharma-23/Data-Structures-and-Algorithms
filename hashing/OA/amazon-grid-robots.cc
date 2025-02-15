// link
// https://docs.google.com/document/d/11zByozgT8OXwPa8AFLbpQoERcT8uL8PQxpvLSVEcV4g/edit?tab=t.0

/*
-> N points are given to us in the input of the format (x,y)

-> Out of these N points we have to output the count of good points;

-> A point is good ; if it has point above ; point below ; point to left and
point to right

m x n grid
*/

#include <vector>

using namespace std;

int idleRobots(int m, int n, vector<int> &Xs, vector<int> &Ys) {

  vector<int> largestV(m, -1), largestH(n, -1), smallestH(n, -1),
      smallestV(m, -1);

  for (int i = 0; i < Xs.size(); i++) {
    int x = Xs[i], y = Ys[i];

    //  for col y
    smallestV[y] = min(x, smallestV[y]);
    largestV[y] = max(x, largestV[y]);

    //  for row x
    smallestH[x] = min(y, smallestH[x]);
    largestH[x] = max(y, smallestH[x]);
  }

  int count = 0;

  for (int i = 0; i < Xs.size(); i++) {
    int x = Xs[i], y = Ys[i];

    bool top = false, down = false, right = false, left = false;

    if (smallestH[x] != -1 && smallestH[x] < x)
      left = true;
    if (smallestV[y] != -1 && smallestV[y] < y)
      top = true;

    if (largestV[y] != -1 && largestV[y] > y)
      down = true;

    if (smallestV[y] != -1 && smallestV[y] < y)
      right = true;

    if (top && down && right && left)
      count++;
  }

  return count;
}
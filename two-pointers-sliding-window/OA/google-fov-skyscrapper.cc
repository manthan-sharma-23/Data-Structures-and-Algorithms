// link ->
// https://leetcode.com/discuss/interview-question/3549864/Google-or-sliding-window

#include <vector>

using namespace std;

int maxBuildings(vector<int> &buildings, int fov) {
  int n = buildings.size();
  int view = 0;
  int len = 0;

  int i = 0;

  for (int j = 0; j < n; j++) {
    view += buildings[j];

    while (view > fov) {
      view -= buildings[i];
      i++;
    }

    len = max(len, j - i + 1);
  }

  return len;
}
#include <map>
#include <vector>

using namespace std;

int stepsToRemove(int boxes[], int n) {
  map<int, int> mp;

  for (int i = 0; i < n; i++) {
    mp[boxes[i]]++;
  }

  vector<int> sortedBoxes;

  for (auto [b, pile] : mp) {
    sortedBoxes.push_back(pile);
  }

  int steps = 0;
  for (int i = sortedBoxes.size() - 1; i > 0; i++) {
    int step = sortedBoxes[i] - sortedBoxes[i - 1];
    sortedBoxes[i - 1] += sortedBoxes[i];

    steps += step;
  }

  return steps;
}
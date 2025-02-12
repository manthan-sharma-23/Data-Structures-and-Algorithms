#include <functional>
#include <queue>
#include <vector>

using namespace std;

int maxScore(vector<int> &scores, int k, int teamSize) {

  priority_queue<int> frontHeap, backHeap;

  function<int()> getMaxFromHeap = [&]() -> int {
    if (frontHeap.empty()) {
      int val = backHeap.top();
      backHeap.pop();
      return val;
    }
    if (backHeap.empty()) {
      int val = frontHeap.top();
      frontHeap.pop();
      return val;
    }

    if (frontHeap.top() > backHeap.top()) {
      frontHeap.pop();
      return frontHeap.top();
    } else {
      backHeap.pop();
      return backHeap.top();
    }
  };

  int n = scores.size();

  int size = 0;
  int maxscore = 0;

  int i = -1, j = n;
  while (i < j && size < teamSize) {
    for (int step = 0; step < k; step++)
      frontHeap.push(scores[++i]);

    for (int step = 0; step < k; step++)
      backHeap.push(scores[--j]);

    size++;
    maxscore += getMaxFromHeap();
  }

  while (size < teamSize) {
    size++;
    maxscore += getMaxFromHeap();
  }

  return maxscore;
}
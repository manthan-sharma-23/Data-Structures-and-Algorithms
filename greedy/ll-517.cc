#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int findMinMoves(vector<int> &machines) {
    int n = machines.size();
    vector<int> moves(n, 0);
    int sum = accumulate(machines.begin(), machines.end(), 0);

    if (sum % n != 0)
      return -1;

    int target = sum / n;

    for (int i = 0; i < n; i++) {
      if (machines[i] < target) {
        int diff = target - machines[i];
        moves[i + 1] += diff;
        machines[i + 1] -= diff;
        machines[i] = target;
      }

      if (machines[i] > target) {
        int diff = machines[i] - target;
        moves[i] += diff;
        machines[i] = target;
        machines[i + 1] += diff;
      }
    }

    int maxi = 0;

    for (auto it : moves) {
      maxi = max(maxi, it);
    }

    return maxi;
  }
};
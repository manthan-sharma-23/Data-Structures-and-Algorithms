// link
// https://www.desiqna.in/17634/google-oa-sde-intern-fulltime-25th-july-2024-kumar-k

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

bool canReduce(vector<int> a, int M, int l, int val) {
  int n = a.size();
  vector<int> direct(2 * n + 1, val);
  int cost = 0;

  if (a[0] > direct[0]) {
    int diff = abs(a[0] - direct[0]);
    cost += diff;
    direct[l] -= diff;
  }

  for (int i = 1; i < n; i++) {
    direct[i] += direct[i - 1];

    if (direct[i] < a[i]) {
      int diff = a[i] - direct[i];

      cost += diff;
      direct[i] += diff;
      direct[i + l] -= diff;
    }
  }

  return cost <= M;
}

// N logN
int maxMinPossiblity(vector<int> &a, int M, int K) {
  int lowest = *min_element(a.begin(), a.end()) - M;
  int highest = *max_element(a.begin(), a.end());

  int minMaxPossible = highest;
  int l = lowest, h = highest;

  while (l <= h) {
    int mid = (h + l) / 2;

    if (canReduce(a, M, K, mid)) {
      minMaxPossible = min(minMaxPossible, mid);
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return minMaxPossible;
}
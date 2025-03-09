#include <vector>

using namespace std;

class Solution {
public:
  int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    int n = baskets.size();

    vector<int> taken(n, false);

    int count = 0;

    for (auto fruit : fruits) {

      int i = 0;
      while (i < n && (baskets[i] < fruit || taken[i] == true)) {
        i++;
      }

      if (i == n) {
        count++;
      } else
        taken[i] = true;
    }

    return count;
  }
};
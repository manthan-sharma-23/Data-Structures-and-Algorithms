#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //  find m = a ^ n  ; solve for a ;
  int nthRoot(int n, int m) {

    int low = 1, high = m;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      int power = pow(mid, n);

      if (power == m)
        return mid;

      if (power > m)
        high = mid - 1;
      else
        low = mid + 1;
    }

    return -1;
  }
};

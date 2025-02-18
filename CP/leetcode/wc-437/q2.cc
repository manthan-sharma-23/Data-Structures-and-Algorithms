#include <cmath>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  typedef long long ll;
  long long maxWeight(vector<int> &pizzas) {
    int n = pizzas.size();
    ll days = n / 4;

    multiset<int> heap(pizzas.begin(), pizzas.end());

    ll oddDays = ceil(days / 2.0);
    ll evenDays = days - oddDays;

    auto takeOutMax = [&heap]() -> int {
      auto it = prev(heap.end());
      ll val = *it;
      heap.erase(it);
      return val;
    };

    auto takeOutMin = [&heap]() -> int {
      auto it = heap.begin();
      ll val = *it;
      heap.erase(it);
      return val;
    };

    ll wt = 0;

    while (oddDays--) {
      int out = takeOutMax();
      wt += out;

      for (int i = 0; i < 3; i++) {
        takeOutMin();
      }
    }

    while (evenDays--) {
      takeOutMax();
      int out = takeOutMax();
      wt += out;

      for (int i = 0; i < 2; i++) {
        takeOutMin();
      }
    }

    return wt;
  }
};
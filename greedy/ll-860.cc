#include <vector>

using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int fives = 0, tens = 0, twenties = 0;

    for (int i = 0; i < bills.size(); i++) {
      int bill = bills[i];

      if (bill == 5) {
        fives++;
      } else if (bill == 10) {
        if (fives) {
          tens++;
          fives--;
        } else {
          return false;
        }
      } else {
        if (tens && fives) {
          tens--;
          fives--;
          twenties++;
        } else if (fives > 2) {
          fives -= 3;
          twenties++;
        } else {
          return false;
        }
      }
    }

    return true;
  }
};
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    int n = people.size();

    int count = 0;

    int wt = 0;

    for (int j = 0; j < n; j++) {

      while (wt <= limit && j < n) {
        wt += people[j++];
      }

      count++;
      j--;
      wt = 0;
    }

    return count;
  }
};
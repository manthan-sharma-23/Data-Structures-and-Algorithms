#include <vector>

using namespace std;

class Solution {
public:
  int numOfSubarrays(vector<int> &arr) {
    int i = 0, count = 0, sum = 0;

    int oddCount = 0, evenCount = 1;

    for (auto num : arr) {
      if (num & 1) {

      } else {
      }
    }

    return oddCount;
  }
};
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int countPairs(vector<int> &arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int i = 0, j = n - 1;
    int count = 0;

    while (i < j) {
      if (arr[i] + arr[j] < target) {
        count += j - i;
        i++;
      } else {
        j--;
      }
    }

    return count;
  }
};
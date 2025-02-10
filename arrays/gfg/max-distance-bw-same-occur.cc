#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxDistance(vector<int> &arr) {
    unordered_map<int, int> first_occur;
    int maxD = 0;

    for (int i = 0; i < arr.size(); i++) {
      if (first_occur.find(arr[i]) == first_occur.end()) {
        first_occur[arr[i]] = i;
      }
      maxD = max(maxD, i - first_occur[arr[i]]);
    }

    return maxD;
  }
};
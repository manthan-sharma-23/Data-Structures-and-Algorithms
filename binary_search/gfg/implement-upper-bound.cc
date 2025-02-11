#include <vector>

using namespace std;

class Solution {

public:
  //  smallest number strcitly greater than target
  int upperBound(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
      int mid = (low + high) / 2;

      if (arr[mid] > target) {
        if (arr[mid - 1] > target) {
          high = mid - 1;
        } else {
          return mid;
        }
      } else {
        low = mid + 1;
      }
    }

    return arr.size();
  }

  //  smallest number strcitly greater than or equal to target
  int lowerBound(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
      int mid = (low + high) / 2;

      if (arr[mid] >= target) {
        if (arr[mid - 1] >= target) {
          high = mid - 1;
        } else {
          return mid;
        }
      } else {
        low = mid + 1;
      }
    }

    return arr.size();
  }
};

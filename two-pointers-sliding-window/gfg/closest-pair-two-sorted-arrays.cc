//   https://www.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1

#include <climits>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
    int i = 0, j = m - 1;

    int ans = INT_MAX, X, Y;

    while (i < n && j >= 0) {
      int sum = arr[i] + brr[j];
      int diff = abs(sum - x);

      if (diff < ans) {
        ans = diff;
        X = arr[i];
        Y = arr[j];
      }

      if (sum > x)
        j--;
      else
        i++;
    }

    return {X, Y};
  }
};
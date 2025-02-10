// Find the number of subarrays whose sum is <= k

#include <vector>

using namespace std;

int numberofSubarrays(vector<int> &nums, int n, int k) {

  int count = 0;

  //  take two pointers i and j and create a dynamic window of a subarray
  //  no. of subarrays that can be formed ending at index i would be j-i+1;
  int sum = 0;
  int i = 0;

  for (int j = 0; j < n; j++) {
    sum += nums[j];

    //  increement i till the subarray satisfies the conditions.
    while (sum > k) {
      sum -= nums[i];
      i++;
    }

    count += (j - i + 1);
  }

  return count;
}
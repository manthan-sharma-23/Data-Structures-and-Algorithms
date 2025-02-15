// Given an array B find the number of pairs such that

// L <= (b[i] + b[j]) <= R

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int countPairs(vector<int> &B, int n, int x) {
  sort(B.begin(), B.end());

  int i = 0, j = n - 1;

  int count = 0;

  while (i < j) {

    int sum = B[i] + B[j];

    if (sum > x) {
      j--;
    } else if (sum <= x) {
      count += j - i;
      i++;
    }
  }

  return count;
}

int main() {
  vector<int> nums = {4, 5, 6, 2, 3, -1, 7};
  int L = 1, R = 5;

  cout << countPairs(nums, nums.size(), R) - countPairs(nums, nums.size(), L-1)
       << endl;
}
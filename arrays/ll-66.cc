#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int n = digits.size();

    long long int sum{0};
    for (int i = 0; i < n; i++) {
      sum = sum * 10 + digits[i];
    }

    sum = sum + 1;

    vector<int> ar;
    while (sum) {
      int digit = sum % 10;
      sum /= 10;
      ar.push_back(digit);
    }

    reverse(ar.begin(), ar.end());
    return ar;
  }
};
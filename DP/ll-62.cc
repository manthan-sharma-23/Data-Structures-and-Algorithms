#include "algorithm"

using namespace std;
class Solution {
public:
  int factorial(int n) {
    if (n == 0)
      return 1;
    return n * factorial(n - 1);
  }

  int uniquePaths(int m, int n) {
    return factorial(m) / (factorial(n) * factorial(m - n));
  }
};
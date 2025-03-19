#include <cmath>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  unordered_map<int, int> primeIdx;
  int count1s = 0;
  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

  Solution() {
    for (int i = 0; i < primes.size(); i++) {
      primeIdx[primes[i]] = i;
    }
  }

  vector<int> findGoodNumbers(const vector<int> &nums) {
    vector<int> goodNumbers;

    for (int number : nums) {
      if (number == 1) {
        count1s++;
        continue;
      }
      if (number < 2)
        continue;

      int factors = 0;
      bool isGood = true;
      int original = number;

      for (auto p : primes) {
        if (p * p > number)
          break;

        int count = 0;
        while (number % p == 0) {
          number /= p;
          count++;
        }

        if (count > 1) {
          isGood = false;
          break;
        }

        if (count == 1) {
          factors |= (1 << primeIdx[p]);
        }
      }

      if (number > 1) {
        if (primeIdx.find(number) == primeIdx.end()) {
          isGood = false;
        } else {
          if (factors & (1 << primeIdx[number])) {
            isGood = false;
          }
          factors |= (1 << primeIdx[number]);
        }
      }

      if (isGood) {
        goodNumbers.push_back(factors);
      }
    }

    return goodNumbers;
  }

  int numberOfGoodSubsets(vector<int> &nums) {
    const int mod = 1e9 + 7;
    for (int i = 0; i < 10; i++) {
      primeIdx[primes[i]] = i;
    }

    int allPrimes = (1 << 10) - 1;

    vector<int> goodNumbers = findGoodNumbers(nums);

    int n = goodNumbers.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(allPrimes + 1, 0));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= allPrimes; j++) {
        dp[i][j] += dp[i - 1][j];

        int goodNum = goodNumbers[i - 1];

        if ((j & goodNum) == goodNum) {
          int leftBits = j ^ goodNum;
          dp[i][j] = (dp[i][j] + dp[i - 1][leftBits]) % mod;
        }
      }
    }
    int ans = 0;
    for (int j = 1; j < allPrimes; j++) {
      ans = (ans + dp[n][j]) % mod;
    }

    return ans * pow(2, count1s);
  }
};
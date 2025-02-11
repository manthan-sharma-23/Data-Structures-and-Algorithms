

#include <vector>

using namespace std;

vector<bool> allPrimes(int n) {
  vector<bool> isPrime(n + 1, true);

  isPrime[0] = 1, isPrime[1] = 1;

  for (int i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      for (int p = i * i; p <= n; p += i) {
        isPrime[p] = false;
      }
    }
  }

  return isPrime;
}



#include <algorithm>
#include <iostream>
using namespace std;

int calculateFibonacciness(int a1, int a2, int a4, int a5) {
  int a3_1 = a1 + a2;
  int a3_2 = a5 - a4;
  int maxFibonacciness = 0;

  int fib1 = 0;
  if (a3_1 == a1 + a2)
    fib1++;
  if (a4 == a2 + a3_1)
    fib1++;
  if (a5 == a3_1 + a4)
    fib1++;
  maxFibonacciness = max(maxFibonacciness, fib1);

  int fib2 = 0;
  if (a3_2 == a1 + a2)
    fib2++;
  if (a4 == a2 + a3_2)
    fib2++;
  if (a5 == a3_2 + a4)
    fib2++;
  maxFibonacciness = max(maxFibonacciness, fib2);

  return maxFibonacciness;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    cout << calculateFibonacciness(a1, a2, a4, a5) << endl;
  }

  return 0;
}

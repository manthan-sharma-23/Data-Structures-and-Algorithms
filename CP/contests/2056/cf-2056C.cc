#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;

  // Construct a sequence that satisfies the condition.
  vector<int> a(n);

  // Use a simple palindrome structure by filling the sequence symmetrically.
  for (int i = 0; i < n / 2; ++i) {
    a[i] = a[n - 1 - i] = i + 1;
  }

  // If n is odd, the middle element can be any number (let's choose n / 2 + 1).
  if (n % 2 == 1) {
    a[n / 2] = n / 2 + 1;
  }

  // Output the sequence
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

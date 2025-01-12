#include <iostream>
using namespace std;

int main() {

  int t;
  cin >> t;

  while (t--) {
    int n, a, b;

    cin >> n >> a >> b;

    int spaces = (abs(a - b) - 1) % 2;

    if (spaces == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
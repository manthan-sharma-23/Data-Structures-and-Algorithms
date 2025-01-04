#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    int refuel[n + 2];

    for (int i = 1; i <= n; i++) {
      cin >> refuel[i];
    }

    refuel[0] = 0;
    refuel[n + 1] = refuel[n] + (2 * (k - refuel[n]));

    int volume = 0;
    for (int i = 1; i <= n + 1; i++) {
      int diff = refuel[i] - refuel[i - 1];
      volume = max(volume, diff);
    }

    printf("%d\n", volume);
  }
}

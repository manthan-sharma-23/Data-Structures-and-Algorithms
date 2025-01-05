#include <climits>
#include <iostream>

using namespace std;
int main() {

  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int min_ = INT_MAX;

  for (auto &num : arr) {
    min_ = min(min_, abs(num));
  }

  cout << min_ << endl;
}
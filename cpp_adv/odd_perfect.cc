#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> findDivisors(int n) {
  vector<int> divisors;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
    }
  }
  return divisors;
}

bool isPerfect(int n) {
  vector<int> divisors = findDivisors(n);
  int sum = 0;
  for (int i = 0; i < divisors.size(); i++) {
    sum += divisors[i];
  }
  return sum == n;
}

vector<int> findPerfects(int n = 10000) {
  vector<int> perfects;
  for (int i = 1; i <= n; i++) {
    if (isPerfect(i)) {
      perfects.push_back(i);
    }
  }
  return perfects;
}

int main() {
  auto list = findPerfects(1000);
  for (int i = 0; i < list.size(); i++) {
    cout << list[i] << endl;
  }

  return 0;
}

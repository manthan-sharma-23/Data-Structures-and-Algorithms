#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

auto findEven = [](ull start, ull end) {
  for (int i = start; i <= end; i++) {
    if ((i & 1) == 0) {
      evenSum += i;
    }
  }
};

auto findOdd = [](ull start, ull end) {
  for (int i = start; i <= end; i++) {
    if ((i & 1) == 1) {
      oddSum += i;
    }
  }
};

int main() {
  ull start = 0, end = 100000000000000;

  auto now = std::chrono::high_resolution_clock::now();

  std::thread t1(findEven, start, end);

  t1.join();

  std::thread t2(findOdd, start, end);
  t2.join();

  if (t1.joinable())
    t1.detach();

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - now);

  cout << "Duraiton in sec:: " << duration.count() << endl;
}

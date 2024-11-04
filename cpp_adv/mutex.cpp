#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int ammount = 0;

std::mutex m;

auto addMoney = []() {
  m.lock();
  ++ammount;
  cout << ammount << endl;
  m.unlock();
};

int main() {
  std::thread t1(addMoney);
  std::thread t2(addMoney);

  t1.join();
  t2.join();

  cout << ammount << endl;
  return 0;
}

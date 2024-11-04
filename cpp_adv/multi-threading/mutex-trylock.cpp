#include <iostream>
#include <mutex>
#include <thread>

int counter = 0;
std::mutex m;

void iterateCounter() {
  for (int i = 0; i <= 100; i++) {
    if (m.try_lock()) {
      counter = i;
      std::cout << "i " << i << std::endl;

      m.unlock();
    }
  }
}

int main() {
  std::thread t1(iterateCounter);
  std::thread t2(iterateCounter);

  t1.join();

  t2.join();

  std::cout << counter << std::endl;
  return 0;
}

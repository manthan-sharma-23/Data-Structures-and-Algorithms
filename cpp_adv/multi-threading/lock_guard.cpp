
#include <iostream>
#include <mutex>
#include <thread>

std::mutex m1;
int buffer = 0;

void task(const char *threadNumber, int loopFor) {
  std::lock_guard<std::mutex> lock(m1);

  for (int i = 0; i < loopFor; i++) {
    buffer++;
    std::cout << threadNumber << " " << buffer << std::endl;
  }
}

int main() {

  std::thread t1(task, "t1", 10);
  std::thread t2(task, "t2", 10);

  t1.join();
  t2.join();
}

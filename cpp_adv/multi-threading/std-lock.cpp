#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int X = 0, Y = 0;

std::mutex m1, m2;

void doSomeWorkForSeconds(int seconds) {
  std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void increementXY(int &XorY, std::mutex &m, const char *desc) {
  for (int i = 0; i < 5; i++) {
    m.lock();
    ++XorY;
    cout << desc << " " << XorY << endl;
    m.unlock();
    doSomeWorkForSeconds(1);
  }
}

void consumeXY() {
  int useCount = 5;
  int XplusY = 0;
  while (useCount-- > 0) {
    int lockResult = std::try_lock(m1, m2);
    if (lockResult == -1) {
      if (X != 0 && Y != 0) {
        --useCount;
        XplusY += X + Y;
        X = 0;
        Y = 0;
        cout << "XplusY " << XplusY << endl;
      }

      m1.unlock();
      m2.unlock();
    }
  }
}

int main() {
  std::thread t1(increementXY, std::ref(X), std::ref(m1), "X");
  std::thread t2(increementXY, std::ref(Y), std::ref(m2), "Y");
  std::thread t3(consumeXY);

  t1.join();
  t2.join();
  t3.join();

  return 0;
}

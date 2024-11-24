#include <iostream>
#include <mutex>
#include <thread>

std::mutex m;
class Human {
private:
  char *name;

public:
  Human(char *name) : name(name) {};

  void Queue() {
    std::cout << "Human " << name << " queued" << std::endl;
    m.lock();
    std::cout << "Human " << name << " dequeued" << std::endl;
  };
};

int main() {
  char str1[] = "John";
  char str2[] = "Rohan";

  Human h1(str1);
  Human h2(str2);

  // Create threads that call Queue() on the respective Human objects
  std::thread t2(&Human::Queue, &h2); // Pass h2 to t2
  std::thread t1(&Human::Queue, &h1); // Pass h1 to t1

  // Join the threads to ensure they complete execution before the program exits
  t1.join();
  t2.join();

  return 0;
}

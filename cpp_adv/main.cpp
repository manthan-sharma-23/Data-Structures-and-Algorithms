#include <iostream>
#include <memory>

class MyClass {
public:
  MyClass() { std::cout << "MyClass created\n"; }
  ~MyClass() { std::cout << "MyClass destroyed\n"; }
};

int main() {
  std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();

  // Create a weak_ptr from a shared_ptr
  std::weak_ptr<MyClass> weakPtr = sharedPtr;

  // Convert weak_ptr to shared_ptr using lock()
  if (std::shared_ptr<MyClass> tempPtr = weakPtr.lock()) {
    // If object still exists, we can access it
    std::cout << "Object is still alive\n";
  } else {
    std::cout << "Object has been destroyed\n";
  }

  // Once sharedPtr is out of scope or reset, the object is destroyed
  sharedPtr.reset();

  // Check again if the object exists
  if (std::shared_ptr<MyClass> tempPtr = weakPtr.lock()) {
    std::cout << "Object is still alive\n";
  } else {
    std::cout << "Object has been destroyed\n";
  }

  return 0;
}


#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
class String
{
public:
  String() = default;

  String(const char *string)
  {
    std::cout << "Resource created !" << std::endl;
    len = std::strlen(string) + 1;
    str = new char[len];
    std::strcpy(str, string);
  }

  String(const String &other)
  {
    len = other.len + 1;
    str = new char[len];
    memcpy(str, other.str, len);
    std::cout << "Resource copied !" << std::endl;
  }

  String(String &&other) noexcept
  {
    std::cout << "Resource moved !" << std::endl;
    len = other.len + 1;
    str = other.str;

    other.len = 0;
    other.str = nullptr;
  }

  String &operator=(String &&other) noexcept
  {
    printf("Operator Moved !\n");

    if (this != &other)
    {
      delete str;
      len = other.len + 1;
      str = other.str;

      other.len = 0;
      other.str = nullptr;
    }
    return *this;
  }

  ~String()
  {
    delete[] str;
    std::cout << "Resource deleted !" << std::endl;
  }

  void print() { std::cout << str << std::endl; }

  char *str;
  int len;
};

class Entity
{
public:
  Entity(const String &name) : m_data(name) {}
  Entity(String &&name) : m_data(std::move(name)) {}

  ~Entity() { std::cout << "Entity destroyed !" << std::endl; }

private:
  String m_data;
};

void add(int &n) { n++; }

int main()
{
  String string = "Hello";
  String dest;

  dest = std::move(string);

  string.print();
  dest.print();
}

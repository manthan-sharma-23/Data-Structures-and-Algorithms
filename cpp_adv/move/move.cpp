#include <cstdint>
#include <cstring>

class String {
public:
  String() = default;
  String(const char *string) {
    m_size = strlen(string);
    m_data = new char[m_size + 1];
    memcpy(m_data, string, m_size);
  }

private:
  char *m_data;
  uint32_t m_size;
};

class Entity {

public:
  Entity(const String &name) : m_name(name) {}

private:
  String m_name;
};

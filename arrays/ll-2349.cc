#include <set>
#include <unordered_map>
using namespace std;

class NumberContainers {
public:
  unordered_map<int, int> i2n;
  unordered_map<int, set<int>> n2i;
  NumberContainers() {
    i2n = unordered_map<int, int>();
    n2i = unordered_map<int, set<int>>();
  }

  void change(int index, int number) {
    if (i2n.find(index) != i2n.end()) {
      int prevNumber = i2n[index];
      n2i[prevNumber].erase(index);
    }

    i2n[index] = number;
    n2i[number].insert(index);
  }

  int find(int number) {
    return (n2i.find(number) == n2i.end() || n2i[number].empty())
               ? -1
               : *n2i[number].begin();
  }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
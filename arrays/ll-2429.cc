class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int count = 0;
    int temp = num1;

    while (num1) {
      num1 = num1 & (num1 - 1);
      count++;
    }
    int res = 0;
    for (int i = 31; i >= 0 && count; i--) {
      if (num1 & (1 << i)) {
        count--;
        res |= (1 << i);
      }
    }

    for (int i = 0; i < 32 and count; i++) {
      if ((temp & (1 << i)) == 0) {
        count--;
        res |= (1 << i);
      }
    }
    return res;
  }
};
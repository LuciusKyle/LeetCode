class Solution {
 public:
  int findComplement(int num) {
    if (num == 0) return 1;
    unsigned int mask = 0xffffffff;
    int backup = num;
    while (backup != 0) {
      backup = backup >> 1;
      mask = mask << 1;
    }
    return mask ^ (~num);
  }
};
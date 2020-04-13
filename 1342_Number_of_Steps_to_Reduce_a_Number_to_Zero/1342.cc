
class Solution {
 public:
  int numberOfSteps(int num) {
    if (num == 0) return 0;
    int rtn = 0;
    while (num != 1) {
      rtn += (num & 1)? 2 : 1;
      num = num >> 1;
    }
    return rtn + 1;
  }
};



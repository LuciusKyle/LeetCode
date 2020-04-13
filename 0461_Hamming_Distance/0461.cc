


class Solution {
 public:
  int hammingDistance(int x, int y) {
    int rtn = 0;
    do {
      if ((1 & x) != (1 & y)) ++rtn;
      x = x >> 1;
      y = y >> 1;
    } while (x != y);
    return rtn;
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.hammingDistance(1, 4);
  return 0;
}
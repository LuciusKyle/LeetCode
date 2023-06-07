
class Solution {
 public:
  int minFlips(int a, int b, int c) {
    int flip_count = 0;
    while (a != 0 || b != 0 || c != 0) {
      const int bit_c = 1 & c, bit_a = 1 & a, bit_b = 1 & b;
      if (bit_c == 0)
        flip_count += (bit_a + bit_b);
      else if (bit_a == 0 && bit_b == 0)
        ++flip_count;
      a = (a >> 1);
      b = (b >> 1);
      c = (c >> 1);
    }
    return flip_count;
  }
};

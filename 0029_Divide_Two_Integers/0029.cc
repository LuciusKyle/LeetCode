
#include<cmath>

// this is not my solution. code was copied from LeetCode Discuss.
// https://leetcode.com/problems/divide-two-integers/discuss/13407/Detailed-Explained-8ms-C++-solution
class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (!divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long dvd = labs(dividend);
    long long dvs = labs(divisor);
    int res = 0;
    while (dvd >= dvs) {
      long long temp = dvs, multiple = 1;
      while (dvd >= (temp << 1)) {
        temp <<= 1;
        multiple <<= 1;
      }
      dvd -= temp;
      res += multiple;
    }
    return sign == 1 ? res : -res;
  }
};

#include <limits.h>
#include <math.h>

class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
      return INT_MAX;
    }
    int ans = dividend / divisor;
    if (ans >= INT_MAX)
      return INT_MAX;
    if (ans <= INT_MIN)
      return INT_MIN;
    return floor(ans);
  }
};

int main(void) {
  Solution sln;
  int result = sln.divide(-2147483648, -1);
  return 0;
}
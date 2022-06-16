
#include <limits.h>
#include <string.h>

#include <string>

using std::string;

constexpr int ma = INT_MAX;
constexpr int mi = INT_MIN;
constexpr long lma = LONG_MAX;

class Solution {
 public:
  bool isPalindrome(const int x) {
    long r_num = 0;
    int temp_num = abs(x);
    while (temp_num) {
      r_num *= 10;
      r_num += (temp_num % 10);
      temp_num /= 10;
    }
    return r_num == x;
  }
};

int main(void) {
  Solution sln;
  sln.isPalindrome(-121);
  return 0;
}

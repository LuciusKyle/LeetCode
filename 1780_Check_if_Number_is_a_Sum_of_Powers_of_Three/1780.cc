
#include <vector>

using std::vector;

class Solution {
 public:
  bool checkPowersOfThree(const int n) {
    if (n == 1) return true;
    if (n % 3 == 2) return false;
    return checkPowersOfThree(n / 3);
  }
};

#include <vector>

using std::vector;

const int kPowerOfThree[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};

class Solution {
 public:
  bool checkPowersOfThree(const int n) {
    return checkPowersOfThree(n, 0);
  }

 private:
  bool checkPowersOfThree(const int target, const size_t index) {
    if (index == std::end(kPowerOfThree) - std::begin(kPowerOfThree)) return false;
    if (target < kPowerOfThree[index]) return false;
    if (target == kPowerOfThree[index]) return true;
    return checkPowersOfThree(target, index + 1) || checkPowersOfThree(target - kPowerOfThree[index], index + 1);
  }
};
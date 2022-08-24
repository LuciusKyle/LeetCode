
#include <limits.h>

#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>

using std::cout;
using std::endl;

constexpr int kAnswers[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
const std::unordered_set kAnswersSet({1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467});

class Solution {
 public:
  bool isPowerOfThree(const int n) {
    return kAnswersSet.count(n);
    for (int i = 0; i < std::end(kAnswers) - std::begin(kAnswers); ++i)
      if (kAnswers[i] == n) return true;
    return false;
  }
};

int main(void) {
  for (int i = 0; i < 30; ++i) {
    size_t num = 1;
    for (int j = 0; j < i; ++j)
      num *= 3;
    if (INT_MAX < num) break;
    cout << num << endl;
  }
  return 0;
}

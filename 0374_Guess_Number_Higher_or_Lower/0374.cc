
#include <assert.h>

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

// assume the answer is 17.
int guess(int num) { return num == 17 ? 0 : (num < 17 ? -1 : 1); }

class Solution {
 public:
  int guessNumber(int n) {
    int lower_bound = 0;
    while (1 < n - lower_bound) {
      const int mid = (static_cast<long long>(lower_bound) + n) / 2;
      const int result = guess(mid);
      if (result == 0) return mid;
      if (result == -1)
        lower_bound = mid;
      else
        n = mid;
    }
    return guess(lower_bound) == 0 ? lower_bound : n;
  }
};

int main(void) {
  Solution sln;
  for (int i = 17; i < 171717; ++i) assert(17 == sln.guessNumber(i));
  return 0;
}

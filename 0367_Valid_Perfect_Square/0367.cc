
#include <assert.h>
#include <tbb/parallel_for.h>
#include <vector>  // for test sample only;

class Solution {
 public:
  bool isPerfectSquare(const int num) {
    int lower = 1;
    int upper = num;
    while (1 < upper - lower) {
      const size_t mid = (lower + upper) / 2;
      if (mid * mid < num)
        lower = mid;
      else if (num < mid * mid)
        upper = mid;
      else
        return true;
    }
    if (lower * lower == num || upper * upper == num)
      return true;
    else
      return false;
  }
};

constexpr size_t kTestSampleCount = 10000;

// solution is OK and beat 100% in LeetCode, there are some problem with the following test program.
int main(void) {
  Solution sln;
  assert(sln.isPerfectSquare(93025));
  assert(sln.isPerfectSquare(16));
  assert(!sln.isPerfectSquare(123));
  assert(sln.isPerfectSquare(1));

  std::vector<int> test_sample(kTestSampleCount, 0);
  tbb::parallel_for(size_t(1), kTestSampleCount, [&test_sample](size_t i) { test_sample[i] = (i * i); });

  // tbb::parallel_for(1, test_sample.back(), [&test_sample](int i) {
  //	});

  for (int i = 1, ii = 0; i < test_sample.back(); ++i) {
    if (i == test_sample[ii]) {
      assert(sln.isPerfectSquare(i));
      ++ii;
    } else {
      assert(!sln.isPerfectSquare(i));
    }
  }
  return 0;
}

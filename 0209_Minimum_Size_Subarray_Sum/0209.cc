
#include <assert.h>

#include <algorithm>
#include <execution>
#include <numeric>
#include <vector>

using std::vector;

class Solution {
 public:
  int minSubArrayLen(int target, const vector<int>& nums) {
    auto l_iter = nums.cbegin(), r_iter = nums.cbegin();
    int sum = 0;

    // enlarge slide windows.
    while (r_iter != nums.cend() && sum < target) sum += *r_iter++;
    if (sum < target) return 0;

    // slide the window and try to shrink.
    while (target <= (sum - *l_iter)) {
      sum -= *l_iter;
      ++l_iter;
    }
    while (r_iter != nums.cend()) {
      sum += *r_iter++;
      sum -= *l_iter++;
      while (target <= (sum - *l_iter)) {
        sum -= *l_iter;
        ++l_iter;
      }
    }

    // return.
    return r_iter - l_iter;
  }
};

int main(int argc, char * argv[]) {
  Solution sln;
  int rtn = sln.minSubArrayLen(11, {1, 2, 3, 4, 5});
  assert(rtn == 3);
  rtn = sln.minSubArrayLen(7, {2, 3, 1, 2, 4, 3});
  assert(rtn == 2);
  return 0;
}

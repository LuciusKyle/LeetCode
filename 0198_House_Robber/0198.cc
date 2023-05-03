
#include <assert.h>
#include <limits.h>

#include <vector>

using std::vector;

class Solution {
 public:
  int rob(const vector<int>& nums) {
    int rob_pre = 0, not_rob_pre = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int rob_this = nums[i] + not_rob_pre, not_rob_this = std::max(rob_pre, not_rob_pre);
      rob_pre = rob_this;
      not_rob_pre = not_rob_this;
    }
    return std::max(rob_pre, not_rob_pre);
  }
};

int main(int argc, char const* argv[]) {
  Solution sln;
  assert(4 == sln.rob({1, 2, 3, 1}));
  assert(12 == sln.rob({2, 7, 9, 3, 1}));
  return 0;
}

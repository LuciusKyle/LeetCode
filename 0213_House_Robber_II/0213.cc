
#include <assert.h>
#include <limits.h>

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int rob(const vector<int>& nums) {
    // rob first
    int rob_pre = nums[0], not_rob_pre = 0;
    for (int i = 1; i < nums.size() - 1; ++i) {
      int rob_this = nums[i] + not_rob_pre, not_rob_this = std::max(rob_pre, not_rob_pre);
      rob_pre = rob_this;
      not_rob_pre = not_rob_this;
    }
    int answer = std::max(rob_pre, not_rob_pre);

    // not rob first
    rob_pre = 0, not_rob_pre = 0;
    for (int i = 1; i < nums.size(); ++i) {
      int rob_this = nums[i] + not_rob_pre, not_rob_this = std::max(rob_pre, not_rob_pre);
      rob_pre = rob_this;
      not_rob_pre = not_rob_this;
    }
    return std::max({rob_pre, not_rob_pre, answer});
  }
};

int main(int argc, char const* argv[]) {
  Solution sln;
  // assert(3 == sln.rob({2, 3, 2}));
  // assert(4 == sln.rob({1, 2, 3, 1}));
  return 0;
}



#include <assert.h>
#include <limits.h>
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
 public:
  int longestConsecutive(const vector<int>& nums) {
    unordered_set<int> nums_set;
    nums_set.reserve(nums.size());
    for (const int num : nums) nums_set.insert(num);
    size_t rtn = 0;
    while (!nums_set.empty()) {
      size_t current_streak = 1;
      const int cur_num = *(nums_set.begin());
      int i = 1;
      while (0 < nums_set.count(cur_num - i)) {
        nums_set.erase(cur_num - i);
        ++i;
      }
      current_streak += (i - 1);
      i = 1;
      while (0 < nums_set.count(cur_num + i)) {
        nums_set.erase(cur_num + i);
        ++i;
      }
      current_streak += (i - 1);
      if (rtn < current_streak) rtn = current_streak;
      nums_set.erase(cur_num);
    }
    return static_cast<int>(rtn);
  }
};

int main(void) {
  Solution sln;
  assert(4 == sln.longestConsecutive({100, 4, 200, 1, 3, 2}));
  return 0;
}


#include <assert.h>

#include <vector>

using std::vector;

class Solution {
 public:
  int findPeakElement(const vector<int>& nums) {
    if (nums.size() == 1) return 0;
    if (nums[1] < nums[0]) return 0;
    if (nums[nums.size() - 2] < nums[nums.size() - 1]) return nums.size() - 1;
    for (size_t i = 1; i < nums.size() - 1; ++i)
      if (nums[i - 1] < nums[i] && nums[i + 1] < nums[i]) return i;

    return -1;
  }
};

int main(int argc, char const* argv[]) {
  Solution sln;
  int rtn = sln.findPeakElement({0, 1});
  assert(rtn == 1);
  rtn = sln.findPeakElement({1, 2, 3, 1});
  assert(rtn == 2);
  return 0;
}

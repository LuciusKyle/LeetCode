
#include <assert.h>
#include <limits.h>

#include <set>
#include <unordered_set>
#include <vector>

using std::set;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    vector<int> dict(nums.size(), 1);
    for (const int num : nums)
      if (0 < num && num < nums.size() + 1) dict[num - 1] = 0;
    for (int i = 0; i < nums.size(); ++i)
      if (dict[i]) return i + 1;
    return nums.size() + 1;
  }
};

int main(void) {
  vector<int> question{1, 2, 0};
  Solution sln;
  int rtn = sln.firstMissingPositive(question);
  assert(rtn == 3);
  return 0;
}

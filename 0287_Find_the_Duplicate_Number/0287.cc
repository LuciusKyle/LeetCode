
#include <assert.h>
#include <vector>

using std::vector;

class Solution {
 public:
  int findDuplicate(const vector<int>& nums) {
    vector<int> dict(nums.size(), -1);
    for (const int num : nums)
      if (dict[num] != -1)
        return num;
      else
        dict[num] = 0;

    return -1;
  }
};

int main(void) {
  Solution sln;
  assert(2 == sln.findDuplicate({1, 3, 4, 2, 2}));
  return 0;
}
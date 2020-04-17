
#include <algorithm>
#include <set>
#include <limits.h>
#include <vector>

using std::multiset;
using std::vector;

class Solution {
 public:
  bool find132pattern(const vector<int>& nums) {
    vector<int> cur_max_from_left(nums.size(), INT_MIN);
    for (int i = nums.size() - 1, cur_max = INT_MIN, pre_num = INT_MIN; i > 0; --i) { // "i > 0", not "i >= 0", don't touch the first number. 
      if (nums[i] != nums[i - 1] && cur_max < nums[i])
        cur_max = nums[i];
      cur_max_from_left[i] = cur_max;
    }
};

int main(void) {
  multiset<int> test{1, 2, 3, 6, 6, 6, 7};
  auto iter = test.lower_bound(1);
  --iter;

  Solution sln;
  // sln.find132pattern({1, 3, 2});
  sln.find132pattern({1, 2, 3, 4});
  
  return 0;
}

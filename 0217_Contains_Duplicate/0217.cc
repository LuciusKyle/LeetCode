
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
 public:
  bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> sets;
    sets.reserve(nums.size());
    for (const int num : nums)
      if (sets.count(num) > 0)
        return true;
      else
        sets.insert(num);
    return false;
  }
};


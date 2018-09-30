
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
 public:
  int singleNumber(const vector<int>& nums) {
    unordered_set<int> nums_set;
    for (const auto num : nums)
      if (nums_set.count(num) == 0)
        nums_set.insert(num);
      else
        nums_set.erase(num);
    return *(nums_set.begin());
  }
};

int main(void) { return 0; }

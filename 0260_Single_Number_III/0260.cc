
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
 public:
  vector<int> singleNumber(const vector<int>& nums) {
    unordered_set<int> nums_set;
    for (const int num : nums)
      if (nums_set.count(num) == 0)
        nums_set.insert(num);
      else
        nums_set.erase(num);

    return {nums_set.cbegin(), nums_set.cend()};
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.singleNumber({1, 2, 1, 3, 2, 5});
  return 0;
}
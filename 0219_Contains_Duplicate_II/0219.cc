
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
 public:
  bool containsNearbyDuplicate(const vector<int>& nums, int k) {
    if (k == 0) return false;
    unordered_set<int> nums_set;
    for (int i = 0; i < nums.size(); ++i) {
      if (k < i) nums_set.erase(nums[i - k - 1]);
      if (!nums_set.insert(nums[i]).second) return true;
    }
    return false;
  }
};

int main(void) {
  Solution sln;
  bool rtn = sln.containsNearbyDuplicate({1, 2, 3, 1}, 3);
  rtn = sln.containsNearbyDuplicate({1, 0, 1, 1}, 1);
  rtn = sln.containsNearbyDuplicate({1, 2, 3, 1, 2, 3}, 1);

  return 0;
}

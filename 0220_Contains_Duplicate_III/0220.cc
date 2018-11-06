
#include <assert.h>
#include <set>
#include <vector>

using std::multiset;
using std::vector;

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(const vector<int>& nums, const int k, const int t) {
    multiset<int> num_set;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (static_cast<size_t>(k) < i) num_set.erase(nums[i - k - 1]);
      const auto insertion_result = num_set.insert(nums[i]);
      auto next_iter = insertion_result;
      next_iter++;
      if (next_iter != num_set.end() && *next_iter - nums[i] <= t)
        return true;
      auto pre_iter = insertion_result;
      --pre_iter;
      if (insertion_result != pre_iter && pre_iter != num_set.end() && nums[i] - *pre_iter <= t)
        return true;
    }
    return false;
  }
};

int main(void) {
  Solution sln;
  assert(sln.containsNearbyAlmostDuplicate({1, 2, 3, 1}, 3, 0));
  assert(sln.containsNearbyAlmostDuplicate({1, 0, 1, 1}, 1, 2));
  assert(!sln.containsNearbyAlmostDuplicate({1, 5, 9, 1, 5, 9}, 2, 3));
  assert(!sln.containsNearbyAlmostDuplicate({-1, 2147483647}, 1, 2147483647));
  return 0;
}

#include <set>
#include <vector>

using std::multiset;
using std::vector;

class Solution {
 public:
  vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    multiset<int> num_set;
    for (int i = 0; i < k; ++i)
      num_set.insert(nums[i]);
    vector<int> result;
    result.reserve(nums.size() - k + 1);
    result.push_back(*num_set.crbegin());
    for (int i = k; i < nums.size(); ++i) {
      num_set.insert(nums[i]);
      num_set.erase(num_set.find(nums[i - k]));
      result.push_back(*num_set.crbegin());
    }
    return result;
  }
};
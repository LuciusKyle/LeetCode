
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
 public:
  int majorityElement(const vector<int>& nums) {
    unordered_map<int, size_t> ele_count;
    ele_count.reserve(nums.size());
    const size_t bottle_neck_size = nums.size() / 2;
    for (const int num : nums) {
      if (0 < ele_count.count(num))
        ++ele_count.at(num);
      else
        ele_count.insert({num, 1});
      if (bottle_neck_size < ele_count.at(num)) return num;
    }
    return 0;
  }
};
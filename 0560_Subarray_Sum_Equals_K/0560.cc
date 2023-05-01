
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::vector;

class Solution {
 public:
  int subarraySum(const vector<int>& nums, int k) {
    std::unordered_map<int, int> prefix_sum_map;
    prefix_sum_map.reserve(nums.size() + 32);
    int prefix_sum = 0;
    int answer = 0;
    for (const int val : nums) {
      ++prefix_sum_map[prefix_sum];
      prefix_sum += val;
      const auto iter = prefix_sum_map.find(prefix_sum - k);
      if (iter != prefix_sum_map.end())
        answer += iter->second;
    }
    return answer;
  }
};

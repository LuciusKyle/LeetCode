
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::vector;

class Solution {
 public:
  int subarraySum(const vector<int>& nums, int k) {
    std::multiset<int> prefix_sum_set;
    // prefix_sum_set.reserve(nums.size() + 32);
    int prefix_sum = 0;
    int answer = 0;
    for (const int val : nums) {
      prefix_sum_set.insert(prefix_sum);
      prefix_sum += val;
      answer += prefix_sum_set.count(prefix_sum - k);
    }
    return answer;
  }
};

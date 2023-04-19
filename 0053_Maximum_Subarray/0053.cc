
#include <limits.h>

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int maxSubArray(const vector<int>& nums) {
    int prefix_sum = 0, min_prefix_sum = 0, answer = nums[0];
    for (const int val : nums) {
      prefix_sum += val;
      answer = std::max(answer, prefix_sum - min_prefix_sum);
      min_prefix_sum = std::min(min_prefix_sum, prefix_sum);
    }
    return answer;
  }
};

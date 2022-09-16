
#include <limits.h>

#include <algorithm>
#include <vector>

using std::vector;

// recurse, beats 12%.
class Solution {
 public:
  int maximumScore(const vector<int>& nums, const vector<int>& multipliers) {
    vector<vector<int>> answers_cache(multipliers.size(), vector<int>(multipliers.size(), INT_MIN));
    return maximumScore(nums, multipliers, 0, nums.size() - 1, answers_cache);
  }

 private:
  int maximumScore(const vector<int>& nums, const vector<int>& multipliers, const int left_index, const int right_index, vector<vector<int>>& answers_cache) {
    const int curr_multipliers_pos = nums.size() - 1 - right_index + left_index;
    if (curr_multipliers_pos == multipliers.size()) return 0;
    if (answers_cache[curr_multipliers_pos][left_index] == INT_MIN) {
      const int result = std::max(multipliers[curr_multipliers_pos] * nums[left_index] + maximumScore(nums, multipliers, left_index + 1, right_index, answers_cache), multipliers[curr_multipliers_pos] * nums[right_index] + maximumScore(nums, multipliers, left_index, right_index - 1, answers_cache));
      answers_cache[curr_multipliers_pos][left_index] = result;
      return result;
    } else
      return answers_cache[curr_multipliers_pos][left_index];
  }
};
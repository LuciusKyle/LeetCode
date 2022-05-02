
#include <assert.h>
#include <limits.h>

#include <algorithm>
#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

class Solution {
 public:
  int maxCoins(const vector<int>& nums) {
    vector<vector<int>> max_result_cache(nums.size() + 1, vector<int>(nums.size() + 1, INT_MIN));

    int max_score = -1;
    for (int i = 0; i < nums.size(); ++i) {
      int left_max = i == 0 ? 0 : maxCoins(nums, 0, i, max_result_cache);
      int right_max = i == (nums.size() - 1) ? 0 : maxCoins(nums, i + 1, nums.size(), max_result_cache);
      int score = nums[i] * (i == 0 ? 1 : nums[i - 1]) * (i == nums.size() - 1 ? 1 : nums[i + 1]) + left_max + right_max;
      if (max_score < score) max_score = score;
    }
    return max_score;
  }

 private:
  int maxCoins(const vector<int>& nums, const size_t begin_index, const size_t end_index, vector<vector<int>>& max_result_cache) {
    if (begin_index + 1 == end_index) return nums[begin_index];
    if (max_result_cache[begin_index][end_index] != INT_MIN) return max_result_cache[begin_index][end_index];
    int max_score = -1;
    for (size_t i = begin_index; i < end_index; ++i) {
      int left_max = i == begin_index ? 0 : maxCoins(nums, begin_index, i, max_result_cache);
      int right_max = i == end_index - 1 ? 0 : maxCoins(nums, i + 1, end_index, max_result_cache);
      int score = nums[i] * (i == 0 ? 1 : nums[i - 1]) * (i == nums.size() - 1 ? 1 : nums[i + 1]) + left_max + right_max;
      if (max_score < score) max_score = score;
    }
    max_result_cache[begin_index][end_index] = max_score;
    return max_score;
  }
};

int main(void) {
  Solution sln;
  int ret = sln.maxCoins(vector{1, 5});
  assert(ret == 10);
  ret = sln.maxCoins(vector{3, 1, 5, 8});
  assert(ret == 167);
  return 0;
}

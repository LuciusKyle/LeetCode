
#include <vector>
#include <limits.h>0581 

using std::vector;

class Solution {
 public:
  int findUnsortedSubarray(const vector<int>& nums) {
    vector<int> cur_max_from_front(nums.size(), 0), cur_min_from_end(nums.size(), 0);
    cur_max_from_front.reserve(nums.size());
    for (int i = 0, j = nums.size() - 1, max_val = INT_MIN, min_val = INT_MAX; i < nums.size(); ++i, --j) {
      if (max_val < nums[i]) max_val = nums[i];
      cur_max_from_front[i] = max_val;
      if (nums[j] < min_val) min_val = nums[j];
      cur_min_from_end[j] = min_val;
    }

    int start_index = 0;
    while (start_index < nums.size() && nums[start_index] == cur_min_from_end[start_index])
      ++start_index;

    int end_index = cur_max_from_front.size() - 1;
    while (start_index < end_index && nums[end_index] == cur_max_from_front[end_index])
      --end_index;
    return end_index <= start_index ? 0 : end_index - start_index + 1;
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.findUnsortedSubarray({2, 6, 4, 8, 10, 9, 15});
	return 0;
}

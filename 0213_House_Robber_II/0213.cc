
#include <assert.h>
#include <limits.h>
#include <vector>

using std::vector;

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() < 4) {
      int rtn = 0;
      for (const int num : nums)
        if (rtn < num) rtn = num;
      return rtn;
    }
    vector<int> dynamic_programing(nums.size() - 1, INT_MIN);
    dynamic_programing[0] = nums[nums.size() - 2];
    dynamic_programing[1] = nums[nums.size() - 2] < nums[nums.size() - 3] ? nums[nums.size() - 3] : nums[nums.size() - 2];
    int rob_first = rob(nums.data(), nums.size() - 1, dynamic_programing.data());
    dynamic_programing.assign(nums.size() - 1, INT_MIN);
    dynamic_programing[0] = nums.back();
    dynamic_programing[1] = nums.back() < *(++nums.crbegin()) ? *(++nums.crbegin()) : nums.back();
    int rob_last = rob(&(nums.data()[1]), nums.size() - 1, dynamic_programing.data());
    return rob_first < rob_last ? rob_last : rob_first;
  }

 private:
  int rob(const int* nums, const size_t num_size, int* dynamic_programing) {
    if (dynamic_programing[num_size - 1] != INT_MIN) {
      return dynamic_programing[num_size - 1];
    }
    const int rob_from_here = nums[0] + rob(nums + 2, num_size - 2, dynamic_programing);
    const int rob_from_next = rob(nums + 1, num_size - 1, dynamic_programing);
    const int rtn_val = rob_from_here < rob_from_next ? rob_from_next : rob_from_here;
    dynamic_programing[num_size - 1] = rtn_val;
    return rtn_val;
  }
};

int main(int argc, char const* argv[]) {
  Solution sln;
  // assert(3 == sln.rob({2, 3, 2}));
  // assert(4 == sln.rob({1, 2, 3, 1}));
  return 0;
}

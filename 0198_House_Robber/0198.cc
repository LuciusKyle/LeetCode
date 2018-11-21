
#include <assert.h>
#include <limits.h>
#include <vector>

using std::vector;

class Solution {
 public:
  int rob(const vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> dynamic_programing(nums.size(), INT_MIN);
    dynamic_programing[0] = nums.back();
    if (1 < nums.size())
      dynamic_programing[1] = nums.back() < *(++nums.crbegin()) ? *(++nums.crbegin()) : nums.back();
    return rob(nums.data(), nums.size(), dynamic_programing.data());
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
  assert(4 == sln.rob({1, 2, 3, 1}));
  assert(12 == sln.rob({2, 7, 9, 3, 1}));
  return 0;
}

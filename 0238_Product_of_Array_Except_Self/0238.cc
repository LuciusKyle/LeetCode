
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int temp_product = 1;
    size_t count_zero = nums[0] == 0 ? 1 : 0;
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] == 0) ++count_zero;
      temp_product *= nums[i];
    }
    vector<int> rtn(nums.size(), 0);
    if (1 < count_zero) return rtn;
    if (1 == count_zero) {
      temp_product = 1;
      size_t index_of_zero = 0;
      for (size_t i = 0; i < nums.size(); ++i)
        if (nums[i] != 0)
          temp_product *= nums[i];
        else
          index_of_zero = i;
      rtn[index_of_zero] = temp_product;
      return rtn;
    }
    rtn[0] = temp_product;
    for (size_t i = 1; i < rtn.size(); ++i) {
      temp_product = (temp_product / nums[i]) * nums[i - 1];
      rtn[i] = temp_product;
    }
    return rtn;
  }
};

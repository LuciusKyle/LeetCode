
#include <vector>

using std::vector;

class Solution {
 public:
  long long zeroFilledSubarray(vector<int>& nums) {
    long long answer = 0;
    int contiguous_zeros = 0;
    for (int i = 0, pre_is_zero = false; i < nums.size(); ++i)
      if (nums[i] == 0)
        ++contiguous_zeros;
      else {
        for (int j = 1; j <= contiguous_zeros; ++j)
          answer += j;
        contiguous_zeros = 0;
      }
    for (int j = 1; j <= contiguous_zeros; ++j)
      answer += j;
    return answer;
  }
};
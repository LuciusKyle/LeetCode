
#include <vector>

using std::vector;

class Solution {
 public:
  int lengthOfLIS(const vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> result(nums.size(), 1);
    int rtn = 1;
    for (size_t i = 1; i < result.size(); ++i)
      for (size_t ii = 0; ii < i; ++ii)
        if (nums[ii] < nums[i])
          if (result[i] < result[ii] + 1) {
            result[i] = result[ii] + 1;
            rtn = rtn < result[i] ? result[i] : rtn;
          }
    return rtn;
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.lengthOfLIS({1, 3, 6, 7, 9, 4, 10, 5, 6});

  return 0;
}
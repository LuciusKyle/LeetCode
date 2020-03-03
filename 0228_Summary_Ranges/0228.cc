
#include <limits.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  vector<string> summaryRanges(const vector<int>& nums) {
    vector<string> rtn;
    if (nums.empty()) return rtn;
    rtn.push_back(std::to_string(nums.front()));
    int64_t pre_num = nums.front();
    int64_t range_start = pre_num;
    bool continuous = true;
    for (int i = 1 /*start from 1 not 0*/; i < nums.size(); ++i) {
      if (continuous)
        if (nums[i] - pre_num == 1) {
          pre_num = nums[i];
          continue;
        } else {
          continuous = false;
          if (nums[i - 1] != range_start) rtn.back().append("->" + std::to_string(nums[i - 1]));
        }
      rtn.push_back(std::to_string(nums[i]));
      pre_num = nums[i];
      range_start = nums[i];
      continuous = true;
    }
    if (continuous && nums.back() != range_start) rtn.back().append("->" + std::to_string(nums.back()));
    return rtn;
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.summaryRanges({0, 1, 2, 4, 5, 7});
  rtn = sln.summaryRanges({0, 2, 3, 4, 6, 8, 9});
  rtn = sln.summaryRanges({-2147483648,-2147483647,2147483647});
  return 0;
}

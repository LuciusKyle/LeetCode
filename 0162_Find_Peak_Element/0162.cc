
#include <vector>

using std::vector;

class Solution {
 public:
  int findPeakElement(const vector<int>& nums) {
    size_t lower_index = 0;
    size_t upper_index = nums.size() - 1;

    if (isPeak(lower_index, nums)) return lower_index;
    if (isPeak(upper_index, nums)) return upper_index;
    while (upper_index - lower_index > 1) {
      const size_t mid_index = (lower_index + upper_index) / 2;
      if (isPeak(mid_index, nums)) return mid_index;
      if (nums[mid_index - 1] < nums[mid_index])
        lower_index = mid_index;
      else
        upper_index = mid_index;
    }
    if (isPeak(lower_index, nums)) return lower_index;
    if (isPeak(upper_index, nums)) return upper_index;
    return 0;
  }

 private:
  bool isPeak(const size_t index, const vector<int>& nums) {
    if (index == 0) return nums[1] < nums[0];
    if (index == nums.size() - 1) return nums[index - 1] < nums[index];
    return nums[index - 1] < nums[index] && nums[index + 1] < nums[index];
  }
};

int main(int argc, char const *argv[])
{
  Solution sln;
  int rtn = sln.findPeakElement({0, 1});
  return 0;
}



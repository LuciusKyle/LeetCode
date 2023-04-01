
#include <vector>

using std::vector;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l_index = 0, r_index = nums.size() - 1;
    while (l_index + 1 < r_index) {
      const int mid_index = l_index + (r_index - l_index) / 2;
      if (nums[mid_index] < target)
        l_index = mid_index;
      else if (target < nums[mid_index])
        r_index = mid_index;
      else
        return mid_index;
    }
    if (l_index + 1 == r_index && nums[r_index] == target)
      return r_index;
    if (nums[l_index] == target)
      return l_index;
    else
      return -1;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;

  return 0;
}

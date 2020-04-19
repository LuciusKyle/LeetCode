
#include <vector>

using std::vector;

class Solution {
 public:
  int arrayNesting(const vector<int>& nums) {
    vector<int> count(nums.size(), -1);
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i)
      if (count[i] == -1) {
        int len = 0, next_index = i;
        do {
          count[next_index] = 0;
          next_index = nums[next_index];
          ++len;
        } while (count[next_index] == -1);
        if (ret < len) ret = len;
      }

    return ret;
  }
};

int main(void) {
  Solution sln;
  int ret = sln.arrayNesting({5, 4, 0, 3, 1, 6, 2});
  return 0;
}

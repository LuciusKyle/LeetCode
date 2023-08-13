
#include <assert.h>

#include <vector>

using std::vector;

class Solution {
 public:
  bool validPartition(const vector<int>& nums) {
    vector<bool> results(nums.size(), false);
    if (nums[0] == nums[1])
      results[1] = true;
    if (nums.size() == 2) return results[1];
    if (nums.size() > 2 && ((nums[0] == nums[1] && nums[1] == nums[2]) || (nums[0] == nums[1] - 1 && nums[2] == nums[1] + 1)))
      results[2] = true;
    for (int i = 1; i + 2 < nums.size(); ++i)
      if (results[i - 1]) {
        if (nums[i + 0] == nums[i + 1])
          results[i + 1] = true;
        if (((nums[i + 0] == nums[i + 1] && nums[i + 1] == nums[i + 2]) || (nums[i + 0] == nums[i + 1] - 1 && nums[i + 2] == nums[i + 1] + 1)))
          results[i + 2] = true;
      }
    if (!results.back() && nums[nums.size() - 1] == nums[nums.size() - 2]) return results[results.size() - 3];
    return results.back();
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  assert(!sln.validPartition({1, 1, 1, 2}));
  return 0;
}

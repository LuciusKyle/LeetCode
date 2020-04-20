
#include <algorithm>
// #include <execution>
#include <vector>

using std::vector;

class Solution {
 public:
  int arrayPairSum(vector<int>& nums) {
    // std::sort(std::execution::par, nums.begin(), nums.end());
    std::sort(nums.begin(), nums.end());
    int ret = 0;
    for (int i = 0; i < nums.size(); i += 2) ret += nums[i];

    return ret;
  }
};

int main(void) {
  Solution sln;
  return 0;
}
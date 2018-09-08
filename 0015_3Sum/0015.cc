
#include <assert.h>
#include <vector>
#include<algorithm>

using std::vector;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
  }
};



#include <assert.h>
#include <math.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    for (const int num : nums) {
      if (nums[std::abs(num)] < 0)
        return std::abs(num);
      else
        nums[std::abs(num)] = -nums[std::abs(num)];
    }
    return -1;
  }
};

int main(void) {
  Solution sln;
  // assert(2 == sln.findDuplicate({1, 3, 4, 2, 2}));
  for (int i = 1, sum = 0; i < 10; ++i) {
    sum += i;
    cout << "i: " << i << "\tsum: " << sum << "\n";
  }
  return 0;
}

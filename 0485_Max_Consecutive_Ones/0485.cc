
#include <vector>

using std::vector;

class Solution {
 public:
  int findMaxConsecutiveOnes(const vector<int>& nums) {
    int rtn = 0;
    int consective = 0;
    for (const int num : nums)
      if (num == 1)
        ++consective;
      else {
        if (rtn < consective) rtn = consective;
        consective = 0;
      }

    if (rtn < consective) rtn = consective;
    return rtn;
  }
};

int main(void) {
  Solution sln;
  sln.findMaxConsecutiveOnes({1});
  return 0;
}

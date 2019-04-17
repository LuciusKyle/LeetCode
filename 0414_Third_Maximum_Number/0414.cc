
#include <limits.h>
#include <array>
#include <set>
#include <vector>

using std::array;
using std::set;
using std::vector;

class Solution {
 public:
  int thirdMax(const vector<int>& nums) {
    set<int> max_num;
    for (const int num : nums) {
      max_num.insert(num);
      if (max_num.size() == 4) max_num.erase(max_num.begin());
    }
    if (max_num.size() <3)
      return *max_num.crbegin();
    else
      return *max_num.cbegin();
  }
};


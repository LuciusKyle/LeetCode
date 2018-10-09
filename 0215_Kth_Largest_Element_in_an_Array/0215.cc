
#include <limits.h>
#include <set>
#include <vector>

using std::multiset;
using std::vector;

class Solution {
 public:
  int findKthLargest(const vector<int>& nums, int k) {
    multiset<int> k_nums;
    k_nums.insert(INT_MIN);
    for (const int num : nums) {
      if (*k_nums.cbegin() <= num) k_nums.insert(num);
      if (k_nums.size() > k) k_nums.erase(k_nums.begin());
    }
    return *k_nums.cbegin();
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.findKthLargest({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4);
  rtn = sln.findKthLargest({3, 2, 1, 5, 6, 4}, 2);

  return 0;
}

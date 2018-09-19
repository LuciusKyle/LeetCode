
#include <assert.h>
#include <limits.h>
#include <set>
#include <unordered_set>
#include <vector>

using std::set;
using std::unordered_set;
using std::vector;

class Solution_V1 {
 public:
  int firstMissingPositive(vector<int>& nums) {
    set<int> result;
    for (const int num : nums)
      if (num > 0) result.insert(num);

    int pre = 0;
    for (const int num : result)
      if (num - pre > 1)
        return pre + 1;
      else
        pre = num;
    if (result.empty()) return 1;
    return *(result.cend()) + 1;
  }
};

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> result;
    result.reserve(nums.size());
    int min_positive = -1;
    for (const int num : nums)
      if (num > 0) {
        if (min_positive < 0 || num < min_positive) min_positive = num;
        result.insert(num);
      }
    if (min_positive == -1 || min_positive > 1) return 1;
    for (int i = min_positive; i < INT_MAX; ++i) {
      if (result.count(i) == 0) return i;
    }
    return 0;
  }
};

int main(void) {
  vector<int> question{1, 2, 0};
  Solution sln;
  int rtn = sln.firstMissingPositive(question);
  assert(rtn == 3);
  return 0;
}

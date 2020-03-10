
#include <vector>

using std::vector;

constexpr int arr[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

class Solution {
 public:
  int findNumbers(const vector<int>& nums) {
    int count = 0;
    for (int num : nums)
      for (int i = 0; i < std::end(arr) - std::begin(arr); ++i)
        if (num / arr[i] == 0) {
          if (i % 2 == 0) ++count;
          break;
        }

    return count;
  }
};
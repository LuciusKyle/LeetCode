
#include <math.h>

#include <numeric>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> findClosestElements(const vector<int>& arr, const int k, const int target) {
    int l_index = 0, r_index = arr.size() - 1;
    if (arr[l_index] == target) r_index = l_index;
    if (arr[r_index] == target) l_index = r_index;
    while (1 < r_index - l_index) {
      const int mid_val = arr[(l_index + r_index) / 2];
      if (target < mid_val) {
        r_index = (l_index + r_index) / 2;
      } else if (mid_val < target) {
        l_index = (l_index + r_index) / 2;
      } else {
        l_index = (l_index + r_index) / 2;
        r_index = l_index;
      }
    }
    if (r_index != l_index && std::abs(arr[r_index] - target) < std::abs(arr[l_index] - target))
      l_index = r_index;
    else
      r_index = l_index;

    while (r_index - l_index != k - 1) {
      if (l_index == 0)
        ++r_index;
      else if (r_index == arr.size() - 1)
        --l_index;
      else {
        if (std::abs(arr[r_index + 1] - target) < std::abs(arr[l_index - 1] - target)) {
          ++r_index;
        } else
          --l_index;
      }
    }
    return {arr.cbegin() + l_index, arr.cbegin() + r_index + 1};
  }
};

int main(void) {
  Solution sln;
  auto ret = sln.findClosestElements({1, 1, 1, 10, 10, 10}, 1, 9);
  ret = sln.findClosestElements({0, 0, 0, 1, 3, 5, 6, 7, 8, 8}, 2, 2);
  return 0;
}
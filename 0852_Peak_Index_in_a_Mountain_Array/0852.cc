
#include <vector>

using std::vector;

class Solution {
 public:
  int peakIndexInMountainArray(const vector<int>& arr) {
    int l_index = 0, r_index = arr.size() - 1, mid_index = (arr.size() - 1) / 2;
    while (!(arr[mid_index - 1] < arr[mid_index] && arr[mid_index + 1] < arr[mid_index])) {
      if (arr[mid_index - 1] < arr[mid_index])
        l_index = mid_index;
      else
        r_index = mid_index;
      mid_index = l_index + (r_index - l_index) / 2;
    }
    return mid_index;
  }
};

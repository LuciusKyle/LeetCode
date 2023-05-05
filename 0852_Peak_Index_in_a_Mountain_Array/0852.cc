
#include <vector>

using std::vector;

class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    return peakIndexInMountainArray(arr, 0, arr.size() - 1);
  }

 private:
  int peakIndexInMountainArray(const vector<int>& arr, int start, int end) {
    if (end == start + 2) return start + 1;
    const int mid_index = start + (end - start) / 2;
    if (arr[mid_index - 1] < arr[mid_index] && arr[mid_index] < arr[mid_index + 1])
      return peakIndexInMountainArray(arr, mid_index, end);
    else if (arr[mid_index + 1] < arr[mid_index] && arr[mid_index] < arr[mid_index - 1])
      return peakIndexInMountainArray(arr, start, mid_index);
    else
      return mid_index;
  }
};

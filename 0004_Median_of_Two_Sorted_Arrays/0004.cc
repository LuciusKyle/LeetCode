
#include <assert.h>

#include <algorithm>
#include <vector>

using std::vector;

// O(n) solution.
class Solution {
 public:
  double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    const size_t all_size = nums1.size() + nums2.size();
    vector<int> merged(all_size);
    for (size_t i = 0, i1 = 0, i2 = 0; i < all_size; ++i) {
      if (i1 < nums1.size()) {
        if (i2 < nums2.size()) {
          if (nums1[i1] < nums2[i2]) {
            merged[i] = nums1[i1++];
          } else {
            merged[i] = nums2[i2++];
          }
        } else {
          merged[i] = nums1[i1++];
        }
      } else {
        merged[i] = nums2[i2++];
      }
    }
    if (all_size % 2 == 1)
      return double(merged[all_size / 2]);
    else
      return (merged[all_size / 2] + merged[all_size / 2 - 1]) / 2.0;
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.findMedianSortedArrays({1, 3}, {2});
  assert(rtn - 2.0 < 0.000001);
  rtn = sln.findMedianSortedArrays({1, 2}, {3, 4});
  assert(rtn - 2.5 < 0.000001);
  return 0;
}
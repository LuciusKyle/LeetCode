
#include <vector>

using std::vector;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, const vector<int>& nums2, int n) {
    int cur_index = m + n;
    while (0 < cur_index) {
      if (n == 0) break;  // or return.
      if (m == 0) {
        nums1[--cur_index] = nums2[--n];
        continue;
      }

      if (nums1[m - 1] < nums2[n - 1]) {
        --n;
        nums1[--cur_index] = nums2[n];
      } else {
        --m;
        nums1[--cur_index] = nums1[m];
      }
    }
  }
};

int main(void) {
  vector vec1{1, 2, 3, 0, 0, 0};
  vector vec2{2, 5, 6};
  Solution sln;
  sln.merge(vec1, 3, vec2, static_cast<int>(vec2.size()));

  vec1 = {0};
  vec2 = {1};
  sln.merge(vec1,0,vec2,1);

  return 0;
}

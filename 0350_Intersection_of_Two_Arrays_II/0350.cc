
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;

// this solution beat 100%.
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    auto& shorter_vec = nums1.size() < nums2.size() ? nums1 : nums2;
    auto& longer_vec = nums1.size() < nums2.size() ? nums2 : nums1;
    std::sort(shorter_vec.begin(), shorter_vec.end());
    std::sort(longer_vec.begin(), longer_vec.end());

    vector<int> rtn;

    auto iter_s = shorter_vec.cbegin(), iter_l = longer_vec.cbegin();
    while (iter_s != shorter_vec.cend() && iter_l != longer_vec.cend()) {
      if (*iter_l < *iter_s)
        ++iter_l;
      else if (*iter_s < *iter_l)
        ++iter_s;
      else {
        rtn.push_back(*iter_l);
        ++iter_l;
        ++iter_s;
      }
    }
    return rtn;
  }
};

// this should be better, but only 50% beat.
class Solution_should_be_better {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    vector<int> rtn;
    auto iter_1 = nums1.cbegin(), iter_2 = nums2.cbegin();
    while (iter_1 != nums1.cend() && iter_2 != nums2.cend()) {
      if (*iter_2 < *iter_1)
        ++iter_2;
      else if (*iter_1 < *iter_2)
        ++iter_1;
      else {
        rtn.push_back(*iter_2);
        ++iter_2;
        ++iter_1;
      }
    }
    return rtn;
  }
};

int main(void) {
  Solution sln;
  vector vec1{1, 2, 2, 1};
  vector vec2{2, 2};
  auto rtn = sln.intersect(vec1, vec2);
  return 0;
}
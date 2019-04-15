
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    const auto& shorter_vec = nums1.size() < nums2.size() ? nums1 : nums2;
    const auto& longer_vec = nums1.size() < nums2.size() ? nums2 : nums1;
    const unordered_set<int> num_set(longer_vec.cbegin(), longer_vec.cend());
    unordered_set<int> result_set;
    for (const int num : shorter_vec)
      if (num_set.count(num) != 0) result_set.insert(num);
    return {result_set.cbegin(), result_set.cend()};
  }
};

int main(void) {
  Solution sln;
  return 0;
}
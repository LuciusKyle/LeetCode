
#include <limits.h>

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int maxUncrossedLines(const vector<int>& nums1, const vector<int>& nums2) {
    vector<int> curr_LCS(nums1.size(), 1), next_LCS(nums1.size());
    for (int i = 0; i < nums1.size(); ++i) {
      if (nums1[i] == nums2.front())
        break;
      curr_LCS[i] = 0;
    }
    for (int i = 1; i < nums2.size(); ++i) {
      next_LCS[0] = ((nums1[0] == nums2[i] || curr_LCS[0] != 0) ? 1 : 0);
      for (int j = 1; j < nums1.size(); ++j)
        if (nums1[j] == nums2[i])
          next_LCS[j] = std::max({next_LCS[j - 1], curr_LCS[j], curr_LCS[j - 1] + 1});
        else
          next_LCS[j] = std::max(next_LCS[j - 1], curr_LCS[j]);
      curr_LCS.swap(next_LCS);
    }
    return curr_LCS.back();
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  sln.maxUncrossedLines({1}, {1, 3});
  return 0;
}

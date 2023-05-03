
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> answer(2, vector<int>());
    vector<unsigned int> bitmap1(2001 / 32 + 1), bitmap2(2001 / 32 + 1);
    for (const int num : nums1) bitmap1[(num + 1000) / 32] |= 1 << ((num + 1000) % 32);
    for (const int num : nums2) {
      if ((bitmap2[(num + 1000) / 32] & (1 << ((num + 1000) % 32))) != 0)
        continue;
      if ((bitmap1[(num + 1000) / 32] & (1 << ((num + 1000) % 32))) == 0)
        answer[1].push_back(num);
      bitmap2[(num + 1000) / 32] |= 1 << ((num + 1000) % 32);
    }
    for (const int num : nums1) {
      if ((bitmap1[(num + 1000) / 32] & (1 << ((num + 1000) % 32))) == 0)
        continue;
      if ((bitmap2[(num + 1000) / 32] & (1 << ((num + 1000) % 32))) == 0)
        answer[0].push_back(num);
      bitmap1[(num + 1000) / 32] &= ~(1 << ((num + 1000) % 32));
    }
    return answer;
  }
};

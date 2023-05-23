
#include <limits.h>

#include <vector>

using std::vector;

class Solution {
 public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    vector<int> pos_map(2001, INT_MAX);
    for (int i = 0; i < nums1.size(); ++i)
      pos_map[nums1[i]] = i;
    vector<int> line_count(nums2.size(), -1);
    int answer = 0;
    for (int i = 0; i < nums2.size(); ++i) {
      if (pos_map[nums2[i]] == INT_MAX)
        continue;
      int max_if_draw_this = 1;
      for (int j = 0; j < i; ++j)
        if (line_count[j] != -1 && pos_map[nums2[j]] < pos_map[nums2[i]]) {
          max_if_draw_this = std::max(max_if_draw_this, line_count[j] + 1);
        }
      line_count[i] = max_if_draw_this;
      answer = std::max(answer, max_if_draw_this);
    }
    return answer;
  }
};

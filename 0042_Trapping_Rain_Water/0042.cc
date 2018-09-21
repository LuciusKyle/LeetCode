
#include <assert.h>
#include <algorithm>  // for std::min();
#include <vector>

using std::vector;

class Solution {
 public:
  int trap(const vector<int>& heights) {
    vector<int> right_max(heights.size(), 0);
    int max = -1;
    for (int i = heights.size() - 1; i >= 0; --i) {
      if (max < heights[i]) max = heights[i];
      right_max[i] = max;
    }
    max = -1;
    int rain_volume = 0;
    for (size_t i = 0; i < heights.size(); ++i)
      if (max < heights[i])
        max = heights[i];
      else
        rain_volume += std::min(max, right_max[i]) - heights[i];
    return rain_volume;
  }
};

int main(void) {
  vector<int> question{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

  Solution sln;
  int rtn = sln.trap(question);
  assert(rtn == 6);
  return 0;
}

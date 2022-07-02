
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    std::sort(horizontalCuts.begin(), horizontalCuts.end());
    std::sort(verticalCuts.begin(), verticalCuts.end());
    const int h_size = horizontalCuts.size(), v_size = verticalCuts.size();
    int max_horizontal_distance = std::max(h - horizontalCuts.back(), horizontalCuts[0]), max_vertical_distance = std::max(w - verticalCuts.back(), verticalCuts[0]);
    for (int i = 1; i < h_size; ++i)
      if (max_horizontal_distance < horizontalCuts[i] - horizontalCuts[i - 1])
        max_horizontal_distance = horizontalCuts[i] - horizontalCuts[i - 1];

    for (int i = 1; i < v_size; ++i)
      if (max_vertical_distance < verticalCuts[i] - verticalCuts[i - 1])
        max_vertical_distance = verticalCuts[i] - verticalCuts[i - 1];

    return size_t(max_vertical_distance) * size_t(max_horizontal_distance) % 1000000007;
  }
};
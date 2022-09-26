
#include <limits.h>

#include <map>
#include <tuple>
#include <unordered_map>
#include <vector>

using std::vector;

class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    int left_most = INT_MAX, right_most = INT_MIN, up_most = INT_MIN, down_most = INT_MAX;
    for (const auto& rect : rectangles) {
      if (rect[0] < left_most) left_most = rect[0];
      if (rect[1] < down_most) down_most = rect[1];
      if (right_most < rect[2]) right_most = rect[2];
      if (up_most < rect[3]) up_most = rect[3];
    }
    auto pair_comparator = [](const std::pair<int, int> x_, const std::pair<int, int> y_) -> bool { return x_.first == y_.first ? x_.second < y_.second : x_.first < y_.second; };
    std::map<std::pair<int, int>, int, decltype(pair_comparator)> vertical_lines;
    std::map<std::pair<int, int>, int, decltype(pair_comparator)> horizontal_lines;
    for (const auto& rect : rectangles) {
    }
  }
};


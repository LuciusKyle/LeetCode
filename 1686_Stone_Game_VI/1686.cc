
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    vector<std::pair<int, int>> A_B_vals;
    A_B_vals.reserve(aliceValues.size());
    for (int i = 0; i < aliceValues.size(); ++i)
      A_B_vals.emplace_back(aliceValues[i], bobValues[i]);
    std::sort(A_B_vals.begin(), A_B_vals.end(), [](const std::pair<int, int>& _x, const std::pair<int, int>& _y) -> bool { return _x.first + _x.second > _y.first + _y.second; });
    int A_B_points[2] = {0};
    for (int i = 0; i < aliceValues.size(); ++i)
      if (i % 2 == 0)
        A_B_points[0] += A_B_vals[i].first;
      else
        A_B_points[1] += A_B_vals[i].second;
    if (A_B_points[0] < A_B_points[1])
      return -1;
    else if (A_B_points[1] < A_B_points[0])
      return 1;
    else
      return 0;
  }
};

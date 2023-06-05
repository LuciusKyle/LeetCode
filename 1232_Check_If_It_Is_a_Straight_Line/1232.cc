
#include <cmath>
#include <vector>

using std::vector;

class Solution {
 public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    if (coordinates[1][0] == coordinates[0][0]) {
      const int x_val = coordinates[0][0];
      for (const auto& coo : coordinates)
        if (coo[0] != x_val) return false;
      return true;
    }
    const double ratio = double(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
    for (int i = 2; i < coordinates.size(); ++i)
      if ((coordinates[i][0] == coordinates[0][0]) || 0.000001 < std::abs(ratio - double(coordinates[i][1] - coordinates[0][1]) / (coordinates[i][0] - coordinates[0][0]))) return false;
    return true;
  }
};

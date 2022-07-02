
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    std::sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& l_vec, const vector<int> r_vec) -> bool { return l_vec[1] > r_vec[1]; });
    int max_units = 0, remain_size = truckSize;
    for (const auto& vec : boxTypes) {
      if (remain_size < vec[0]) {
        return max_units + remain_size * vec[1];
      } else {
        max_units += vec[0] * vec[1];
        remain_size -= vec[0];
      }
    }

    return max_units;
  }
};

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int current_full_bags = 0;
    vector<int> diff_vec;
    for (int i = 0; i < capacity.size(); ++i)
      if (capacity[i] == rocks[i])
        ++current_full_bags;
      else
        diff_vec.push_back(capacity[i] - rocks[i]);

    std::sort(diff_vec.begin(), diff_vec.end());
    for (int i = 0; i < diff_vec.size(); ++i)
      if (0 <= additionalRocks - diff_vec[i]) {
        additionalRocks -= diff_vec[i];
        ++current_full_bags;
      } else
        break;

    return current_full_bags;
  }
};
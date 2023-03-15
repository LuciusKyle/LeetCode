
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int carFleet(const int target, const vector<int>& position, const vector<int>& speed) {
    vector<std::pair<int, int>> pos_speed_vec;
    pos_speed_vec.reserve(position.size() + 1);
    for (int i = 0; i < position.size(); ++i)
      pos_speed_vec.emplace_back(position[i], speed[i]);
    std::sort(pos_speed_vec.begin(), pos_speed_vec.end());
    pos_speed_vec.emplace_back(target, 1); // not needed.
    int fleet_count = 0;

    float slowest_time = 0;
    for (int i = pos_speed_vec.size() - 2, slowest_car = pos_speed_vec.size() - 1; 0 <= i; --i) {
      const int distance = target - pos_speed_vec[i].first;
      const float time = float(distance) / pos_speed_vec[i].second;
      if (slowest_time < time && 0.000001 < std::abs(slowest_time - time)) {
        slowest_car = i;
        slowest_time = time;
        ++fleet_count;
      }
    }
    return fleet_count;
  }
};
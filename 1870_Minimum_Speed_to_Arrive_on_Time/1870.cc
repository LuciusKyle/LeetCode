
#include <assert.h>
#include <math.h>

#include <algorithm>  // std::max_element
#include <numeric>
#include <vector>

using std::vector;

class Solution {
 public:
  int minSpeedOnTime(const vector<int>& dist, const double hour) {
    const int len = dist.size();
    if (hour < len - 1) return -1;
    int max_speed = *(std::max_element(dist.cbegin(), dist.cend())), min_speed = 1;

    // validate max_speed
    if (double(dist.back()) / max_speed > (hour - (len - 1))) {
      const double last_station_time_left = hour - (len - 1);
      return static_cast<int>(ceil(dist.back() / last_station_time_left));
    }

    // binary search for answer
    while (1 < max_speed - min_speed) {
      int time_before_final_station = 0;
      const int mid_speed = min_speed + (max_speed - min_speed) / 2;
      for (int i = 0; i < len - 1; ++i) {
        time_before_final_station += (dist[i] / mid_speed + bool(dist[i] % mid_speed));
      }
      const double last_station_time = double(dist.back()) / mid_speed;
      if (time_before_final_station + last_station_time < hour) {
        max_speed = mid_speed;
      } else {
        min_speed = mid_speed;
      }
    }

    if (max_speed == min_speed) return max_speed;

    // validate min_speed
    int time_before_final_station = 0;
    for (int i = 0; i < len - 1; ++i)
      time_before_final_station += (dist[i] / min_speed + bool(dist[i] % min_speed));
    if (time_before_final_station + double(dist.back()) / min_speed < hour + 0.000001)
      return min_speed;

    return max_speed;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  assert(10000000 == sln.minSpeedOnTime({1, 1, 100000}, 2.01));
  sln.minSpeedOnTime({1, 3, 2}, 6);
  sln.minSpeedOnTime({1, 3, 2}, 2.7);
  return 0;
}


#include <assert.h>
#include <math.h>
#include <string.h>

#include <algorithm>  // std::max_element
#include <iostream>
#include <numeric>
#include <vector>

using std::vector;

// offical solution.
class Solution_correct {
 public:
  double timeRequired(vector<int>& dist, int speed) {
    double time = 0.0;
    for (int i = 0; i < dist.size(); i++) {
      double t = (double)dist[i] / (double)speed;
      // Round off to the next integer, if not the last ride.
      time += (i == dist.size() - 1 ? t : ceil(t));
    }
    return time;
  }

  int minSpeedOnTime(vector<int>& dist, double hour) {
    int left = 1;
    int right = 1e7;
    int minSpeed = -1;

    while (left <= right) {
      int mid = (left + right) / 2;

      // Move to the left half.
      if (timeRequired(dist, mid) <= hour) {
        minSpeed = mid;
        right = mid - 1;
      } else {
        // Move to the right half.
        left = mid + 1;
      }
    }
    return minSpeed;
  }
};

class Solution {
 public:
  int minSpeedOnTime(const vector<int>& dist, const double hour) {
    const int len = dist.size();
    if (hour - 0.00000000001 < len - 1) return -1;
    // int max_speed = *(std::max_element(dist.cbegin(), dist.cend())), min_speed = 1;
    int max_speed = 1e9, min_speed = 1;

    //    // validate max_speed
    //    if (double(dist.back()) / max_speed > (hour - (len - 1))) {
    //      const double last_station_time_left = hour - (len - 1);
    //      return static_cast<int>(ceil(dist.back() / last_station_time_left));
    //    }

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
    if (time_before_final_station + double(dist.back()) / min_speed < hour + 0.0000000001)
      return min_speed;

    return max_speed;
  }
};

constexpr size_t kBufferSize = 1024 * 1024 * 1024;

int main(int argc, char* argv[]) {
  Solution sln;
  vector<int> test_vec;
  test_vec.reserve(100002);

  FILE* fp = fopen("testcase", "rb");
  char* buffer = new char[kBufferSize];
  memset(buffer, 0, kBufferSize);

  int file_size = fread(buffer, 1, kBufferSize, fp);
  fclose(fp);
  int line_break = 0;
  for (int i = 0; i < file_size; ++i) {
    if (buffer[i] == '\n') {
      line_break = i;
      break;
    }
    if (buffer[i] < '0' || '9' < buffer[i]) continue;
    int num = atoi(buffer + i);
    test_vec.push_back(num);
    while (num > 1) {
      num /= 10;
      ++i;
    }
  }
  const double test_hour = atof(buffer + line_break + 1);
  delete[] buffer;

  Solution_correct sln_corrent;
  assert(sln_corrent.minSpeedOnTime(test_vec, test_hour) == sln.minSpeedOnTime(test_vec, test_hour));
  assert(-1 == sln.minSpeedOnTime({1, 1}, 1));
  assert(10000000 == sln.minSpeedOnTime({1, 1, 100000}, 2.01));
  sln.minSpeedOnTime({1, 3, 2}, 6);
  sln.minSpeedOnTime({1, 3, 2}, 2.7);
  return 0;
}

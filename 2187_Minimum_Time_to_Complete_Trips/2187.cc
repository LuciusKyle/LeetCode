
#include <limits.h>

#include <vector>

using std::vector;

class Solution {
 public:
  long long minimumTime(const vector<int>& time, const int totalTrips) {
    long long lower_answer = 0, upper_answer = LONG_MAX;
    while (1 < upper_answer - lower_answer) {
      const long long mid_val = lower_answer + (upper_answer - lower_answer) / 2;
      long long trips_count = 0;
      for (const int t : time) {
        trips_count += mid_val / t;
        if (totalTrips < trips_count) break;
      }
      if (trips_count < totalTrips)
        lower_answer = mid_val;
      else
        upper_answer = mid_val;
    }
    return upper_answer;
  }
};

int main(int argc, char* argv[]) {
  vector<int> test_vec{2};
  Solution sln;
  sln.minimumTime(test_vec, 1);
  return 0;
}

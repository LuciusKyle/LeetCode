
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <limits.h>

using std::vector;
using std::string;

// 60% beat.
// a better solution is using counting sort. there are 24 * 60 possible minutes in a day.
class Solution {
 public:
  int findMinDifference(const vector<string>& timePoints) {
    vector<int> minutePoints;
    minutePoints.reserve(timePoints.size() + 1);
    for (const string &timePoint : timePoints)
      minutePoints.push_back(atoi(timePoint.c_str()) * 60 + atoi(timePoint.c_str() + 3));
    std::sort(minutePoints.begin(), minutePoints.end());
    minutePoints.push_back(minutePoints[0] + 24 * 60);
    int min_diff = INT_MAX;
    for (size_t i = 1; i < minutePoints.size(); ++i) {
      if (minutePoints[i] - minutePoints[i - 1] < min_diff)
        min_diff = minutePoints[i] - minutePoints[i - 1];
    }
    return min_diff;
  }

 private:
  int timeToMinute(const string& timePoint) {
    return atoi(timePoint.c_str()) * 60 + atoi(timePoint.c_str() + 3);
  }
};

int main(void) {
  char str[6] = { '\0' };
  strcpy(str, "12:13");
  int a = atoi(str);

  Solution sln;
  int ret = sln.findMinDifference({"23:59", "00:00"});

  return 0;
}

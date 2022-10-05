
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int minCost(string colors, vector<int>& neededTime) {
    const int length = neededTime.size();
    int result = 0;
    char pre_color = 'A';
    int time_sum = 0, curr_max = 0, consecutive_colors = 0;
    for (int i = 0; i < length; ++i)
      if (colors[i] == pre_color) {
        ++consecutive_colors;
        time_sum += neededTime[i];
        if (curr_max < neededTime[i]) curr_max = neededTime[i];
      } else {
        if (0 < consecutive_colors)
          result += (time_sum - curr_max);
        consecutive_colors = 0;
        curr_max = neededTime[i];
        time_sum = neededTime[i];
        pre_color = colors[i];
      }

    if (0 < consecutive_colors)
      result += (time_sum - curr_max);
    return result;
  }
};
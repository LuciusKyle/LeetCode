
#include <limits.h>

#include <vector>

using std::vector;

class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int max_answer = -1, min_answer = 1;
    for (const int num : piles) max_answer = std::max(max_answer, num);
    do {
      int time_sum = 0;
      const int mid_val = (min_answer + max_answer) / 2;
      for (const int num : piles) time_sum += (num / mid_val) + ((num % mid_val) == 0 ? 0 : 1);
      if (h < time_sum)
        min_answer = mid_val;
      else
        max_answer = mid_val;
    } while (min_answer + 1 < max_answer);
    if (min_answer == max_answer) return min_answer;
    int time_sum = 0;
    for (const int num : piles) time_sum += (num / min_answer) + ((num % min_answer) == 0 ? 0 : 1);
    if (h < time_sum) return max_answer;
    return min_answer;
  }
};

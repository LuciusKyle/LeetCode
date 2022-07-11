
#include <vector>

using std::vector;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int pre = 0, cur = 0, next = cost[0];
    for (int i = 1; i < cost.size(); ++i) {
      pre = cur;
      cur = next;
      next = cost[i] + std::min(pre, cur);
    }
    return std::min(cur, next);
  }
};
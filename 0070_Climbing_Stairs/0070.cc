
#include <limits.h>
#include <vector>

using std::vector;

class Solution {
 public:
  int climbStairs(int n) {
    vector<int> ways_count(n + 1, INT_MAX);
    return sub_climbStairs(ways_count, n);
  }

 private:
  int sub_climbStairs(vector<int>& ways_ount, const int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (ways_ount[n] != INT_MAX) return ways_ount[n];
    int rtn =
        sub_climbStairs(ways_ount, n - 1) + sub_climbStairs(ways_ount, n - 2);
    ways_ount[n] = rtn;
    return rtn;
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.climbStairs(10);
  return 0;
}

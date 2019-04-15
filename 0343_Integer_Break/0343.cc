
#include <limits.h>
#include <vector>

using std::vector;

class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp;
    dp.push_back(0);  // 0
    dp.push_back(1);  // 1
    // dp.push_back(1); // 2
    // dp.push_back(2); // 3

    for (int i = 2; i <= n; ++i) {
      int max = INT_MIN;
      for (int ii = 1; ii <= i / 2; ++ii) {
        const int product_val = ((i - ii) < dp[i - ii] ? dp[i - ii] : i - ii) *
                                (ii < dp[ii] ? dp[ii] : ii);
        if (max < product_val) max = product_val;
      }
      dp.push_back(max);
    }
    return dp[n];
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.integerBreak(10);
  return 0;
}
